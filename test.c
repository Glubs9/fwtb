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
	add_default_words(d);
	int_stack *s;
	s = init_int_stack();
	setup_input();
	while (words_left()) {
		char *string;
		string = get_word();
		dict_node *word;
		word = search_dict(d, string);
		execute_word(word, s);
	}
}
