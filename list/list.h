#ifndef LIST_H
#define LIST_H

struct nodo {
	Paddle* pad;
	struct nodo* next;
	struct nodo* prev;
};
typedef struct nodo nodo;

struct list {
	nodo* head;
	nodo* last;
};
typedef struct list list;

list* create_list();
list* add_element(list* list, Paddle* pad);
nodo* get_nodo(list* list, Paddle* pad);
int equals_nodes(nodo* n1, nodo* n2);
void print_list(list* list);
nodo* remove_nodo(list* list, Paddle* pad);
int list_length(list* list);

#endif