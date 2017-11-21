/*
Wildfire Project
Author: Pablo Orduna Lagarma (end222)
File: kernel/kernel.asm
*/

.set ALIGN,    1<<0             /* align loaded modules on page boundaries */
.set MEMINFO,  1<<1             /* provide memory map */
.set FLAGS,    ALIGN | MEMINFO  /* this is the Multiboot 'flag' field */
.set MAGIC,    0x1BADB002       /* 'magic number' lets bootloader find the header */
.set CHECKSUM, -(MAGIC + FLAGS) /* checksum of above, to prove we are multiboot */

/* 
Declare a multiboot header that marks the program as a kernel. These are magic
values that are documented in the multiboot standard. The bootloader will
search for this signature in the first 8 KiB of the kernel file, aligned at a
32-bit boundary. The signature is in its own section so the header can be
forced to be within the first 8 KiB of the kernel file.
*/

.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

/*
Setting stack
*/

.section .bss
.align 16
stack_bottom:
.skip 16384 # 16 KiB
stack_top:

/*
Start function
*/

.section .text
.global _start
.type _start, @function
_start:
	mov $stack_top, %esp
	call kernel_main
	
	/*
	Disable interrupts
	*/
	cli
1:	hlt
	jmp 1b

.size _start, . - _start
