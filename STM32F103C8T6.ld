MEMORY
{
    FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 64K
    RAM (rwx) : ORIGIN = 0x20000000, LENGTH = 20K
}

SECTIONS
{
    .text :
    {
        *(.isr_vector)
        *(.text)
        *(.rodata) 
        *(.rodata.*)
        *(.glue_7)
        *(.glue_7t)
        *(.gcc_except_table)
        *(.gnu.linkonce.t.*)
    } > FLASH
    
    .data : AT (ADDR(.text) + SIZEOF(.text))
    {
        *(.data)
        *(.data.*)
    } > RAM
    
    .bss : 
    {
        *(.bss)
        *(.bss.*)
        *(COMMON)
    } > RAM
}
