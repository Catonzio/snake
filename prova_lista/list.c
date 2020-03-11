#include "list.h"
#include <stdlib.h>
#include <stdio.h>

list* create_list() {
	list* list =  malloc(sizeof(list));
	list->head = NULL;
	list->last = NULL;
	return list;
}

int equals_nodes(nodo* n1, nodo* n2) {
	return equals_paddle(n1->pad, n2->pad);
}

list* add_element(list* list, Paddle* pad) {
	nodo* iterator = malloc(sizeof(nodo));
	nodo* nodo =  malloc(sizeof(nodo));
	nodo->pad = pad;
	nodo->next = NULL;
	if(list->head == NULL && list->last == NULL) {
		list->head = nodo;
		list->last = nodo;
		return list;
	}
	else {
		iterator = list->last;
		list->last->next = nodo;
		list->last = nodo;
	}
	return list;
}

nodo* remove_nodo(list* list, Paddle* pad) {
	nodo* it = list->head;
	nodo* returnValue = NULL;
	nodo* appoggio = NULL;
	//se il nodo da eliminare è il primo
	if(equals_paddle(it->pad, pad)) {
		returnValue = (nodo*)malloc(sizeof(nodo));
		returnValue = it;
		list->head = it->next;
		return returnValue;
	}
	while(it != NULL) {
		if(!equals_paddle(it->pad, pad)) {
			appoggio = it;
			it = it->next;
		} else {
			printf("equals_paddle\n");
			returnValue = (nodo*)malloc(sizeof(nodo));
			returnValue = it;
			appoggio->next = it->next;
			return returnValue;
		}
	}
	return returnValue;
}

nodo* get_nodo(list* list, Paddle* pad) {
	nodo* iterator = list->head;
	nodo* appoggio =  NULL;
	while(iterator!=NULL) {
		if(!equals_paddle(iterator->pad, pad)) {
			iterator = iterator->next;
		} else {
			appoggio = iterator;
			return appoggio;
		}
	}
}

int list_length(list* list) {
	nodo* it = list->head;
	int count = 0;
	while(it != NULL) {
		count++;
		it = it->next;
	}
	return count;
}

void print_list(list* list) {
	nodo* it = malloc(sizeof(nodo));
	it = list->head;
	while(it != NULL) {
		printf(" .");
		print_paddle(it->pad);
		printf(".\n");
		it = it->next;
	}
}