#ifndef DEFAULT_WORDS
#define DEFAULT_WORDS

//should I move this file?

#include "../dictionary/dictionary.h"
#include "../stack/stack.h"
#include <stdbool.h>

bool is_default_word(dict_node *node);
void execute_default_word(dictionary *d, dict_node *node, stack *s, bool *compiling, bool *immediate, stack *c);
void add_default_words(dictionary *d); //idk if I should move this function elsewhere

#endif
