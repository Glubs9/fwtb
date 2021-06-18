#ifndef __USERCODE_H
#define __USERCODE_H

#include "dictionary.h" // for dict_node

//user defined code (stored in void* data in dict_node)
typedef struct user_code
{
	int size;
	dict_node **words;
} user_code;

user_code *init_user_code();
user_code *extract_user_code(dict_node *dn);
void push_user_code(user_code *c, dict_node *w);
void print_user_code(user_code *uc);
int extract_int(dict_node *dn);

#endif
