#ifndef DEFAULT_WORDS
#define DEFAULT_WORDS

//should I move this file?

#include "../dictionary/dictionary.h"
#include "../int_stack/int_stack.h"
#include <stdbool.h>

bool is_default_word(dict_node *node);
void execute_default_word(dict_node *node, int_stack *s);
void add_default_words(dictionary *d); //idk if I should move this function elsewhere

#endif
