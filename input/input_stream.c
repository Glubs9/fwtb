//currently this code is broken but this is the general idea for the input

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "input_stream.h"
#include "CONSTANTS.h"

FILE *stream;
bool end_reached;

char* get_word()
{
	char* buff = malloc(sizeof(char) * MAX_WORD_LENGTH);
	int tmp = fscanf(stream, "%s", buff);
	if (tmp == EOF) { end_reached = false; }
	return buff;
}

//little superfluous
bool words_left()
{
	return !end_reached;
}

void new_stream(FILE *s)
{
	stream = s;
	end_reached = false;
}

void setup_input()
{
	stream = stdin;
	end_reached = false;
}

//main exists for testing
/*
int main()
{
	setup_input();
	printf("> ");
	while (words_left()){
		printf("%s \n", get_word());
	}
	printf("end \n");
}
*/
