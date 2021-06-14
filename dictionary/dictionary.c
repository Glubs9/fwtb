#include <stdlib.h>
#include <stdio.h> //only for debugging, remove later
#include <string.h>
#include <errno.h>

#include "dictionary.h"
#include "CONSTANTS.h"

dictionary* init_dict()
{
	dictionary *ret = malloc(sizeof(dictionary));
	ret->head = (dict_node*) -1;
	return ret;
}

//feels a little weird? and unecersarry?
void push_word(dictionary *dict, char name[MAX_NAME_LENGTH], void *data, enum node_type nt)
{
	dict_node *dn = malloc(sizeof(dict_node));
	strcpy(dn->name, name); //strcpy?
	dn->data = data;
	dn->node_type = nt;
	dn->prev = dict->head;
	dict->head = dn;
}

//recursive call for search_dict
dict_node* _search_dict(dict_node *dn, char *name)
{
	if (dn == (dict_node*) -1) { //end of linked list
		//i feel i should separate this logic out into a separate function
		dict_node *dn = malloc(sizeof(dict_node)); //create and return numeric word
		strcpy(dn->name, name);
		int n;
		if (name[0] == 39) { //if input is a character i.e: name == "'*'"
			n = name[1];
		} else { //if input is a straight number
			//feels like i should move this logic
			char *p; //wtf?
			n = strtol(name, &p, 10);
			if (name == p) {
				printf("ERROR: WORD NOT FOUND %s\n", name);
				errno = 5; //check value is the right value
				exit(EXIT_FAILURE);
			}
		}
		int *n2 = malloc(sizeof(int));
		(*n2) = n; //weird funky memory stuff because c
		dn->data = n2;
		dn->node_type = number;
		return dn;
	} else if (strcmp(dn->name, name) == 0) {
		return dn;
	} else {
		_search_dict(dn->prev, name);
	}
}

//this kind of thing makes me feel that the dictionary object is a bit unecersarry
dict_node* search_dict(dictionary *dict, char *name)
{
	return _search_dict(dict->head, name);
}

//not printing?
void _print_dict(dict_node *dn)
{
	if (dn == (dict_node*) -1) {
		printf("\n");
	} else {
		printf("%s ", dn->name);
		_print_dict(dn->prev);
	}
}

void print_dict(dictionary *d)
{
	_print_dict(d->head);
}
