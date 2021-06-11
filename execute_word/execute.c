#include <stdio.h>
#include "../dictionary/dictionary.h"
#include "../call_stack/call_stack.c"
#include "../int_stack/int_stack.h"
#include "default_words.h"
#include "number_handler.h"
#include "execute_user_code.h"

void execute_word(dictionary *d, dict_node *dn, int_stack *s, char *string, bool *compiling, call_stack *c)
{
	if (dn == (dict_node*) -1) { //delete later
		execute_number(s, string);
	} else if (is_default_word(dn)) {
		execute_default_word(d, dn, s, compiling, c);
	} else if (dn->node_type == code) { //assuming user code
		execute_user_code(dn, c);
	} else if (dn->node_type == number) {
		execute_number_word(s, dn);
	}
}
