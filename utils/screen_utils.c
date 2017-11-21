/*
 * Wildfire Project
 * Author: Pablo Orduna Lagarma (end222)
 * File: utils/screen_utils.h
 */

#include "screen_utils.h"
// 80 columns, 25 lines, 2 bytes per element
#define SCREEN_BYTE_SIZE 80 * 25 * 2

char *video_ptr = (char*)0xb8000;

void clear_screen(){
        char clear = ' ';
        int i = 0;
        while(i < SCREEN_BYTE_SIZE){
                video_ptr[i] = clear;

                /* 0x07
                 * 0: Background: Black
                 * 7: Font color: Grey
                 */
                video_ptr[i+1] = 0x07;
                i += 2;
        }
}

void welcome(){
	const char *welcome_text = "Welcome to Wildfire Project";

        // Clear screen

        clear_screen();

        // Write text from the welcome_text string

        int i = 0;
        int j = 0;

        while(welcome_text[j] != '\0'){
                video_ptr[i] = welcome_text[j];
                video_ptr[i+1] = 0x47;

                i += 2;
                j += 1;
        }
}
