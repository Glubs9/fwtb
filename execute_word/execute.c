#include <stdio.h>
#include "../dictionary/dictionary.h"
#include "../int_stack/int_stack.h"
#include "default_words.h"
#include "number_handler.h"

void execute_word(dict_node *dn, int_stack *s, char *string)
{
	if (dn == (dict_node*) -1) {
		execute_number(s, string);
	} else if (is_default_word(dn)) {
		execute_default_word(dn, s);
	} 
}
