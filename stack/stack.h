#ifndef STACK
#define STACK

typedef struct stack {
	void **stack;
	int head;
	int allocated_head;
} stack;

stack* init_stack();
void push_stack(stack *s, int add);
void* pop_stack(stack *s);
bool stack_empty(stack *s);

#endif
