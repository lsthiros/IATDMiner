
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#include "usart.h"
#include "spi.h"

#define CONSOLE_MAX_CMD_LEN     255
#define CONSOLE_MAX_NUM_ARGS    100

typedef void (*commandCallback)(uint32_t, char**);

typedef struct {
    char* cmdStr;
    uint32_t minArguments;
    commandCallback callback;
} ConsoleCommand;

typedef enum {CONSOLE_START = 0, CONSOLE_READING} ConsoleState;

void console_writeSpi(uint32_t, char**);

static ConsoleCommand commands[] = {
    {"writeSpi", 1, console_writeSpi},
    {NULL, 0, NULL}
};

static uint32_t createArgv(char* cmd, char** argv)
{
    uint32_t numArgs = 0;

    while (numArgs < CONSOLE_MAX_NUM_ARGS && *cmd != '\0')
    {
        if (*cmd == ',')
        {
            *cmd = '\0';
            argv[numArgs] = cmd + 1;
            numArgs++;
        }

        cmd++;
    }

    argv[numArgs] = NULL;

    return numArgs;
}

static void processCommand(char* cmd)
{
    int i = 0;
    char* argv[CONSOLE_MAX_NUM_ARGS];
    uint32_t argc;

    while (commands[i].cmdStr != NULL)
    {
        if ((strncmp(cmd, commands[i].cmdStr, strlen(commands[i].cmdStr)) == 0))
        {
            argc = createArgv(cmd, argv);

            debugUsartPrint("\r\n<");
            if (argc < commands[i].minArguments)
            {
                debugUsartPrint("ERROR: Need more Args");
            } else {
                commands[i].callback(argc, argv);
            }
            debugUsartPrint(">\r\n\r\n");

            break;
        }
        i++;
    }

    if (commands[i].cmdStr == NULL)
    {
        printf("\r\n<ERROR: Command Not Found>\r\n");
    }
}

void consoleProcessBytes()
{
    static ConsoleState state = CONSOLE_START;
    static char cmdBuffer[CONSOLE_MAX_CMD_LEN];
    static uint32_t cmdBufferIdx;

    uint8_t data;

    while (debugUsartRead(&data, 1))
    {
        debugUsartPut(data);
        switch(state) {
            case CONSOLE_START:
                if (data == '[')
                {
                    state = CONSOLE_READING;
                    memset(cmdBuffer, 0, CONSOLE_MAX_CMD_LEN);
                    cmdBufferIdx = 0;
                }
                break;
            case CONSOLE_READING:
                if (data == ']')
                {
                    processCommand(cmdBuffer);
                    state = CONSOLE_START;
                } else {
                    if (cmdBufferIdx < CONSOLE_MAX_CMD_LEN)
                    {
                        cmdBuffer[cmdBufferIdx] = data;
                        cmdBufferIdx++;
                    } else {
                        state = CONSOLE_START;
                    }
                }
                break;
            default:
                state = CONSOLE_START;
                break;
        }
    }
}

void console_writeSpi(uint32_t argc, char** argv)
{
    uint8_t sendBuf[256];
    uint8_t recvBuf[256];
    uint32_t idx = 0;

    while (idx < argc)
    {
        sendBuf[idx] = atoi(argv[idx]);
        idx++;
    }

    spiSendTransaction(sendBuf, recvBuf, argc);

    idx = 0;
    while (idx < argc)
    {
        debugUsartPutHex8(recvBuf[idx]);
        idx++;

        if (idx < argc)
        {
            debugUsartPut(',');
        }
    }
}




