#include "ContextManager.h"
#include "BoardSetup.h"
#include "DataTypes.h"


int main(void){

   if(TRUE == InitBoard()){

      SaveContext();
      SetOutput(LD1,TRUE);
      while(1){
         /* TODO: Light LED when button is pressed. */
      }
   }
   else{

   }
}

void _exit(int status)
{
   /* it shall not get here */
   while (1);
}
