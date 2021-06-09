#ifndef INT_STACK
#define INT_STACK

typedef struct int_stack {
	int *stack;
	int head; //top of stack
	int allocated_head; //highest allocated size
} int_stack;

int_stack* init_int_stack();
void push_int_stack(int_stack *s, int add);
int pop_int_stack(int_stack *s);
void print_int_stack(int_stack *s);

#endif
