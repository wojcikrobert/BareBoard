#include "setjmp.h"
#include "ContextManager.h"
#include "BoardSetup.h"
#include "DataTypes.h"

jmp_buf  env;

int main(void){

   if(TRUE == InitBoard()){

      SaveContext();
      if(setjmp(env)){
         SetOutput(LD1,TRUE);
      }
      else{
         longjmp(env,1);
      }
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
