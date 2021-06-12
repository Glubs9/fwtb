#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "../dictionary/dictionary.h"
#include "../int_stack/int_stack.h"
#include "../input/input_stream.h"
#include "../execute_word/execute.h"
#include "../dictionary/user_code.h"
#include "../call_stack/call_stack.h"

//ok so I seem to haev made a mistake with user input but to be honest I don't really mind all that
//much
	//the issue is that I have to deal with two stacks (one call and one input) instead of just
	//one stack and this is gonna make everything an ightmare but whatever right?
void interpret(dictionary *d, int_stack *s) {
	dict_node *word;
	bool compiling = false;
	stack *call_stack;
	c = init_stack();

	while (words_left() || (!call_stack_empty(c))) {
		if (call_stack_empty(c)) {
			char *string; //should this be moved earlier? before the while loop?
			string = get_word();
			word = search_dict(d, string);
		} else {
			word = pop_call_stack(c);
		}

		if (compiling && word->node_type != immediate) {
			//add to current word definition
			//(this feels weird to put in the loop, maybe move to a separate file?)
			dict_node *top = d->head;
			user_code *uc;
			uc = extract_user_code(top);
			push_user_code(uc, word); //hopefully works? (it does :)
		} else {
			execute_word(d, word, s, &compiling, c);
		}
	}

}
