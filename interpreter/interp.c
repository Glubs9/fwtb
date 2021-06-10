#include <stdbool.h>
#include "../dictionary/dictionary.h"
#include "../int_stack/int_stack.h"
#include "../input/input_stream.h"
#include "../execute_word/execute.h"

void interpret(dictionary *d, int_stack *s) {
	char *string;
	dict_node *word;
	bool compiling = false;
	while (words_left()) {
		string = get_word();
		word = search_dict(d, string);
		if (!compiling) {
			execute_word(word, s, string, &compiling);
		}
	}

}
