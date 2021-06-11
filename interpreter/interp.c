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
	char *string;
	dict_node *word;
	bool compiling = false;
	call_stack *c;
	c = init_call_stack();
	user_code *uc;
	while (words_left() || (!call_stack_empty(c))) {
		if (call_stack_empty(c)) {
			string = get_word();
			word = search_dict(d, string);
		} else {
			word = pop_call_stack(c);
			string = word->name; //this is why I feel string is superfluous
		}
		if (compiling && (word == (dict_node*)-1 || word->node_type != immediate)) {
			dict_node *top = d->head;
			uc = extract_user_code(top);
			if (word == (dict_node*) -1) { //see this is the problem with having nubmer literals as strings
				//thsi definition is what we should have instead
				//this absolutely should move
				word = malloc(sizeof(dict_node));
				strcpy(word->name, string);
				char *p;
				int n = strtol(string, &p, 10);
				word->data = &n;
				word->node_type = number;
			}
			push_user_code(uc, word); //hopefully works?
		} else {
			execute_word(d, word, s, string, &compiling, c);
		}
	}

}
