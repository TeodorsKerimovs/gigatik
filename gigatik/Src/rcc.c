/*
 * rcc.c
 *
 *  Created on: Jan 10, 2024
 *      Author: teodors.kerimovs
 */

#include "rcc.h"

void ConfigureRCC(void)
{
	// Enable peripheral clocks: USART2
	RCC->APB1ENR  |=  ( RCC_APB1ENR_USART2EN );

	// Enable peripheral clocks: PORTA for UART
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;

	// Enable peripheral clocks: PORTB for LEDS
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;

	// Enable the APB clock FOR TIM3
	SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM3EN);

	// Enable the APB clock FOR TIM4
	SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM4EN);

}

