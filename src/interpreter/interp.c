#include <stdbool.h>								  // for bool, false
#include <stdlib.h>									  // for free, malloc
#include <string.h>									  // for strcmp, strcpy
#include "../dictionary/CONSTANTS.h"				  // for MAX_NAME_LENGTH
#include "../dictionary/user_code.h"				  // for extract_user_code
#include "../execute_word/../dictionary/dictionary.h" // for dict_node, sea...
#include "../execute_word/../stack/stack.h"			  // for stack_empty
#include "../execute_word/execute.h"				  // for execute_word
#include "../input/input_stream.h"					  // for get_word, new_...

//ok so I seem to haev made a mistake with user input but to be honest I don't really mind all that
void interpret(dictionary *d, stack *s)
{
	dict_node *word;
	bool compiling = false;
	stack *call_stack;
	call_stack = init_stack();
	char *tmp_string;
	user_code *uc;
	bool immediate_b = false;
	bool commenting = false; //not currently used but use it later when i refactor to passing struct

	while (words_left() || (!stack_empty(call_stack)))
	{
		if (stack_empty(call_stack))
		{
			tmp_string = get_word();
			char *str = malloc(sizeof(char) * MAX_NAME_LENGTH); //sizeof(char) unecersarry
			strcpy(str, tmp_string);
			if (strcmp(str, "") == 0)
			{ //causing errors?
				continue;
			}
			else if (strcmp(str, "(") == 0)
			{
				//i feel like this should be moved to execute.c but honestly I am passing so many
				//paramters to execute_word, maybe i should switch to using a struct to pass
				new_custom_end_char(')');
				get_word();
				reset_end_char();
				continue;
			}
			else if (strcmp(str, "\\") == 0)
			{
				new_custom_end_char('\n'); //yikes
				get_word();
				reset_end_char();
				continue;
			}
			word = search_dict(d, tmp_string);
			free(tmp_string); //i don't know where to put my free stuff so I put it here
		}
		else
		{
			word = pop_stack(call_stack);
		}

		if (compiling && (word->node_type != immediate) && (!immediate_b))
		{
			//add to current word definition
			//(this feels weird to put in the loop, maybe move to a separate file?)
			dict_node *top = d->head;
			uc = extract_user_code(top);
			push_user_code(uc, word); //hopefully works? (it does :)
		}
		else
		{
			execute_word(d, word, s, &compiling, &immediate_b, call_stack);
		}
	}
}
