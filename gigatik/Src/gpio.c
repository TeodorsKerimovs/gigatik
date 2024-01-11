/*
 * gpio.c
 *
 *  Created on: Jan 10, 2024
 *      Author: teodors.kerimovs
 */

#include "gpio.h"




void ConfigureGPIO(void)
{
	// Enable peripheral clocks: PORTA
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;


	// For LED 0
	if(LED_0_GPIOB_PIN == 0){
		GPIOB->CRL &= ~GPIO_CRL_CNF0_Msk;
		GPIOB->CRL |= GPIO_CRL_MODE0_Msk;
	}
	else if(LED_0_GPIOB_PIN == 1){
		GPIOB->CRL &= ~GPIO_CRL_CNF1_Msk;
		GPIOB->CRL |= GPIO_CRL_MODE1_Msk;
	}
	else if(LED_0_GPIOB_PIN == 2){
		GPIOB->CRL &= ~GPIO_CRL_CNF2_Msk;
		GPIOB->CRL |= GPIO_CRL_MODE2_Msk;
	}
	else if(LED_0_GPIOB_PIN == 5){
		GPIOB->CRL &= ~GPIO_CRL_CNF5_Msk;
		GPIOB->CRL |= GPIO_CRL_MODE5_Msk;
	}

	// For LED 1
	if(LED_1_GPIOB_PIN == 0){
		GPIOB->CRL &= ~GPIO_CRL_CNF0_Msk;
		GPIOB->CRL |= GPIO_CRL_MODE0_Msk;
	}
	else if(LED_1_GPIOB_PIN == 1){
		GPIOB->CRL &= ~GPIO_CRL_CNF1_Msk;
		GPIOB->CRL |= GPIO_CRL_MODE1_Msk;
	}
	else if(LED_1_GPIOB_PIN == 2){
		GPIOB->CRL &= ~GPIO_CRL_CNF2_Msk;
		GPIOB->CRL |= GPIO_CRL_MODE2_Msk;
	}
	else if(LED_1_GPIOB_PIN == 5){
		GPIOB->CRL &= ~GPIO_CRL_CNF5_Msk;
		GPIOB->CRL |= GPIO_CRL_MODE5_Msk;
	}

}
