#include <stdio.h>
#include "../dictionary/dictionary.h"
#include "../int_stack/int_stack.h"
#include "default_words.h"

void execute_word(dict_node *dn, int_stack *s)
{
	if (is_default_word(dn)) {
		execute_default_word(dn, s);
	} else {
		printf("non default words not specified yet");
	}
}
