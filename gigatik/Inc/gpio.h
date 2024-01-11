/*
 * gpio.h
 *
 *  Created on: Jan 10, 2024
 *      Author: teodors.kerimovs
 */

#ifndef GPIO_H_
#define GPIO_H_

#include <stm32f1xx.h>

#ifndef LED_0_GPIOB_PIN
	#define LED_0_GPIOB_PIN 0
#endif

#ifndef LED_1_GPIOB_PIN
	#define LED_1_GPIOB_PIN 1
#endif

void ConfigureGPIO(void);

#endif /* GPIO_H_ */
