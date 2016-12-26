.global setjmp
setjmp:                                      /* R0 points to jmp_buf env */
   stm      r0!,{r0-r12,sp,lr}               /* store registers */
   mrs      r1,spsr                          /* store special registers spsr,cpsr */
   mrs      r2,cpsr
   stm      r0!,{r1,r2}
   mov      r0,#0                            /* return 0 (FALSE) */
   bx       lr                               /* return */

.global longjmp
longjmp:                                     /* R0 points to jmp_buf env */
                                             /* R1 points to value that is going to be returned (int) */
                                             /* R0 is used to return value */
   ldm      r0!,{r2-r12,sp,lr}               /* restore registers starting from r2 */
   push     {r1,r2}                          /* store value */
   ldm      r0!,{r1,r2}                      /* restore special registers spsr,cpsr */
   msr      spsr,r1
   msr      cpsr,r2
   ldr      r1,[r0,#4]                       /* restore r1 */
   pop      {r0,r2}                          /* use value as returned value and restore r2 */
   bx       lr                               /* return */
