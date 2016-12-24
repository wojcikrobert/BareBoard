/*
 * data_types.h
 *
 *  Created on: Dec 2, 2016
 *      Author: 502546347
 */

#ifndef DATA_TYPES_H_
#define DATA_TYPES_H_

   #if !defined(NULL)
    #define NULL ((void*)0)
   #endif

	typedef signed char s8;
	typedef unsigned char uint8_t;

	typedef signed short sint16_t;
	typedef unsigned short uint16_t;

	typedef signed int sint32_t;
	typedef unsigned int uint32_t;

	typedef signed long long sint64_t;
	typedef unsigned long long uint64_t;

	typedef enum BOOL{
      FALSE = 0,
      TRUE = 1
	}BOOL;

#endif /* DATA_TYPES_H_ */
