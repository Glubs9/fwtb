#ifndef USERCODE
#define USERCODE

typedef struct user_code {
	int size;
	dict_node **words;
} user_code;

extract_user_code(dict_node *dn);
push_user_code(user_code *c, dict_node *w);

#endif
