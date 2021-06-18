#include "input_stream.h"
#include <errno.h>	   // for errno
#include <stdbool.h>   // for false, bool, true
#include <stdio.h>	   // for fgetc, printf, EOF, FILE, stdin
#include <stdlib.h>	   // for exit, malloc, EXIT_FAILURE
#include "CONSTANTS.h" // for MAX_WORD_LENGTH

FILE *stream;
bool end_reached;
bool using_custom_end_char; //for when a custom end character is used instead of empty space
char custom_end_char;

char *get_word()
{
	if (end_reached)
	{
		printf("get word called while end has been reached\n");
		errno = 12; //maybe wrong error number?
		exit(EXIT_FAILURE);
	}
	char *buff = malloc(sizeof(char) * MAX_WORD_LENGTH);
	char c = fgetc(stream);
	int head = 0;

	//this feels wrong, refactor later
	if (using_custom_end_char)
	{
		while (c != custom_end_char)
		{
			c = fgetc(stream);
			buff[head] = c;
			head++;
		}
	}
	else
	{
		//note: switch this loop to do while loop later
		while (c != ' ' && c != '\t' && c != '\n' && c != EOF)
		{
			buff[head] = c;
			c = fgetc(stream);
			head++;
		}
	}
	buff[head] = '\0';
	if (c == EOF)
	{
		end_reached = true;
	}
	else if (stream == stdin && c == '\n')
	{
		end_reached = true;
	}
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

void force_end()
{
	end_reached = true;
}

void setup_input()
{
	stream = stdin;
	end_reached = false;
}

void new_custom_end_char(char end_char)
{
	using_custom_end_char = true;
	custom_end_char = end_char;
}

void reset_end_char()
{
	using_custom_end_char = false;
}

