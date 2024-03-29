/*
 * uart.c
 *
 *  Created on: Jan 10, 2024
 *      Author: teodors.kerimovs
 */

#include "uart.h"

#ifndef UART_BAUD_RATE
	#define UART_BAUD_RATE 9600
#endif


static ring_buffer_t rb = {0U}; // initialize all memebers to zero
static uint8_t data_buffer[RING_BUFFER_SIZE] = {0U};

void ConfigureUART(void)
{
	ring_buffer_setup(&rb, data_buffer, RING_BUFFER_SIZE);

	// Set the baud rate to 9600.
	uint32_t SystemCoreClock = 8000000;
	uint16_t uartdiv = SystemCoreClock / UART_BAUD_RATE;

	USART2->BRR = ( ( ( uartdiv / 16 ) << USART_BRR_DIV_Mantissa_Pos ) |
	                ( ( uartdiv % 16 ) << USART_BRR_DIV_Fraction_Pos ) );

	// Configure pins A2, A3 for USART2.
	GPIOA->CRL    &= ( GPIO_CRL_MODE2 |
					 GPIO_CRL_CNF2 |
					 GPIO_CRL_MODE3 |
					 GPIO_CRL_CNF3 );

	GPIOA->CRL    |= ( ( 0x1 << GPIO_CRL_MODE2_Pos ) |
					 ( 0x2 << GPIO_CRL_CNF2_Pos ) |
					 ( 0x0 << GPIO_CRL_MODE3_Pos ) |
					 ( 0x1 << GPIO_CRL_CNF3_Pos ) );


	NVIC_SetPriorityGrouping( 0 );
	uint32_t uart_pri_encoding = NVIC_EncodePriority( 0, 2, 0 );
 	NVIC_SetPriority( USART2_IRQn, uart_pri_encoding );
	NVIC_EnableIRQ( USART2_IRQn );
}

void EnableUART(void){
	// Enable the USART peripheral with interrupt
	USART2->CR1 |= ( USART_CR1_RE |
					 USART_CR1_TE |
					 USART_CR1_UE |
					 USART_CR1_RXNEIE );
}

uint32_t uart_read(uint8_t* data, const uint32_t length){
	if (length == 0) {
		return 0;
	}

	for (uint32_t bytes_read = 0; bytes_read < length; bytes_read++){
		if(!ring_buffer_read(&rb, &data[bytes_read])){
			return bytes_read;
		}
	}

	return length;
}

uint8_t uart_read_byte(void){
	uint8_t byte = 0;
	(void)uart_read(&byte, 1); //explicitly ignore
	return byte;
}


void uart_send_byte(uint8_t data){
    while (!(USART2->SR & USART_SR_TXE)) {}
	USART2->DR = data;
}

void uart_send_string(const char *str) {
    size_t length = strlen(str);

    for (size_t i = 0; i < length; ++i) {
    	uart_send_byte((uint8_t)str[i]);
    }
}

bool uart_data_available(void) {
	return !ring_buffer_empty(&rb);
}

// USART2 interrupt handler
void USART2_IRQHandler(void) {
    // 'Receive register not empty' interrupt.
    if ( USART2->SR & USART_SR_RXNE ) {
    	if(ring_buffer_write(&rb, (uint8_t)USART2->DR)){
    		//handle failure, when running out of buffer size?
    		// Exercise says, that it won't be longer than 300 characters and current size is 512, so it should not happen for this
    	}
    }
}
