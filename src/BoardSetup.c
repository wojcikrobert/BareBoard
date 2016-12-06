/*
 * BoardSetup.c
 *
 *  Created on: Dec 2, 2016
 *      Author: 502546347
 */

#include "BCM2837.h"

/* define GPIO function selection registers */
volatile GPFSEL_t* pGPIOSEL0 = GPFSEL0;
volatile GPFSEL_t* pGPIOSEL1 = GPFSEL1;
volatile GPFSEL_t* pGPIOSEL2 = GPFSEL2;
volatile GPFSEL_t* pGPIOSEL3 = GPFSEL3;
volatile GPFSEL_t* pGPIOSEL4 = GPFSEL4;
volatile GPFSEL_t* pGPIOSEL5 = GPFSEL5;

/* define GPIO set/clear registers */
volatile GPIOR0_t* pGPSET0 = GPSET0;
volatile GPIOR1_t* pGPSET1 = GPSET1;
volatile GPIOR0_t* pGPCLR0 = GPCLR0;
volatile GPIOR1_t* pGPCLR1 = GPCLR1;

/* TODO: zadeklarowac pozostale wskazniki */

int SetupGPIOs(void);

int InitBoard(void){
	int result = 1;
	/* GPIOs */
	result &= SetupGPIOs();

	return result;
}

int SetupGPIOs(void){
	int result = 1;

	/* setup GPIO functions
	   Possible options

	   000 = GPIO Pin 9 is an input
  	   001 = GPIO Pin 9 is an output
	   100 = GPIO Pin 9 takes alternate function 0
	   101 = GPIO Pin 9 takes alternate function 1
	   110 = GPIO Pin 9 takes alternate function 2
	   111 = GPIO Pin 9 takes alternate function 3
	   011 = GPIO Pin 9 takes alternate function 4
	   010 = GPIO Pin 9 takes alternate function 5
	 */

	/*   GPIO Bank 0
	   	   TO DO:
	 */

	/* GPIO Bank 1
	   	   PIN6 is an output
	 */
	(*pGPIOSEL1).FSELx6 = 0b001;
	/* GPIO Bank 2
	   	   TO DO:
	 */

	/* GPIO Bank 3
	   	   TO DO:
	 */

	/* GPIO Bank 4
	   	   TO DO:
	 */

	/* GPIO Bank 5
	   	   TO DO:
	 */

	/* GPIO Bank 6
	   	   TO DO:
	 */

	return result;
}

