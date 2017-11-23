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

void print_text(const char *text, uint8_t attributes){
	int i = 0;

        // Write text from the text string

        while(text[i] != '\0'){
		if(text[i] == '\n'){
			new_line();
		}
		else{
                	video_ptr[screen_location] = text[i];
                	video_ptr[screen_location+1] = attributes;

                	screen_location += 2;
		}
                i += 1;
        }
}

void welcome(){
	print_text("W",0x04);
	print_text("I",0x0C);
	print_text("L",0x0A);
	print_text("D",0x02);
	print_text("F",0x0B);
	print_text("I",0x09);
	print_text("R",0x01);
	print_text("E",0x05);
}

void new_line(){
	// Get to the beginning of the current line
	screen_location = screen_location / 160 * 160;
	
	// Jump to the next line
	screen_location = screen_location + 160;
}
