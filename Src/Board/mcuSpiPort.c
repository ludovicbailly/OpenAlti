/*
 * mcuSpiPort.c
 *
 *  Created on: Nov 12, 2023
 *      Author: ludovic
 */


#include "stm32l1xx.h"

#include "mcuSpiPort.h"

void McuSpiPortRoutePin( SPI_TypeDef *ptrSpi )
{
  // I only uses SPI1 so far
  if( ptrSpi == SPI1 )
  {
    // SPI_1
    // Pins usage
    // PA5 <-> CLK
    // PA6 <-> MISO
    // PA7 <-> MOSI

    // Set alternate functions to pins
    GPIOA->AFR[0] &= ~GPIO_AFRL_AFSEL5_Msk;
    GPIOA->AFR[0] &= ~GPIO_AFRL_AFSEL6_Msk;
    GPIOA->AFR[0] &= ~GPIO_AFRL_AFSEL7_Msk;

    GPIOA->AFR[0] |= 5 << GPIO_AFRL_AFSEL5_Pos;
    GPIOA->AFR[0] |= 5 << GPIO_AFRL_AFSEL6_Pos;
    GPIOA->AFR[0] |= 5 << GPIO_AFRL_AFSEL7_Pos;

    // Then set pins as alternate
    GPIOA->MODER &= ~GPIO_MODER_MODER5_Msk;
    GPIOA->MODER |= GPIO_MODER_MODER5_1;

    GPIOA->MODER &= ~GPIO_MODER_MODER6_Msk;
    GPIOA->MODER |= GPIO_MODER_MODER6_1;

    GPIOA->MODER &= ~GPIO_MODER_MODER7_Msk;
    GPIOA->MODER |= GPIO_MODER_MODER7_1;
  }
}
