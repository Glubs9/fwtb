#include <stdbool.h>
#include "../dictionary/dictionary.h"
#include "../int_stack/int_stack.h"
#include "../input/input_stream.h"
#include "../execute_word/execute.h"
#include "../dictionary/user_code.h"

void interpret(dictionary *d, int_stack *s) {
	char *string;
	dict_node *word;
	bool compiling = false;
	while (words_left()) {
		string = get_word();
		word = search_dict(d, string);
		if (compiling && word->node_type != immediate) {
			dict_node *top = d->head;
			user_code *ud = (user_code*) top->data;
		} else {
			execute_word(word, d, s, string);
		}
	}

}
