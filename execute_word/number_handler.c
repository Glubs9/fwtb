#include <stdlib.h>
#include "../int_stack/int_stack.h"

//might not need to be a separate file
	//but it feels better tahn putting it in execute.c

void execute_number(int_stack *s, char *string)
{
	char *p;
	int n = strtol(string, &p, 10); //check for errors
	push_int_stack(s, n);
}
