/*
 * timers.c
 *
 *  Created on: Jan 10, 2024
 *      Author: teodors.kerimovs
 */

#include "timers.h"
#include "leds.h"
#include "uart.h"

void ConfigureTimer3(void)
{
	/* fCK_PSC / (PSC[15:0] + 1)
	 (8 MHz / (7999+1)) = 1 KHz timer clock speed */
	TIM3->PSC = 7999;
	/* (1 KHz / 1000) = 1Hz = 1s */
	/* So, this will generate the 1s delay */
	TIM3->ARR = 999;
	/* Enable the Interrupt */
	TIM3->DIER |= TIM_DIER_UIE;
	/* Clear the Interrupt Status */
	TIM3->SR &= ~TIM_SR_UIF;
	/* Enable NVIC Interrupt for Timer 3 */


	NVIC_SetPriorityGrouping( 0 );
	uint32_t tim3_pri_encoding = NVIC_EncodePriority( 0, 1, 0 );
	NVIC_SetPriority( TIM3_IRQn, tim3_pri_encoding );
	NVIC_EnableIRQ(TIM3_IRQn);
}

void EnableTimer3(uint32_t ms)
{
	TIM3->ARR = ms-1;

    // Force an update event to immediately apply the new ARR value. But the interrupt is not triggered, because timer is stopped
    TIM3->EGR = TIM_EGR_UG;

	TIM3->CR1 |= TIM_CR1_CEN;
}

void DisableTimer3(void)
{
	TIM3->CR1 &= ~TIM_CR1_CEN;
}

void TIM3_IRQHandler(void)
{
  /* if UIF flag is set */
  if(TIM3->SR & TIM_SR_UIF)
  {
	DisableTimer3();
    if(getZeroLedStatus() == 1)
    {
    	// https://gist.github.com/iwalpola/6c36c9573fd322a268ce890a118571ca
		turnOffLedZero();
		uart_send_string("led-off: 0\r\n");
		changeZeroLedStatus(0);
    }
    /* Clear the Interrupt Status */
    TIM3->SR &= ~TIM_SR_UIF;
  }
}

void ConfigureTimer4(void)
{
	/* fCK_PSC / (PSC[15:0] + 1)
	 (8 MHz / (7999+1)) = 1 KHz timer clock speed */
	TIM4->PSC = 7999;
	/* (1 KHz / 1000) = 1Hz = 1s */
	/* So, this will generate the 1s delay */
	TIM4->ARR = 999;
	/* Enable the Interrupt */
	TIM4->DIER |= TIM_DIER_UIE;
	/* Clear the Interrupt Status */
	TIM4->SR &= ~TIM_SR_UIF;
	/* Enable NVIC Interrupt for Timer 3 */


	NVIC_SetPriorityGrouping( 0 );
	uint32_t tim4_pri_encoding = NVIC_EncodePriority( 0, 1, 0 );
	NVIC_SetPriority( TIM4_IRQn, tim4_pri_encoding );
	NVIC_EnableIRQ(TIM4_IRQn);
}

void EnableTimer4(uint32_t ms)
{
	TIM4->ARR = ms-1;

    // Force an update event to immediately apply the new ARR value. But the interrupt is not triggered, because timer is stopped
	TIM4->EGR = TIM_EGR_UG;

	TIM4->CR1 |= TIM_CR1_CEN;
}

void DisableTimer4(void)
{
	TIM4->CR1 &= ~TIM_CR1_CEN;
}


void TIM4_IRQHandler(void)
{
  /* if UIF flag is set */
  if(TIM4->SR & TIM_SR_UIF)
  {
	DisableTimer4();
    if(getOneLedStatus() == 1)
    {
		turnOffLedOne();
		uart_send_string("led-off: 1\r\n");
		changeOneLedStatus(0);
    }
    /* Clear the Interrupt Status */
    TIM4->SR &= ~TIM_SR_UIF;
  }
}

