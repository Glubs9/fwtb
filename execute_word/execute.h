#ifndef EXECUTE
#define EXECUTE

#include "../dictionary/dictionary.h"
#include "../stack/stack.h"

void execute_word(dictionary *d, dict_node *dn, stack *s, bool *compiling, bool *immediate_b, stack *call_stack);

#endif
