
#include "stm32l0xx_hal.h"

#include <stdint.h>
#include "timerCallback.h"

#define CALLBACK_TIMER  TIM6
#define CALLBACK_FREQUENCY 1000
#define TIMER_FREQUENCY 1000000
#define TIMER_MAX_VALUE    0xFFFF
#define MAX_NUM_CALLBACK_TIMERS 4
#define CALLBACK_TIMER_IRQ TIM6_IRQn
#define CALLBACK_TIMER_ISR TIM6_IRQHandler

typedef struct CallbackTimer_t {
    uint32_t currentValue;
    uint32_t resetValue;
    timerCallback callback;
    void* parameters;
} CallbackTimer;

CallbackTimer timerList[MAX_NUM_CALLBACK_TIMERS];

void initCallbackTimer()
{
    CALLBACK_TIMER->DIER = TIM_DIER_UIE;

    CALLBACK_TIMER->PSC = HAL_RCC_GetPCLK2Freq() / TIMER_FREQUENCY;
    CALLBACK_TIMER->ARR = (TIMER_FREQUENCY / CALLBACK_FREQUENCY); 

    HAL_NVIC_SetPriority(CALLBACK_TIMER_IRQ, 2, 0);  //Lowest Pre-emption Priority
    HAL_NVIC_EnableIRQ(CALLBACK_TIMER_IRQ);

    CALLBACK_TIMER->CR1 = TIM_CR1_CEN | TIM_CR1_ARPE;

    uint32_t ndx;
    for (ndx = 0; ndx < MAX_NUM_CALLBACK_TIMERS; ndx++)
    {
        timerList[ndx].resetValue = 0;
    }

}

int32_t addCallbackTimer(uint32_t count, timerCallback callback, void* parameters)
{
    uint32_t ndx;

    if (count == 0 || callback == NULL)
    {
        return -1;
    }

    for (ndx = 0; ndx < MAX_NUM_CALLBACK_TIMERS; ndx++)
    {
        if (timerList[ndx].resetValue == 0)
        {
            break;
        }
    }

    if (ndx == MAX_NUM_CALLBACK_TIMERS)
    {
        return -1;
    }

    timerList[ndx].resetValue = count;
    timerList[ndx].callback = callback;
    timerList[ndx].parameters = parameters;

    __disable_irq();

    timerList[ndx].currentValue = count;

    __enable_irq();

    return 0;
}

void TIM6_IRQHandler()
{
    uint32_t ndx;
    for (ndx = 0; ndx < MAX_NUM_CALLBACK_TIMERS; ndx++)
    {
        if (timerList[ndx].resetValue != 0)
        {
            timerList[ndx].currentValue--;
            if (timerList[ndx].currentValue == 0)
            {
                if (timerList[ndx].callback(timerList[ndx].parameters) == DISABLE_TIMER)
                {
                    timerList[ndx].resetValue = 0;
                }

                timerList[ndx].currentValue = timerList[ndx].resetValue;
            }
        }
    }

    CALLBACK_TIMER->SR &= ~(TIM_SR_UIF);
}