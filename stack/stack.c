#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

stack* init_stack()
{
	stack *ret = malloc(sizeof(stack));
	ret->stack = malloc(sizeof(void*) * 1);
	ret->head = 0;
	ret->allocated_head = 1;
}

void push_int_stack(stack *s, void* add)
{
	s->head++;
	if (s->head >= s->allocated_head) {
		s->allocated_head++;
		s->stack = realloc(s->stack, s->allocated_head); //check that this isn't causing the overflow
	}
	s->stack[s->head] = add;
}

void *pop_sack(stack *s)
{
	s->head--;
	return s->stack[s->head+1];
}

bool stack_empty(stack *s)
{
	return (s->head == 0);
}

//idk how i should do this?
/*
void print_stack(stack *s)
{
}
*/
