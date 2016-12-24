/*
 * BoardSetup.c
 *
 *  Created on: Dec 2, 2016
 *      Author: 502546347
 */

#include "STM32F746NG.h"
#include "DataTypes.h"
#include "BoardSetup.h"

   BOOL InitBoard(void);
   void SetOutput(OUTPUTS out, BOOL val);
   void ReadInput(INPUTS in, BOOL* const val);

	BOOL InitBoard(void){

	   BOOL InitResult = TRUE;
		/* Pin PD14 is output LED [LD1], push-pull output, low speed, pull-up */
	   MODIFY_REG(GPIOD->MODER,3 << GPIO_MODER_MODER14_SHIFT,1 << GPIO_MODER_MODER14_SHIFT);
	   MODIFY_REG(GPIOD->OTYPER,1 << GPIO_OTYPER_OT_14_SHIFT,1 << GPIO_OTYPER_OT_14_SHIFT);
	   MODIFY_REG(GPIOD->OSPEEDR,3 << GPIO_OSPEEDER_OSPEEDR14_SHIFT,0);
	   MODIFY_REG(GPIOD->PUPDR,3 << GPIO_PUPDR_PUPDR14_SHIFT,0);
	   /* Pin F3 is input pushbutton [B1], pull-down */
      MODIFY_REG(GPIOF->MODER,3 << GPIO_MODER_MODER3_SHIFT,1 << GPIO_MODER_MODER3_SHIFT);
      MODIFY_REG(GPIOF->PUPDR,3 << GPIO_PUPDR_PUPDR3_SHIFT,1 << GPIO_PUPDR_PUPDR3_SHIFT);

	   /* TODO: Freeze GPIO registers after configuration */

	   return InitResult;
	}

	void SetOutput(OUTPUTS out, BOOL val){
	   /* declare modifiers */
	   GPIO_TypeDef* PortSelection = NULL;
	   uint32_t Shift = 0;
	   switch(out){
	      case LD1:
	         /* set modifiers */
	         PortSelection = GPIOD;
	         Shift = GPIO_ODR_ODR_14_SHIFT;
	         break;
	   }

	   /* if selection was done update output register */
      if(PortSelection != NULL){
	      MODIFY_REG(PortSelection->ODR,1<<Shift,val<<Shift);
	   }
	}

	void ReadInput(INPUTS in, BOOL* const val){
      /* declare modifiers */
      GPIO_TypeDef* PortSelection = NULL;
      uint32_t Shift = 0;
      switch(in){
         case B1:
            /* set modifiers */
            PortSelection = GPIOF;
            Shift = GPIO_IDR_IDR_3_SHIFT;
            break;
      }
      /* if selection was done read register */
      if(PortSelection != NULL){
         *val = READ_BIT(PortSelection->IDR,Shift);
      }
   }
