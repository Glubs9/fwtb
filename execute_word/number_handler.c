#include "../stack/stack.h"
#include "../dictionary/dictionary.h"

//might not need to be a separate file

//could probably just chuck this in execute.c
void execute_number_word(stack *s, dict_node *dn)
{
	int *n = dn->data;
	push_stack(s, n);
}
