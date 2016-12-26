/*
 * setjmp.h
 *
 *  Created on: Dec 25, 2016
 *      Author: 502546347
 */
#include "DataTypes.h"

#ifndef SRC_SETJMP_H_
#define SRC_SETJMP_H_

typedef struct{
   uint32_t R0;
   uint32_t R1;
   uint32_t R2;
   uint32_t R3;
   uint32_t R4;
   uint32_t R5;
   uint32_t R6;
   uint32_t R7;
   uint32_t R8;
   uint32_t R9;
   uint32_t R10;
   uint32_t R11;
   uint32_t R12;
   uint32_t SP;
   uint32_t LR;
   uint32_t CPSR;
   uint32_t SPSR;
}jmp_buf;

extern int setjmp(jmp_buf env);
extern void longjmp(jmp_buf env, int value);

#endif /* SRC_SETJMP_H_ */
