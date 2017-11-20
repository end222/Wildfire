; Wildfire Project
; Author: Pablo Orduna Lagarma (end222)
; File: kernel/kernel.asm

bits 32 			; Nasm directive: 32 bits for now
section .text
        			;Multiboot spec needed for Grub support
        align 4
        dd 0x1BADB002           ;magic
        dd 0x00                 ;flags
        dd - (0x1BADB002 + 0x00);checksum. m+f+c should be zero

global start
extern kernel_main 			; Defined in kernel/kernel.c

start:
	cli 			; Block interruptions
	mov esp, stack_space	; Set stack pointer
	call kernel_main		; Calls the kmain function from kernel.c
	hlt			; Halt


section .bss
resb 8192			; 8KB for stack
stack_space:
