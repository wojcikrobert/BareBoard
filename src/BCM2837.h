/*
 * BCM2837.h
 *
 *  Created on: Dec 2, 2016
 *      Author: 502546347
 */
#include "DataTypes.h"

#ifndef BCM2837_H_
#define BCM2837_H_

/* GPIO */
	#define BCM2837_GPFSEL_BASE 	0x7E200000
	typedef struct{
		uint8_t	Reserved : 2;
		uint8_t FSELx9 : 3;
		uint8_t FSELx8 : 3;
		uint8_t FSELx7 : 3;
		uint8_t FSELx6 : 3;
		uint8_t FSELx5 : 3;
		uint8_t FSELx4 : 3;
		uint8_t FSELx3 : 3;
		uint8_t FSELx2 : 3;
		uint8_t FSELx1 : 3;
		uint8_t FSELx0 : 3;
	} GPFSEL_t;

	#define GPFSEL0			(BCM2837_GPFSEL_BASE + 0x0000)	/* GPIO Function Select 0 */
	#define GPFSEL1			(BCM2837_GPFSEL_BASE + 0x0004)	/* GPIO Function Select 1 */
	#define GPFSEL2			(BCM2837_GPFSEL_BASE + 0x0008)	/* GPIO Function Select 2 */
	#define GPFSEL3			(BCM2837_GPFSEL_BASE + 0x000C)	/* GPIO Function Select 3 */
	#define GPFSEL4			(BCM2837_GPFSEL_BASE + 0x0010)	/* GPIO Function Select 4 */
	#define GPFSEL5			(BCM2837_GPFSEL_BASE + 0x0014)	/* GPIO Function Select 5 */

	typedef struct{
		uint8_t GPIO0 : 1;
		uint8_t GPIO1 : 1;
		uint8_t GPIO2 : 1;
		uint8_t GPIO3 : 1;
		uint8_t GPIO4 : 1;
		uint8_t GPIO5 : 1;
		uint8_t GPIO6 : 1;
		uint8_t GPIO7 : 1;
		uint8_t GPIO8 : 1;
		uint8_t GPIO9 : 1;
		uint8_t GPIO10 : 1;
		uint8_t GPIO11 : 1;
		uint8_t GPIO12 : 1;
		uint8_t GPIO13 : 1;
		uint8_t GPIO14 : 1;
		uint8_t GPIO15 : 1;
		uint8_t GPIO16 : 1;
		uint8_t GPIO17 : 1;
		uint8_t GPIO18 : 1;
		uint8_t GPIO19 : 1;
		uint8_t GPIO20 : 1;
		uint8_t GPIO21 : 1;
		uint8_t GPIO22 : 1;
		uint8_t GPIO23 : 1;
		uint8_t GPIO24 : 1;
		uint8_t GPIO25 : 1;
		uint8_t GPIO26 : 1;
		uint8_t GPIO27 : 1;
		uint8_t GPIO28 : 1;
		uint8_t GPIO29 : 1;
		uint8_t GPIO30 : 1;
		uint8_t GPIO31 : 1;
	} GPIOR0_t;

	typedef struct{
		uint8_t GPIO32 : 1;
		uint8_t GPIO33 : 1;
		uint8_t GPIO34 : 1;
		uint8_t GPIO35 : 1;
		uint8_t GPIO36 : 1;
		uint8_t GPIO37 : 1;
		uint8_t GPIO38 : 1;
		uint8_t GPIO39 : 1;
		uint8_t GPIO40 : 1;
		uint8_t GPIO41 : 1;
		uint8_t GPIO42 : 1;
		uint8_t GPIO43 : 1;
		uint8_t GPIO44 : 1;
		uint8_t GPIO45 : 1;
		uint8_t GPIO46 : 1;
		uint8_t GPIO47 : 1;
		uint8_t GPIO48 : 1;
		uint8_t GPIO49 : 1;
		uint8_t GPIO50 : 1;
		uint8_t GPIO51 : 1;
		uint8_t GPIO52 : 1;
		uint8_t GPIO53 : 1;
		uint8_t Unused : 10;
	} GPIOR1_t;

	#define GPSET0			(BCM2837_GPFSEL_BASE + 0x001C)	/* GPIO Pin Output Set 0 */
	#define GPSET1			(BCM2837_GPFSEL_BASE + 0x0020)	/* GPIO Pin Output Set 1 */
	#define GPCLR0			(BCM2837_GPFSEL_BASE + 0x0028)	/* GPIO Pin Output Clear 0 */
	#define GPCLR1			(BCM2837_GPFSEL_BASE + 0x002C)	/* GPIO Pin Output Clear 1 */

	#define GPLEV0			(BCM2837_GPFSEL_BASE + 0x0034)	/* GPIO Pin Level 0 */
	#define GPLEV1			(BCM2837_GPFSEL_BASE + 0x0038)	/* GPIO Pin Level 1 */

	#define GPEDS0			(BCM2837_GPFSEL_BASE + 0x0040)	/* GPIO Pin Event Detect Status 0 */
	#define GPEDS1			(BCM2837_GPFSEL_BASE + 0x0044)	/* GPIO Pin Event Detect Status 1 */

	#define GPREN0			(BCM2837_GPFSEL_BASE + 0x004C)	/* GPIO Pin Rising Edge Detect Enable 0 */
	#define GPREN1			(BCM2837_GPFSEL_BASE + 0x0050)	/* GPIO Pin Rising Edge Detect Enable 1 */

	#define GPFEN0			(BCM2837_GPFSEL_BASE + 0x0058)	/* GPIO Pin Falling Edge Detect Enable 0 */
	#define GPFEN1			(BCM2837_GPFSEL_BASE + 0x005C)	/* GPIO Pin Falling Edge Detect Enable 1 */

	#define GPHEN0			(BCM2837_GPFSEL_BASE + 0x0064)	/* GPIO Pin High Detect Enable 0 */
	#define GPHEN1			(BCM2837_GPFSEL_BASE + 0x0068)	/* GPIO Pin High Detect Enable 1 */

	#define GPLEN0			(BCM2837_GPFSEL_BASE + 0x0070)	/* GPIO Pin Low Detect Enable 0 */
	#define GPLEN1			(BCM2837_GPFSEL_BASE + 0x0074)	/* GPIO Pin Low Detect Enable 1 */

	#define GPAREN0			(BCM2837_GPFSEL_BASE + 0x007C)	/* GPIO Pin Async. Rising Edge Detect 0 */
	#define GPAREN1			(BCM2837_GPFSEL_BASE + 0x0080)	/* GPIO Pin Async. Rising Edge Detect 1 */

	#define GPAFEN0			(BCM2837_GPFSEL_BASE + 0x0088)	/* GPIO Pin Async. Falling Edge Detect 0 */
	#define GPAFEN1			(BCM2837_GPFSEL_BASE + 0x008C)	/* GPIO Pin Async. Falling Edge Detect 1 */

	typedef struct{
		//TODO
	} GPPUD_t;

	#define GPPUD			(BCM2837_GPFSEL_BASE + 0x0094)	/* GPIO Pin Pull-up/down Enable */


	#define GPPUDCLK0		(BCM2837_GPFSEL_BASE + 0x0098)  /* GPIO Pin Pull-up/down Enable Clock 0 */
	#define GPPUDCLK1		(BCM2837_GPFSEL_BASE + 0x009C)	/* GPIO Pin Pull-up/down Enable Clock 1 */

#endif /* BCM2837_H_ */
