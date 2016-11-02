
#include "stm32l0xx_hal.h"

#include "config.h"



void initSPI()
{
    GPIO_InitTypeDef gpio;
    gpio.Pin = GPIO_PIN_5 | GPIO_PIN_7;
    gpio.Mode = GPIO_MODE_AF_PP;
    gpio.Pull = GPIO_NOPULL;
    gpio.Speed = GPIO_SPEED_HIGH;
    gpio.Alternate = GPIO_AF0_SPI1;
    HAL_GPIO_Init(GPIOA, &gpio);

    gpio.Pin = GPIO_PIN_6;
    gpio.Mode = GPIO_MODE_AF_OD;
    gpio.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(GPIOA, &gpio);

    gpio.Pin = GPIO_PIN_4;
    gpio.Mode = GPIO_MODE_OUTPUT_OD;
    gpio.Pull = GPIO_PULLUP;
    gpio.Speed = GPIO_SPEED_HIGH;
    HAL_GPIO_Init(GPIOA, &gpio);

    SPI1->CR1 = SPI_CR1_SSM  | // Software slave management
                SPI_CR1_SSI  |
                SPI_CR1_BR_0 |
                SPI_CR1_BR_1 |
                SPI_CR1_BR_2 | // Divide Pclk by 256
                SPI_CR1_MSTR | // Master Mode
                SPI_CR1_CPHA;  // CPOL = 0; CPHA = 1

    SPI1->CR2 = 0;

    SPI1->CR1 |= SPI_CR1_SPE; // Enable the SPI
}

uint8_t spiSendByte(uint8_t send)
{
    while (!(SPI1->SR & SPI_SR_TXE))
    {}

    SPI1->DR = send;

    while (!(SPI1->SR & SPI_SR_RXNE))
    {}

    return SPI1->DR;
}

void spiSendTransaction(uint8_t* sendData, uint8_t* recvData, uint32_t len)
{
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);

    //SPI1->CR1 |= SPI_CR1_SSI; // Internal SSI

    while (len--)
    {
        *recvData = spiSendByte(*sendData);
        sendData++;
        recvData++;
    }

    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
}

