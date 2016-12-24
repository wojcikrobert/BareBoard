MEMORY
{
  flash (rx)	: ORIGIN = 0x08000000, LENGTH = 1024K
  sram (rwx)	: ORIGIN = 0x20010000, LENGTH = 256K
  stack (rwx)	: ORIGIN = 0x2004FFFF, LENGTH = 0
}
SECTIONS
{
    .nvic_vector : 
    {
        *(vectors)    /* Vector table */   
    } >flash
    
    .text : 
    {
        *(.text)      /* Program code */
        *(.text.*)
        *(.rodata)    /* Read only data */
        *(.rodata.*)     
    } >flash
    
    .data : 
    {
        *(.data)      /* Data memory */
        *(.data.*)    
    } >sram AT >flash
    
    .bss :
    {
    	__bss_start__ = .;
        *(.bss)       /* Zero-filled run time allocate data memory */
		__bss_end__ = .;
    } >sram
    
    .heap :
    {
        _HEAP = .;
    } >sram

    .stack :
    {
        _STACKTOP = .;
    } >stack
}