#include <stdlib.h>

#include "user_code.h"
#include "dictionary.h"

user_code* extract_user_code(dict_node *dn)
{
	return (user_code*) dn->data;
}

void push_user_code(user_code *uc, dict_node *w)
{
	uc->size++;
	uc->words = realloc(uc->words, sizeof(dict_node*) * uc->size); //equals?
	uc->words[uc->size-1] = w; //size-1? 
}
