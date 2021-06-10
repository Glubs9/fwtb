#include <stdbool.h>
#include "../dictionary/dictionary.h"
#include "../int_stack/int_stack.h"
#include "../input/input_stream.h"
#include "../execute_word/execute.h"
#include "../dictionary/user_code.h"

//ok so I seem to haev made a mistake with user input but to be honest I don't really mind all that
//much
	//the issue is that I have to deal with two stacks (one call and one input) instead of just
	//one stack and this is gonna make everything an ightmare but whatever right?
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
			execute_word(d, word, s, string, &compiling);
		}
	}

}
