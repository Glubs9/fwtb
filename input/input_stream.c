#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include "input_stream.h"
#include "CONSTANTS.h"

FILE *stream;
bool end_reached;

char* get_word()
{
	if (end_reached) {
		printf("get word called while end has been reached\n");
		errno = 12; //maybe wrong error number?
		exit(EXIT_FAILURE);
	}
	char *buff = malloc(sizeof(char) * MAX_WORD_LENGTH);
	char c = fgetc(stream);
	int head = 0;
	//note: switch this loop to do while loop later
	while (c != ' ' && c != '\t' && c != '\n' && c != EOF) {
		buff[head] = c;
		c = fgetc(stream);
		head++;
	}
	buff[head] = '\0';
	if (c == EOF) { end_reached = true; }
	else if (stream == stdin && c == '\n') { end_reached = true; }
	return buff;
}

//little superfluous
bool words_left()
{
	return !end_reached;
}

//add fflush
void new_stream(FILE *s)
{
	stream = s;
	end_reached = false;
}

//useful for getting new line input from stdin
void force_continue()
{
	//do something here
	end_reached = false;
}

void setup_input()
{
	stream = stdin;
	end_reached = false;
}

//test main example
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
