/*
 * BoardSetup.h
 *
 *  Created on: Dec 2, 2016
 *      Author: 502546347
 */

#include "DataTypes.h"

#ifndef BOARDSETUP_H_
#define BOARDSETUP_H_

   typedef enum OUTPUTS{
      LD1
   }OUTPUTS;


   typedef enum INPUTS{
      B1
   }INPUTS;

	extern BOOL InitBoard(void);
	extern void SetOutput(OUTPUTS out, BOOL val);
	extern void ReadInput(INPUTS in, BOOL* const val);

#endif /* BOARDSETUP_H_ */
