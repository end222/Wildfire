/*
 * Wildfire Project
 * Author: Pablo Orduna Lagarma (end222)
 * File: utils/screen:utils.h
 */

#include <stddef.h>
#include <stdint.h>

void vertical_scroll_up();

void clear_screen();

void print_text(const char *text, uint8_t attributes);

void welcome();

void new_line();
