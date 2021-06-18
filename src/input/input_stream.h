#ifndef __INPUT_STREAM_H
#define __INPUT_STREAM_H

#include <stdbool.h> // for bool
#include <stdio.h>   // for FILE

char *get_word();
bool words_left();
void new_stream(FILE *s);
void setup_input();
void force_continue();
void new_custom_end_char(char end_char);
void reset_end_char();

#endif
