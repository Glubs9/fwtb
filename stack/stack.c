#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

stack* init_stack()
{
	stack *ret = malloc(sizeof(stack));
	ret->stack = malloc(sizeof(void*) * 1);
	ret->head = 0;
	ret->allocated_head = 1;
	return ret;
}

void push_stack(stack *s, void* add)
{
	s->head++;
	if (s->head >= s->allocated_head) {
		s->allocated_head++;
		s->stack = realloc(s->stack, s->allocated_head); //check that this isn't causing the overflow
	}
	s->stack[s->head-1] = add;
}

void *pop_stack(stack *s)
{
	free(s->stack[s->head]); //this many memoery allocations could be slow
	s->head--;
	s->allocated_head--; //due to de allocating every time we don't need both head and allocated head but this will change later
	return s->stack[s->head];
}

bool stack_empty(stack *s)
{
	return (s->head == 0);
}

//idk how i should do this?
/*
void prstack(stack *s)
{
}
*/
