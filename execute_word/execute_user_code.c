#include <stdlib.h> //might not be used, delete if unecersrarry
#include <stdio.h> //debugging, delete later
#include "../dictionary/user_code.h"
#include "../call_stack/call_stack.h"

void execute_user_code(dict_node *dn, call_stack *cs) 
{
	user_code *uc;
	uc = extract_user_code(dn);
	for (int i = uc->size-1; i >= 0; i++) {
		printf("pushing to call_stack \n");
		push_call_stack(cs, uc->words[i]);
		printf("pushed to call stack\n");
	}
	printf("before printing call stack\n");
	print_call_stack(cs);
}
