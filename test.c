#include <stdio.h>

#include "dictionary/dictionary.h"
#include "int_stack/int_stack.h"
#include "input/input_stream.h"
#include "execute_word/execute.h"
#include "execute_word/default_words.h"

int main()
{
	dictionary *d;
	d = init_dict();
	printf("after init dict\n");
	add_default_words(d);
	printf("after adddefault words");
	int_stack *s;
	printf("before init_stack\n");
	s = init_int_stack();
	printf("> ");
	setup_input();
	while (words_left()) {
		char *string;
		string = get_word();
		dict_node *word;
		word = search_dict(d, string);
		execute_word(word, s, string);
	}
}
