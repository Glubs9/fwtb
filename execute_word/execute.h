#ifndef EXECUTE
#define EXECUTE

#include "../dictionary/dictionary.h"
#include "../int_stack/int_stack.h"
#include "../call_stack/call_stack.h"

void execute_word(dictionary *d, dict_node *dn, int_stack *s, char *string, bool *compiling, call_stack *c);

#endif
