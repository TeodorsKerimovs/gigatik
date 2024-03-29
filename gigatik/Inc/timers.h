/*
 * timers.h
 *
 *  Created on: Jan 10, 2024
 *      Author: teodors.kerimovs
 */

#ifndef TIMERS_H_
#define TIMERS_H_

#include <stm32f1xx.h>
#include <stdbool.h>



void ConfigureTimer3(void);
void EnableTimer3(uint32_t ms);
void DisableTimer3(void);

void ConfigureTimer4(void);
void EnableTimer4(uint32_t ms);
void DisableTimer4(void);

#endif /* TIMERS_H_ */
