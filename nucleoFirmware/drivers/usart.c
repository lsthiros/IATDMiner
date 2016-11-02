

#include "stm32l0xx_hal.h"

#include "buffer8.h"
#include "config.h"

static uint8_t debugTxBuffer[64];
static uint8_t debugRxBuffer[5000];

static USART_HandleTypeDef debugUsart;
static buffer8_t debugTxFifo;
static buffer8_t debugRxFifo;
static int forwardingEnabled = 0;

void initDebugUsart()
{

    GPIO_InitTypeDef gpio;
    gpio.Pin = GPIO_PIN_2 | GPIO_PIN_3;
    gpio.Mode = GPIO_MODE_AF_PP;
    gpio.Pull = GPIO_NOPULL;
    gpio.Speed = GPIO_SPEED_HIGH;
    gpio.Alternate = GPIO_AF4_USART2;

    HAL_GPIO_Init(GPIOA, &gpio);

    debugUsart.Instance = USART2;

    USART2->CR1 = USART_CR1_RE | USART_CR1_TE;

    //115200 Baud
    // USART2->BRR = PCLK1_FREQ / 115200;
    USART2->BRR = 37;


    USART2->CR1 |= USART_CR1_UE;

    HAL_NVIC_SetPriority(USART2_IRQn, 1, 0);
    HAL_NVIC_EnableIRQ(USART2_IRQn);

    __HAL_USART_ENABLE_IT(&debugUsart, USART_IT_RXNE);

    buffer8_init(&debugTxFifo, debugTxBuffer, 64);
    buffer8_init(&debugRxFifo, debugRxBuffer, 64);
}

void debugUsartPut(uint8_t data)
{
    __disable_irq();
    if (__HAL_USART_GET_IT_SOURCE(&debugUsart, USART_IT_TXE))
    {
        buffer8_put(&debugTxFifo, data);
    } else {
        __HAL_USART_ENABLE_IT(&debugUsart, USART_IT_TXE);
        debugUsart.Instance->TDR = data;
    }
    __enable_irq();
}

void debugUsartWrite(char* data, uint16_t size)
{
    if (size > 0)
    {
        if (__HAL_USART_GET_IT_SOURCE(&debugUsart, USART_IT_TXE))
        {
            buffer8_write(&debugTxFifo, (uint8_t*)data, size);
        } else {
            buffer8_write(&debugTxFifo, (uint8_t*)data + 1, size -1);
            __HAL_USART_CLEAR_IT(&debugUsart, USART_FLAG_TXE);
            debugUsart.Instance->TDR = *data;
            __HAL_USART_ENABLE_IT(&debugUsart, USART_IT_TXE);
        }
    }
}

void debugUsartPrint(char* data)
{
    while(*data)
    {
        debugUsartPut(*data);
        data++;
    }
}

char debugUsartGetBlocking()
{
    while (buffer8_empty(&debugRxFifo))
    {}

    return buffer8_get(&debugRxFifo);
}

void debugUsartPutHex8(uint8_t hex)
{
    char* hexTable = "0123456789ABCDEF";

    debugUsartPut(hexTable[(hex >> 4)]);
    debugUsartPut(hexTable[hex & 0xF]);
}

uint32_t debugUsartRead(uint8_t* data, uint32_t len)
{
    uint32_t bytesRead = 0;

    while(!buffer8_empty(&debugRxFifo) && bytesRead < len)
    {
        *data++ = buffer8_get(&debugRxFifo);
        bytesRead++;
    }

    return bytesRead;
}

void debugEnableTunneling()
{
    forwardingEnabled = 1;
}

void debugDisableTunneling()
{
    forwardingEnabled = 0;
}

void USART2_IRQHandler(void)
{
    if (__HAL_USART_GET_FLAG(&debugUsart, USART_FLAG_TXE) != RESET)
    {
        if (buffer8_empty(&debugTxFifo))
        {
            __HAL_USART_DISABLE_IT(&debugUsart, USART_IT_TXE);
        } else {
            uint8_t data = buffer8_get(&debugTxFifo);
            debugUsart.Instance->TDR = data;
        }

        __HAL_USART_CLEAR_IT(&debugUsart, USART_FLAG_TXE);
    } else {
    }

    if (__HAL_USART_GET_FLAG(&debugUsart, USART_FLAG_RXNE) != RESET)
    {
        buffer8_put(&debugRxFifo, debugUsart.Instance->RDR);
        __HAL_USART_CLEAR_IT(&debugUsart, USART_FLAG_RXNE);
    }
}
