#include "execute.h"
#include <stdio.h>					  // for printf
#include "../dictionary/dictionary.h" // for dict_node, code, data, dictionary
#include "../stack/stack.h"			  // for push_stack, stack
#include "default_words.h"			  // for execute_default_word, is_defau...
#include "execute_user_code.h"		  // for execute_user_code, execute_use...
#include "number_handler.h"			  // for execute_number_word

void execute_word(dictionary *d, dict_node *dn, stack *s, bool *compiling, bool *immediate_b, stack *call_stack)
{
	if (is_default_word(dn))
	{
		execute_default_word(d, dn, s, compiling, immediate_b, call_stack);
	}
	else if (dn->node_type == code)
	{ //assuming user code
		execute_user_code(dn, call_stack);
	}
	else if (dn->node_type == immediate)
	{
		execute_user_immediate(d, dn, call_stack);
	}
	else if (dn->node_type == number)
	{
		execute_number_word(s, dn);
	}
	else if (dn->node_type == data)
	{
		push_stack(s, dn); //push stack feels weird not being in it's own file but tbh it's too late to care (this push does mean that the stack contains (int*) and (void*) but whatever) (pushing data feels weird as well, might be able to just push dn)
	}
	else
	{
		//for immediate words I might just be able to execute_code ?
		printf("this kind of node type has not yet been implemented\n");
	}
}
