#ifndef CALL_STACK
#define CALL_STACK

#include <stdbool.h>
#include "../dictionary/dictionary.h"

typedef struct call_stack {
	dict_node **stack; //array of dict_node pointers
	int head; //top of stack
	int allocated_head; //highest allocated size
} call_stack;

call_stack* init_call_stack();
void push_call_stack(call_stack *s, dict_node *add);
dict_node* pop_call_stack(call_stack *s);
bool call_stack_empty(call_stack *s);
void print_call_stack(call_stack *cs);

#endif
