
#ifndef __SPI_H__
#define __SPI_H__

void initSPI();
uint8_t spiSendByte(uint8_t send);
void spiSendTransaction(uint8_t* sendData, uint8_t* recvData, uint32_t len);

#endif
