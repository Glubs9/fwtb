#include "CONSTANTS.h"

//building the forth dictionary via a linked list
//might be able to modularize this a bit but it works for now

//few options for this as it has to be generic
	//issue is we store not only code but also user variables
	//so i was thinking either an enum describing the void* type
	//or a union describing all the types separately
	//i might go for the void* and the enum
	//but this is subject to change

enum node_type {code = 0, data = 1};

typedef struct dict_node {
	struct dict_node *prev;
	char name[MAX_NAME_LENGTH];
	void* data;
	enum node_type node_type; //bad name?
} dict_node;
