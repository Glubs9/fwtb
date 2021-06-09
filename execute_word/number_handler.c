#include <stdlib.h>
#include <stdio.h> //for debugging, delete later
#include "../int_stack/int_stack.h"

//might not need to be a separate file
	//but it feels better tahn putting it in execute.c
	//I feel like maybe I should move this to dictionary so that when an unsuccessful dictioanry
	//search is done it can directly return the number and execute_word will be simpler

void execute_number(int_stack *s, char *string)
{
	char *p;
	int n = strtol(string, &p, 10); //check for errors
	push_int_stack(s, n);
}
