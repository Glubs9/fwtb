#include <stdlib.h>
#include <stdio.h>

#include "user_code.h"

user_code *init_user_code()
{
	user_code *uc = malloc(sizeof(user_code));
	uc->size = 0;
	uc->words = malloc(sizeof(dict_node *) * 1);
	return uc;
}

user_code *extract_user_code(dict_node *dn)
{
	return (user_code *)dn->data;
}

void push_user_code(user_code *uc, dict_node *w)
{
	uc->size++;
	uc->words = realloc(uc->words, sizeof(dict_node *) * uc->size); //equals?
	uc->words[uc->size - 1] = w;									//size-1?
}

void print_user_code(user_code *uc)
{
	printf("print user code called\n");
	for (int i = 0; i < uc->size; i++)
	{
		printf("%s ", uc->words[i]->name);
	}
	printf("\n");
}

int extract_int(dict_node *dn)
{
	int *n = malloc(sizeof(int)); //unecersarry allocation, make sure to test tuck if this is changed
	int *tmp = dn->data;
	*n = *tmp;
	return *n;
}
