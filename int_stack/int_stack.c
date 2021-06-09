#include <stdlib.h>
#include <stdio.h>
#include "int_stack.h"

//this file holds the commands for manipulating a stack of ints (the main data stack in forth)

int_stack* init_int_stack()
{
	int_stack *ret; //do I need to allocate?
	ret->stack = malloc(sizeof(int) * 1);
	ret->head = 0;
	ret->allocated_head = 1;
}

void push_int_stack(int_stack *s, int add)
{
	s->head++;
	if (s->head >= s->allocated_head) {
		s->allocated_head++; //might be worth allocating more space to speed up (like the 2* thing)
		s->stack = realloc(s->stack, s->allocated_head);
	}
	s->stack[s->head] = add;
}

//how to handle stack out of size?
	//throw error or something
int pop_int_stack(int_stack *s)
{
	s->head--; //might be worth deallocating memory here if the difference between head and allocated head is too large but for now it probably doesn't matter
	return s->stack[s->head+1];
}

//might change where this is but for now it works
void print_int_stack(int_stack *s)
{
	for (int i = 1; i <= s->head; i++) { //something wacky is happening with the stack indexes
		printf("%d ", s->stack[i]);
	}
	printf("\n");
}

//main for basic testing and analysis
/*
#include <stdio.h>
int main()
{
	printf("before create_int_tsack \n");
	int_stack* s = init_int_stack();
	printf("created stack\n");
	push_int_stack(s, 3);
	printf("pushed 3\n");
	push_int_stack(s, 4);
	printf("pushed 4\n");
	int i1 = pop_int_stack(s);
	int i2 = pop_int_stack(s);
	printf("%d %d\n", i1, i2);
	printf("after print 4 3\n");
}
*/
