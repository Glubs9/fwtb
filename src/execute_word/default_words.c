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
		strcmp(n, "EMIT") == 0 ||
		strcmp(n, ".s") == 0 ||
		strcmp(n, "+") == 0 ||
		strcmp(n, "-") == 0 ||
		strcmp(n, "*") == 0 ||
		strcmp(n, "/") == 0 ||
		strcmp(n, "@") == 0 || //instructions here and below are not implemented yet
		strcmp(n, "!") == 0 ||
		strcmp(n, "DOES>") == 0 ||
		strcmp(n, ":") == 0 ||
		strcmp(n, ";") == 0 ||
		strcmp(n, "=") == 0 ||
		strcmp(n, "IMMEDIATE") == 0 ||
		strcmp(n, "ENTER_IMMEDIATE") == 0 || //used to set interpreter flag immediate to true
		strcmp(n, "EXIT_IMMEDIATE") == 0 ||
		strcmp(n, "CREATE") == 0 ||
		strcmp(n, "!") == 0 ||
		strcmp(n, "@") == 0 
	);
}

int extract_int(dict_node *dn)
{
	int *n = dn->data;
	return *n;
}

//short hand for writing extract int from top of stack (e.p.s == extract pop stack)
int eps(stack *s)
{
	return extract_int(pop_stack(s));
}

//TOOD: fix shadowing input char *n and int n in this function.
void execute_default_word(dictionary* d, dict_node *node, stack *s, bool *compiling, bool *immediate_b, stack *call_stack)
{
	//wish switch statement worked on strings
	char *n = node->name;
	if (strcmp(n, ".") == 0) {
		int n = eps(s);
		printf("%d\n", n);
	} else if (strcmp(n, "EMIT") == 0) {
		char n = eps(s);
		printf("%c\n", n);
	} else if (strcmp(n, ".s") == 0) {
		//maybe I should put this somewhere else but tbh I can't be bothered
		for (int i = 0; i < s->head; i++) {
			int n = extract_int(s->stack[i]); //this is causing issue with stuff on stack that is not int
			printf("%d ", n);
		}
		printf("\n");
	} else if (strcmp(n, "+") == 0) {
		int tos1 = eps(s); //do we have to free?
		int tos2 = eps(s);
		int *n = malloc(sizeof(int));
		*n = tos1+tos2;
		dict_node *dn = create_dict_node("add_num", n, number, NULL); //change name later? (with like format string or something)
		push_stack(s, dn);
	} else if (strcmp(n, "-") == 0) {
		int tos1 = eps(s); //do we have to free?
		int tos2 = eps(s);
		int *n = malloc(sizeof(int));
		*n = tos1-tos2;
		dict_node *dn = create_dict_node("add_num", n, number, NULL); //change name later? (with like format string or something)
		push_stack(s, dn);
	} else if (strcmp(n, "*") == 0) {
		int tos1 = eps(s); //do we have to free?
		int tos2 = eps(s);
		int *n = malloc(sizeof(int));
		*n = tos1*tos2;
		dict_node *dn = create_dict_node("add_num", n, number, NULL); //change name later? (with like format string or something)
		push_stack(s, dn);
	} else if (strcmp(n, "/") == 0) {
		int tos1 = eps(s); //do we have to free?
		int tos2 = eps(s);
		int *n = malloc(sizeof(int));
		*n = tos1/tos2;
		dict_node *dn = create_dict_node("add_num", n, number, NULL); //change name later? (with like format string or something)
		push_stack(s, dn);
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
		int tos1 = eps(s); //do we have to free?
		int tos2 = eps(s);
		int *n = malloc(sizeof(int));
		*n = tos1==tos2;
		dict_node *dn = create_dict_node("add_num", n, number, NULL); //change name later? (with like format string or something)
	} else if (strcmp(n, "IMMEDIATE") == 0) {
		d->head->node_type = immediate;
	} else if (strcmp(n, "ENTER_IMMEDIATE") == 0) {
		*immediate_b = true;
	} else if (strcmp(n, "EXIT_IMMEDIATE") == 0) {
		*immediate_b = false;
	} else if (strcmp(n, "CREATE") == 0) {
		char *string;
		string = get_word();
		int *v = malloc(sizeof(int) * 1); //allocate variable space
		push_word(d, string, v, data);
	} else if (strcmp(n, "@") == 0) {
		//idk I shouldn't need anything for now (maybe just clone it and switch type to
		//number but like what else? maybe something to do with arrays)
	} else if (strcmp(n, "!") == 0) { 
		dict_node *tos1 = pop_stack(s);
		int *n = tos1->data;
		int *tos2 = malloc(sizeof(int));
		*tos2 = eps(s);
		tos1->data = tos2; //maybe? (makes sense to me)
	} else {
		printf("default word called that has not been implemented\n");
	}
}

void add_default_words(dictionary *d)
{
	enum node_type nt = code;
	void *data = NULL; //do I have to allocate (data should be empty? but in real forth this is a machine code whatever)
	push_word(d, ".", data, nt); //maybe using the same data is causing this error
	push_word(d, "EMIT", data, nt);
	push_word(d, ".s", data, nt);
	push_word(d, "+", data, nt);
	push_word(d, "-", data, nt);
	push_word(d, "*", data, nt);
	push_word(d, "/", data, nt);
	push_word(d, "@", data, nt);
	push_word(d, "!", data, nt);
	push_word(d, "DOES>", data, nt);
	push_word(d, ":", data, nt);
	push_word(d, ";", data, immediate);
	push_word(d, "IMMEDIATE", data, nt);
	push_word(d, "ENTER_IMMEDIATE", data, immediate);
	push_word(d, "EXIT_IMMEDIATE", data, nt); //not immediate because we should be in immediate mode at the time
	push_word(d, "CREATE", data, nt);
	push_word(d, "!", data, nt);
	push_word(d, "@", data, nt);
}
