#ifndef __NUMBER_HANDLER__H
#define __NUMBER_HANDLER__H

#include "../stack/stack.h"
#include "../dictionary/dictionary.h"

void execute_number(stack *s, char *string);
void execute_number_word(stack *s, dict_node *dn);

#endif
