#ifndef __EXECUTE_H
#define __EXECUTE_H

#include <stdbool.h>                  // for bool
#include "../dictionary/dictionary.h" // for dict_node, dictionary
#include "../stack/stack.h"           // for stack

void execute_word(dictionary *d, dict_node *dn, stack *s, bool *compiling, bool *immediate_b, stack *call_stack);

#endif
