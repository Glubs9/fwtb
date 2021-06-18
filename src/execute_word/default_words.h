#ifndef __DEFAULT_WORDS_H
#define __DEFAULT_WORDS_H

#include <stdbool.h>                  // for bool
#include "../dictionary/dictionary.h" // for dict_node, dictionary
#include "../stack/stack.h"           // for stack

//should I move this file?

bool is_default_word(dict_node *node);
void execute_default_word(dictionary *d, dict_node *node, stack *s, bool *compiling, bool *immediate, stack *c);
void add_default_words(dictionary *d); //idk if I should move this function elsewhere

#endif
