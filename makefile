# 
# Wildfire Project
# Author: Pablo Orduna Lagarma (end222)
# File: makefile
#

CC = gcc
AS = as

main: kernel/kernel.asm kernel/kernel.c scripts/link.ld screen_utils.o
	$(AS) --32 kernel/kernel.asm -o out/boot.o
	$(CC) -m32 -c kernel/kernel.c -o out/kernel.o
	$(CC) -m32 -T scripts/link.ld -o out/kernel.bin -ffreestanding -O2 -nostdlib out/boot.o out/kernel.o out/screen_utils.o -lgcc

screen_utils.o: utils/screen_utils.c utils/screen_utils.h
	$(CC) -m32 -c utils/screen_utils.c  -o out/screen_utils.o -ffreestanding -O2 -nostdlib -lgcc

clean: 
	rm out/*
