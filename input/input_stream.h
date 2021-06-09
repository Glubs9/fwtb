#ifndef INPUT_STREAM
#define INPUT_STREAM

#include <stdbool.h>
char* get_word();
bool words_left();
void new_stream(FILE *s);
void setup_input();

#endif
