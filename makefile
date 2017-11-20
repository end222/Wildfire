# 
# Wildfire Project
# Author: Pablo Orduna Lagarma (end222)
# File: makefile
#

CC = gcc
LD = ld

main: kernel/kernel.asm kernel/kernel.c scripts/link.ld
	nasm -f elf32 kernel/kernel.asm -o out/kasm.o
	gcc -m32 -c kernel/kernel.c -o out/kc.o
	ld -m elf_i386 -T scripts/link.ld -o out/kernel out/kasm.o out/kc.o

clean: 
	rm out/*
