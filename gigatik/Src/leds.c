/*
 * leds.c
 *
 *  Created on: Jan 10, 2024
 *      Author: teodors.kerimovs
 */

#include "leds.h"

static uint32_t led0_toggle_register;
static uint32_t led1_toggle_register;

static bool zero_led_on;
static bool one_led_on;

void ConfigureLEDS(void){
	zero_led_on = 0;
	one_led_on = 0;
	// For LED 0
	if(LED_0_GPIOB_PIN == 0){
		led0_toggle_register = GPIO_ODR_ODR0;
	}
	else if(LED_0_GPIOB_PIN == 1){
		led0_toggle_register = GPIO_ODR_ODR1;
	}
	else if(LED_0_GPIOB_PIN == 2){
		led0_toggle_register = GPIO_ODR_ODR2;
	}
	else if(LED_0_GPIOB_PIN == 5){
		led0_toggle_register = GPIO_ODR_ODR5;
	}

	// For LED 1
	if(LED_1_GPIOB_PIN == 0){
		led1_toggle_register = GPIO_ODR_ODR0;
	}
	else if(LED_1_GPIOB_PIN == 1){
		led1_toggle_register = GPIO_ODR_ODR1;
	}
	else if(LED_1_GPIOB_PIN == 2){
		led1_toggle_register = GPIO_ODR_ODR2;
	}
	else if(LED_1_GPIOB_PIN == 5){
		led1_toggle_register = GPIO_ODR_ODR5;
	}
}

void turnOnLedZero(void){
	GPIOB -> ODR |= led0_toggle_register;
}

void turnOffLedZero(void){
	GPIOB -> ODR &= ~(led0_toggle_register);
}

void turnOnLedOne(void){
	GPIOB -> ODR |= led1_toggle_register;
}

void turnOffLedOne(void){
	GPIOB -> ODR &= ~(led1_toggle_register);
}

bool getZeroLedStatus(void){
	return zero_led_on;
}

void changeZeroLedStatus(bool changeTo){
	zero_led_on = changeTo;
}

bool getOneLedStatus(void){
	return one_led_on;
}

void changeOneLedStatus(bool changeTo){
	one_led_on = changeTo;
}
