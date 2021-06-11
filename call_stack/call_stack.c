#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "call_stack.h"
#include "../dictionary/dictionary.h"

//todo: merge this with int_stack and user_code as these bits of code all do pretty much the same
//thing (not pretty much exactly the same thing)
	//maybe as a void* stack
	//and just have a generic stack implementation
	//do this afterward cause right now we tryna get definitions working

call_stack* init_call_stack()
{
	call_stack* ret = malloc(sizeof(call_stack));
	ret->stack = malloc(sizeof(dict_node*) * 1);
	ret->head = 0;
	ret->allocated_head = 1;
	return ret;
}

//yeah like for example this code is identical to int_stack.c push_int_stack
void push_call_stack(call_stack *s, dict_node *add)
{
	s->head++;
	if (s->head >= s->allocated_head) {
		s->allocated_head++;
		s->stack = realloc(s->stack, s->allocated_head);
	}
	s->stack[s->head-1] = add; //DO NOT DELETE IDIOT
}

dict_node* pop_call_stack(call_stack *s)
{
	s->head--;
	return s->stack[s->head]; //maybe? YES!
}

bool call_stack_empty(call_stack *s)
{
	return (s->head == 0);
}

void print_call_stack(call_stack *cs)
{
	printf("print_call_stack called\n");
	for (int i = 0; i < cs->head; i++) {
		printf("%s ", cs->stack[i]->name);
	}
	printf("\n");
}
