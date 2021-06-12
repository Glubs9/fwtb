#include "dictionary/dictionary.h"
#include "input/input_stream.h"
#include "execute_word/execute.h"
#include "execute_word/default_words.h"
#include "interpreter/interp.h"
#include "stack/stack.h"

//this feels unecersarry
void setup(dictionary **d, stack **s)
{
	*d = init_dict();
	add_default_words(*d);
	//add stdlib here
	*s = init_stack();
	setup_input();
}

int main()
{
	printf("welcome to forth with the boys\n\n");
	dictionary *d;
	stack *s;
	setup(&d, &s);
	while (true) {
		printf("> ");
		interpret(d, s);
		force_continue();
	}
}
