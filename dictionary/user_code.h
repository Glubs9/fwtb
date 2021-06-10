#ifndef USERCODE
#define USERCODE

#include "dictionary.h"

//user defined code (stored in void* data in dict_node)
typedef struct user_code {
	int size;
	dict_node **words;
} user_code;

user_code *extract_user_code(dict_node *dn);
void push_user_code(user_code *c, dict_node *w);

#endif
