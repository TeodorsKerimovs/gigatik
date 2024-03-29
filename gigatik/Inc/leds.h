/*
 * leds.h
 *
 *  Created on: Jan 10, 2024
 *      Author: teodors.kerimovs
 */

#ifndef LEDS_H_
#define LEDS_H_

#include <stm32f1xx.h>
#include <stdbool.h>

void ConfigureLEDS(void);

void turnOnLedZero(void);
void turnOffLedZero(void);
void turnOnLedOne(void);
void turnOffLedOne(void);

bool getZeroLedStatus(void);
void changeZeroLedStatus(bool changeTo);

bool getOneLedStatus(void);
void changeOneLedStatus(bool changeTo);

#endif /* LEDS_H_ */
