/*
 * Wildfire Project
 * Author: Pablo Orduna Lagarma (end222)
 * File: kernel/kernel.c
 */

void kernel_main(void){
	int i = 0;
	char clear = ' ';
	// 80 columns, 25 lines, 2 bytes per element
	int screen_byte_size = 80 * 25 * 2;
	char *video_ptr = (char*)0xb8000;
	const char *welcome_text = "Welcome to Wildfire Project";
	
	// Clear screen

	while(i < screen_byte_size){
		video_ptr[i] = clear;
		
		/* 0x07
		 * 0: Background: Black
		 * 7: Font color: Grey
		 */
		video_ptr[i+1] = 0x07;
		i += 2;
	}
	int j = 0;
	i = 0;

	// Write text from the welcome_text string
	
	while(welcome_text[j] != '\0'){
		video_ptr[i] = welcome_text[j];
		video_ptr[i+1] = 0x07;
		
		i += 2;
		j += 1;
	}
}
