#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../dictionary/dictionary.h"
#include "../dictionary/user_code.h"
#include "../stack/stack.h"
#include "../input/input_stream.h"

//this file describes the execution of some default words

//i really don't know how to do this file

//i don't know forth well enough to boostrap from these instructions alone but i'm going to give
//it my best shot
bool is_default_word(dict_node *node)
{
	char *n = node->name;
	return (
		strcmp(n, ".") == 0 ||
		strcmp(n, ".s") == 0 ||
		strcmp(n, "+") == 0 ||
		strcmp(n, "-") == 0 ||
		strcmp(n, "*") == 0 ||
		strcmp(n, "/") == 0 ||
		strcmp(n, "@") == 0 || //instructions here and below are not implemented yet
		strcmp(n, "!") == 0 ||
		strcmp(n, "CREATE") == 0 ||
		strcmp(n, "DOES>") == 0 ||
		strcmp(n, ":") == 0 ||
		strcmp(n, ";") == 0 ||
		strcmp(n, "=") == 0
	);
}

void execute_default_word(dictionary* d, dict_node *node, stack *s, bool *compiling, stack *call_stack)
{
	//wish switch statement worked on strings
	char *n = node->name;
	if (strcmp(n, ".") == 0) {
		int *n = pop_stack(s);
		printf("v: %d s->head: %d\n", (*n), s->head);
	} else if (strcmp(n, ".s") == 0) {
		//maybe I should put this somewhere else but tbh I can't be bothered
		for (int i = 0; i < s->head; i++) {
			int *n = s->stack[i];
			printf("%d ", *n); //deallocated before
		}
		printf("\n");
	} else if (strcmp(n, "+") == 0) {
		int *tos1 = pop_stack(s);
		int *tos2 = pop_stack(s);
		int *n = malloc(sizeof(int));
		*n = (*tos1)+(*tos2);
		push_stack(s, n);
	} else if (strcmp(n, "-") == 0) {
		int *tos1 = pop_stack(s);
		int *tos2 = pop_stack(s);
		int *n = malloc(sizeof(int));
		*n = (*tos1)-(*tos2);
		push_stack(s, n);
	} else if (strcmp(n, "*") == 0) {
		int *tos1 = pop_stack(s);
		int *tos2 = pop_stack(s);
		int *n = malloc(sizeof(int));
		*n = (*tos1)*(*tos2);
		push_stack(s, n);
	} else if (strcmp(n, "/") == 0) {
		int *tos1 = pop_stack(s);
		int *tos2 = pop_stack(s);
		int *n = malloc(sizeof(int));
		*n = (*tos1)/(*tos2);
		push_stack(s, n);
	} else if (strcmp(n, ":") == 0) {
		(*compiling) = true;
		char *string;
		string = get_word(); //error check and maybe modularize later (also means definitions can't strech lines in repl)
		//i feel i should have data = push self to stack but i can't be bothered with that right now
		user_code *uc;
		uc = init_user_code();
		push_word(d, string, (void*) uc, code); //void* type cast might be unecersarry
	} else if (strcmp(n, ";") == 0) {
		(*compiling) = false;
		//add exit to data on word (maybe not? i'm not 100% on how I have implemented this language)
	} else if (strcmp(n, "=") == 0) { 
		int *tos1 = pop_stack(s);
		int *tos2 = pop_stack(s);
		int *n = malloc(sizeof(int));
		*n = (*tos1) == (*tos2); //int because pushing to int stack but it could be bool
		push_stack(s, n);
	} else {
		printf("default word called that has not been implemented\n");
	}
}

void add_default_words(dictionary *d)
{
	enum node_type nt = code;
	void *data = NULL; //do I have to allocate (data should be empty? but in real forth this is a machine code whatever)
	push_word(d, ".", data, nt); //maybe using the same data is causing this error
	push_word(d, ".s", data, nt);
	push_word(d, "+", data, nt);
	push_word(d, "-", data, nt);
	push_word(d, "*", data, nt);
	push_word(d, "/", data, nt);
	push_word(d, "@", data, nt);
	push_word(d, "!", data, nt);
	push_word(d, "CREATE", data, nt);
	push_word(d, "DOES>", data, nt);
	push_word(d, ":", data, nt);
	push_word(d, ";", data, immediate);
}
