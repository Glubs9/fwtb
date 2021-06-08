#include "CONSTANTS.h"

//building the forth dictionary via a linked list
//might be able to modularize this a bit but it works for now

typedef struct dict_node {
	dict_node* prev;
	char name[MAX_NAME_LENGTH];
} dict_node;
