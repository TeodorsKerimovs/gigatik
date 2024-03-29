/*
 * uart.h
 *
 *  Created on: Jan 10, 2024
 *      Author: teodors.kerimovs
 */

#ifndef UART_H_
#define UART_H_

#include <stm32f1xx.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>


#include "ringbuf.h"

#define RING_BUFFER_SIZE (512)

void ConfigureUART(void);
void EnableUART(void);


uint32_t uart_read(uint8_t* data, const uint32_t length);

uint8_t uart_read_byte(void);


void uart_send_byte(uint8_t data);
void uart_send_string(const char *str);

void USART2_IRQHandler(void) ;
bool uart_data_available(void);
#endif /* UART_H_ */
