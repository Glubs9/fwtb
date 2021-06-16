#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "../dictionary/dictionary.h"
#include "../input/input_stream.h"
#include "../execute_word/execute.h"
#include "../dictionary/user_code.h"

//ok so I seem to haev made a mistake with user input but to be honest I don't really mind all that
void interpret(dictionary *d, stack *s) {
	dict_node *word;
	bool compiling = false;
	stack *call_stack;
	call_stack = init_stack();
	char *tmp_string;
	user_code *uc;
	bool immediate_b = false;

	while (words_left() || (!stack_empty(call_stack))) {
		if (stack_empty(call_stack)) {
			tmp_string = get_word();
			/*if (tmp_string[0] == '\0') { //causing errors?
				printf("in continue with %s\n", tmp_string);
				break; //break is bad rip
			}
			printf("word passed %s\n", tmp_string);*/
			word = search_dict(d, tmp_string);
			free(tmp_string); //i don't know where to put my free stuff so I put it here
		} else {
			word = pop_stack(call_stack);
		}

		if (compiling && (word->node_type != immediate) && (!immediate_b)) {
			//add to current word definition
			//(this feels weird to put in the loop, maybe move to a separate file?)
			dict_node *top = d->head;
			uc = extract_user_code(top);
			push_user_code(uc, word); //hopefully works? (it does :)
		} else {
			execute_word(d, word, s, &compiling, &immediate_b, call_stack);
		}
	}

}
