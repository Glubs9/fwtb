#include "../stack/stack.h"
#include "../dictionary/dictionary.h"

//might not need to be a separate file

//could probably just chuck this in execute.c
void execute_number_word(stack *s, dict_node *dn)
{
	push_stack(s, dn); //doesn't really need to be here
}
