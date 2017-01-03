MEMORY
{
  options (r)			: ORIGIN = 0x1FFF0000, LENGTH = 32
  itcm_ram (rwx)		: ORIGIN = 0x00000000, LENGTH = 4K
  itcm_flash (rx)       : ORIGIN = 0x00200000, LENGTH = 32K
  flash (rx)            : ORIGIN = 0x08000000, LENGTH = 1024K
  boot_vector			: ORIGIN = 0x08001000, LENGTH = 0
  dtcm (rwx)            : ORIGIN = 0x20000000, LENGTH = 64K
  sram (rwx)            : ORIGIN = 0x20010000, LENGTH = 256K
  stack (rwx)           : ORIGIN = 0x2004FFFF, LENGTH = 0
}

SECTIONS
{
    
    .nvic_vector : ALIGN(4)
    {
        FILL(0xFF)
        KEEP(*(.isr_vector))     			/* Interrupt vectors */
        *(.after_vectors .after_vectors.*)	/* Boot code */
    } >flash
    
    .text : 
    {
    	*(.main)
        *(.text)      /* Program code */
        *(.text.*)
        *(.rodata)    /* Read only data */
        *(.rodata.*)     
		. = ALIGN(4);
    } >flash
    
    .data : 
    {
        *(.data)      /* Data memory */
        *(.data.*)    
		. = ALIGN(4);
    } >sram AT >flash
    
    .bss :
    {
    	__bss_start__ = .;
        *(.bss)       /* Zero-filled run time allocate data memory */
		. = ALIGN(4);
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