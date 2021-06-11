#include "../int_stack/int_stack.h"
#include "../dictionary/dictionary.h"

//might not need to be a separate file

//could probably just chuck this in execute.c
void execute_number_word(int_stack *s, dict_node *dn)
{
	int *n = dn->data;
	push_int_stack(s, *n);
}
