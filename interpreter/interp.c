#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "../dictionary/dictionary.h"
#include "../input/input_stream.h"
#include "../execute_word/execute.h"
#include "../dictionary/user_code.h"

//ok so I seem to haev made a mistake with user input but to be honest I don't really mind all that
//much
	//the issue is that I have to deal with two stacks (one call and one input) instead of just
	//one stack and this is gonna make everything an ightmare but whatever right?
void interpret(dictionary *d, stack *s) {
	dict_node *word;
	bool compiling = false;
	stack *call_stack;
	call_stack = init_stack();
	char *tmp_string;

	while (words_left() || (!stack_empty(call_stack))) {
		if (stack_empty(call_stack)) {
			tmp_string = get_word();
			word = search_dict(d, tmp_string);
		} else {
			word = pop_stack(call_stack);
		}

		if (compiling && word->node_type != immediate) {
			//add to current word definition
			//(this feels weird to put in the loop, maybe move to a separate file?)
			dict_node *top = d->head;
			user_code *uc;
			uc = extract_user_code(top);
			push_user_code(uc, word); //hopefully works? (it does :)
		} else {
			execute_word(d, word, s, &compiling, call_stack);
		}
	}

}
