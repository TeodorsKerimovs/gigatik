/*
 * sysClk.c
 *
 *  Created on: Jan 10, 2024
 *      Author: teodors.kerimovs
 */
#include "sysClk.h"

/***************************************************************************//**

  \details  This function enables the HSI clock as a system clock and generate
            the 8MHz. The Internal HSI Clock is 8MHz. So, we are not using PLL
            and not dividing, Multiplying. So, we will get the 8MHz as it is.

  \return   void

  \retval   none

*******************************************************************************/

void SetSystemClockTo8Mhz(void)
{
  /* Enabling the HSI clock - If not enabled and ready */
  if( (RCC->CR & RCC_CR_HSIRDY) == 0)
  {
    RCC->CR |= RCC_CR_HSION;  /* HSION=1 */

    /* Waiting until HSI clock is ready */
    while( (RCC->CR & RCC_CR_HSIRDY) == 0);
  }

  /* Select AHB prescaler to 1 */
  RCC->CFGR |= RCC_CFGR_HPRE_DIV1;

  /* APB1 prescaler to 1 */
  RCC->CFGR |= RCC_CFGR_PPRE1_DIV1;

  /* APB2 prescaler to 1 */
  RCC->CFGR |= RCC_CFGR_PPRE2_DIV1;

  /* Select the HSI as system clock source */
  RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_SW));
  RCC->CFGR |= RCC_CFGR_SW_HSI;

  FLASH->ACR  |= FLASH_ACR_LATENCY_2;

  /* Disabling HSE Clock */
  RCC->CR &= ~RCC_CR_HSEON;
}
