#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "../dictionary/dictionary.h"
#include "../int_stack/int_stack.h"

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
		strcmp(n, "DOES>") == 0
	);
}

void execute_default_word(dict_node *node, int_stack *s)
{
	//wish switch statement worked on strings
	char *n = node->name;
	if (strcmp(n, ".") == 0) {
		printf("%d\n", pop_int_stack(s));
	} else if (strcmp(n, ".s") == 0) {
		print_int_stack(s);
	} else if (strcmp(n, "+") == 0) {
		int tos1 = pop_int_stack(s);
		int tos2 = pop_int_stack(s);
		push_int_stack(s, tos1+tos2);
	} else if (strcmp(n, "-") == 0) {
		int tos1 = pop_int_stack(s);
		int tos2 = pop_int_stack(s);
		push_int_stack(s, tos1-tos2);
	} else if (strcmp(n, "*") == 0) {
		int tos1 = pop_int_stack(s);
		int tos2 = pop_int_stack(s);
		push_int_stack(s, tos1*tos2);
	} else if (strcmp(n, "/") == 0) {
		int tos1 = pop_int_stack(s);
		int tos2 = pop_int_stack(s);
		push_int_stack(s, tos1/tos2);
	} else {
		printf("default word called that has not been implemented\n");
	}
}

void add_default_words(dictionary *d)
{
	enum node_type nt = code;
	void *data = NULL; //do I have to allocate (data should be empty? but in real forth this is a machine code whatever)
	push_word(d, ".", data, nt, false); //maybe using the same data is causing this error
	push_word(d, ".s", data, nt, false);
	push_word(d, "+", data, nt, false);
	push_word(d, "-", data, nt, false);
	push_word(d, "*", data, nt, false);
	push_word(d, "/", data, nt, false);
	push_word(d, "@", data, nt, false);
	push_word(d, "!", data, nt, false);
	push_word(d, "CREATE", data, nt, false);
	push_word(d, "DOES>", data, nt, false);
}
