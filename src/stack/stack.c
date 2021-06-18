#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <errno.h>

#include "stack.h"

stack* init_stack()
{
	stack *ret = malloc(sizeof(stack));
	ret->stack = malloc(sizeof(void*) * 1);
	ret->head = 0;
	return ret;
}

void push_stack(stack *s, void* add)
{
	s->head++;
	s->stack = realloc(s->stack, sizeof(void*) * s->head); //check that this isn't causing the overflow
	*(s->stack + s->head-1) = add;
}

void *pop_stack(stack *s)
{
	if (s->head != 0) {
		s->head--;
		return *(s->stack + s->head); //shifted away from using array operators cause memoery?
	}
	printf("ERROR: POPPPED EMPTY STACK\n"); //maybe print call stack?
	errno = 12;
	exit(EXIT_FAILURE);
}

bool stack_empty(stack *s)
{
	return (s->head == 0);
}
