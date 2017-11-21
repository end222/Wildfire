/*
 * Wildfire Project
 * Author: Pablo Orduna Lagarma (end222)
 * File: utils/screen_utils.h
 */
#include <stddef.h>
#include <stdint.h>
#include "screen_utils.h"
// 80 columns, 25 lines, 2 bytes per element
#define SCREEN_BYTE_SIZE 80 * 25 * 2

uint8_t* video_ptr = (uint8_t*)0xB8000;

// Variable to control the location in the screen
int screen_location = 0; 

void clear_screen(){
        char clear = ' ';
        while(screen_location < SCREEN_BYTE_SIZE){
                video_ptr[screen_location] = clear;

                /* 0x07
                 * 0: Background: Black
                 * 7: Font color: Grey
                 */
                video_ptr[screen_location+1] = 0x07;
                screen_location += 2;
        }
	// Point back to the beginning of the screen
	screen_location = 0;
}

void welcome(){
	const char *welcome_text = "Welcome to Wildfire Project";
	int j = 0;

        // Write text from the welcome_text string

        while(welcome_text[j] != '\0'){
                video_ptr[screen_location] = welcome_text[j];
                video_ptr[screen_location+1] = 0x47;

                screen_location += 2;
                j += 1;
        }
}

void new_line(){
	// Get to the beginning of the current line
	screen_location = screen_location / 160 * 160;
	
	// Jump to the next line
	screen_location = screen_location + 160;
}
