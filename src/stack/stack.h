#ifndef __STACK_H
#define __STACK_H

#include <stdbool.h>

typedef struct stack
{
	void **stack;
	int head;
} stack;

stack *init_stack();
void push_stack(stack *s, void *add);
void *pop_stack(stack *s);
bool stack_empty(stack *s);

#endif
