# 
# Wildfire Project
# Author: Pablo Orduna Lagarma (end222)
# File: makefile
#

CC = gcc
LD = ld

main: kernel/kernel.asm kernel/kernel.c scripts/link.ld
	as --32 kernel/kernel.asm -o out/boot.o
	gcc -m32 -c kernel/kernel.c -o out/kernel.o
	gcc -m32 -T scripts/link.ld -o out/kernel.bin -ffreestanding -O2 -nostdlib out/boot.o out/kernel.o -lgcc

clean: 
	rm out/*
