/*
 * Wildfire Project
 * Author: Pablo Orduna Lagarma (end222)
 * File: kernel/kernel.c
 */

#include "../utils/screen_utils.h"

void kernel_main(void){
	clear_screen();
	welcome();
	new_line();
	int i = 0;
	print_text("login: ",0x07);
}
