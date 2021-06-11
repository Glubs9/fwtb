#include <stdlib.h> //might not be used, delete if unecersrarry
#include <stdio.h> //debugging, delete later
#include "../dictionary/user_code.h"
#include "../call_stack/call_stack.h"

void execute_user_code(dict_node *dn, call_stack *cs) 
{
	user_code *uc;
	uc = extract_user_code(dn);
	for (int i = 0; i < uc->size; i++) {
		push_call_stack(cs, uc->words[i]);
	}
}