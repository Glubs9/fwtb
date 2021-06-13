#include <stdlib.h> //might not be used, delete if unecersrarry
#include <stdio.h> //debugging, delete later
#include "../dictionary/user_code.h"
#include "../stack/stack.h"

void print_debug(user_code *uc)
{
	printf("printing debug\n");
	printf("uc pointer %d\n", uc);
	printf("uc size %d\n",uc->size);
	for (int i = 0; i < uc->size; i++) {
		printf("%s \n", uc->words[i]->name);
	}
	printf("end debug\n");
}

void execute_user_code(dict_node *dn, stack *call_stack) 
{
	user_code *uc;
	uc = extract_user_code(dn); //is this is a pointer?
	//print_debug(uc);
	for (int i = uc->size-1; i >= 0; i--) {
		printf("pushing to stack \n");
		push_stack(call_stack, uc->words[i]);
		printf("pushed to call stack\n");
	}
	printf("before printing call stack\n");
}
