#ifndef EXECUTE
#define EXECUTE

#include "../dictionary/dictionary.h"
#include "../stack/stack.h"

void execute_word(dictionary *d, dict_node *dn, stack *s, bool *compiling, stack *call_stack);

#endif
