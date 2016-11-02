
#include "stm32l0xx_hal.h"

#include "usart.h"
#include "console.h"
#include "timerCallback.h"
#include "spi.h"

#include <stdio.h>
#include <string.h>

void SystemClock_Config(void);

int main(void)
{
    HAL_Init();

    SystemClock_Config();

    RCC->IOPENR = 0xFFFFFFFF;
    RCC->AHBENR = 0xFFFFFFFF;
    RCC->APB2ENR = 0xFFFFFFFF;
    RCC->APB1ENR = 0xFFFFFFFF;

    initDebugUsart();
    initSPI();

    debugUsartPrint("Hello\n");

    while (1)
    {
        consoleProcessBytes();
    }

}

/** System Clock Configuration
*/
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;

  __PWR_CLK_ENABLE();

  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = 0x0;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  HAL_RCC_OscConfig(&RCC_OscInitStruct);

  RCC_OscInitTypeDef osc;
  osc.OscillatorType = RCC_OSCILLATORTYPE_LSI;
  osc.LSIState = RCC_LSI_ON;
  HAL_RCC_OscConfig(&osc);

  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_SYSCLK;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_MSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0);


  RCC_PeriphCLKInitTypeDef clkSel;
  clkSel.PeriphClockSelection = RCC_PERIPHCLK_RTC;
  clkSel.RTCClockSelection = RCC_RTCCLKSOURCE_LSI;
  HAL_RCCEx_PeriphCLKConfig(&clkSel);

  RCC->CSR |= RCC_CSR_RTCEN;

  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

#ifdef USE_FULL_ASSERT

/**
   * @brief Reports the name of the source file and the source line number
   * where the assert_param error has occurred.
   * @param file: pointer to the source file name
   * @param line: assert_param error line source number
   * @retval None
   */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */

}

#endif

//Necessary to link libc
void _init()
{
}

/**
  * @}
  */ 

/**
  * @}
*/ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
