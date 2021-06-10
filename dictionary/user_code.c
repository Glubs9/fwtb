#include <stdlib.h>

#include "user_code.h"
#include "dictionary.h"

user_code* extract_user_code(dict_node *dn)
{
	return (user_data*) dn->data;
}

void push_user_code(user_code *uc, dict_node *w)
{
	uc->size++;
	uc->words = realloc(sizeof(dict_node*) * uc->size);
	uc->words[size-1] = w; //size-1? 
}
