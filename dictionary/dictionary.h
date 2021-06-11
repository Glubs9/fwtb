#ifndef DICTIONARY
#define DICTIONARY

#include <stdbool.h>
#include "CONSTANTS.h"

//building the forth dictionary via a linked list
//might be able to modularize this a bit but it works for now

enum node_type {code = 0, data = 1, number = 2, immediate = 3};

typedef struct dict_node {
	struct dict_node *prev;
	char name[MAX_NAME_LENGTH];
	void *data; //if code this is a list of dict_nodes if data then whatever it is
	enum node_type node_type; //bad name?
} dict_node;

//might not be necersarry
typedef struct dictionary {
	dict_node *head;
} dictionary;

dictionary* init_dict();
void push_word(dictionary *dict, char name[MAX_NAME_LENGTH], void *data, enum node_type nt);
dict_node* search_dict(dictionary *dict, char *name);
void print_dict(dictionary *d);

#endif
