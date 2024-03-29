#include <stdint.h>
#include <stdbool.h>
#include <stm32f1xx.h>
#include <stdio.h>
#include <string.h>

#include "uart.h"
#include "timers.h"
#include "gpio.h"
#include "sysClk.h"
#include "rcc.h"
#include "leds.h"
#include "ringbuf.h"

#define MAX_STRING_LENGTH (512)
char str[MAX_STRING_LENGTH] = {0};
char str_message[MAX_STRING_LENGTH] = {0};
uint32_t stringWriteIdx = 0;

int main(void)
{

	/* Set System clock to 8 MHz using HSI */
	SetSystemClockTo8Mhz();
	ConfigureRCC();
	ConfigureTimer3();
	ConfigureTimer4();
	ConfigureUART();
	ConfigureGPIO();
	ConfigureLEDS();
	EnableUART();

	while(1)
	{
		while (uart_data_available()){
			uint8_t data = uart_read_byte();
			if (data == '\r') {
				// Terminate the current string
				str[stringWriteIdx] = '\0';
				// Process the current string (e.g., print it, store it, etc.)
				int ledNumber, value;
				char extraChar;

				// If there has been an extraChar then it leads to error
				if (sscanf(str, "set-led %d,%d%c", &ledNumber, &value, &extraChar) == 2)
			    {
			    	if (((ledNumber == 0) || (ledNumber == 1)) && (value >= 1) && (value < 5000)){
			    		if (ledNumber == 0){
			    			if(getZeroLedStatus() == 0){
					    		uart_send_string("OK\r\n");
			    				turnOnLedZero();
			    				EnableTimer3((uint32_t)value);
			    				changeZeroLedStatus(1);
			    			}
			    		}
			    		if (ledNumber == 1){
			    			if(getOneLedStatus() == 0){
					    		uart_send_string("OK\r\n");
			    				turnOnLedOne();
			    				EnableTimer4((uint32_t)value);
			    				changeOneLedStatus(1);
			    			}
			    		}
			    	}
			    }
			    else
			    {
			    	int len = 0;
					// Set message string to zeros
			    	memset(str_message, 0, sizeof(str_message));
				    if (sscanf(str, "echo %d,%511s\r", &len, str_message) == 2)
				    {
				    	if((len >= 0) && (len <=300)){
				    		uart_send_string("data: ");
					    	uart_send_string(str_message);
				    		uart_send_string("\n");
				    		uart_send_string("OK\r\n");
				    	}
				    }
				    else
				    {
				    	uart_send_string("ERROR\r\n");
				    }
			    }
				// Reset the index for the next string
				stringWriteIdx = 0;
				// Set incoming string buffer to zeros
				memset(str, 0, sizeof(str));
			}
			else if (stringWriteIdx < (MAX_STRING_LENGTH - 1))
			{
				// Append the byte to the string if there's room
				str[stringWriteIdx] = data;
				stringWriteIdx++;
			}
			else
			{
				// String buffer overflow is not handled, however it is long enough = 512. Exercise won't have longer than 300
			}
		}
	}
}

