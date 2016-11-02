#ifndef __USART_H__
#define __USART_H__

#include <stdint.h>

void initDebugUsart();
void debugUsartPut(uint8_t data);
void debugUsartWrite(char* data, uint16_t size);
void debugUsartPrint(char* data);
void debugUsartPutHex8(uint8_t hex);
char debugUsartGetBlocking();
uint32_t debugUsartRead(uint8_t* data, uint32_t len);
void debugEnableTunneling();
void debugDisableTunneling();

#endif
