#include <stdbool.h>					// for true
#include <stdio.h>						// for printf, fclose, fopen
#include "execute_word/default_words.h" // for add_default_words
#include "input/input_stream.h"			// for new_stream, force_...
#include "dictionary/dictionary.h"		// for init_dict, dictionary
#include "interpreter/interp.h"			// for interpret
#include "stack/stack.h"				// for init_stack, stack

//this feels unecersarry
void setup(dictionary **d, stack **s)
{
	*d = init_dict();
	add_default_words(*d);
	*s = init_stack();
	setup_input();
	FILE *f = fopen("stdlib.fs", "r");
	new_stream(f);
	interpret(*d, *s);
	fclose(f);
	new_stream(stdin);
}

int main()
{
	printf("Welcome to Forth with the boys!\n\n");
	dictionary *d;
	stack *s;
	setup(&d, &s);
	while (true)
	{
		printf("> ");
		interpret(d, s);
		printf(" ok\n");
		force_continue();
	}
}
