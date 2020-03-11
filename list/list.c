#include "../snake.h"

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
	nodo->prev = NULL;
	if(list->head == NULL && list->last == NULL) {
		list->head = nodo;
		list->last = nodo;
		return list;
	}
	else {
		iterator = list->last;
		nodo->prev = list->last;
		list->last->next = nodo;
		list->last = nodo;
	}
	return list;
}

nodo* remove_nodo(list* list, Paddle* pad) {
	if(pad == NULL)
		return NULL;
	nodo* it = list->head;
	nodo* returnValue = NULL;
	nodo* appoggio = NULL;
	//se il nodo da eliminare è il primo
	if(equals_paddle(it->pad, pad)) {
		returnValue = (nodo*)malloc(sizeof(nodo));
		returnValue = it;
		list->head = it->next;
		list->head->prev = NULL;
		it->next = NULL;
		it->prev = NULL;
		return returnValue;
	}
	while(it != NULL) {
		if(!equals_paddle(it->pad, pad)) {
			appoggio = it;
			it = it->next;
		} else {
			returnValue = (nodo*)malloc(sizeof(nodo));
			returnValue = it;
			appoggio->next = it->next;
			it->next->prev = appoggio;
			return returnValue;
		}
	}
	return returnValue;
}

nodo* get_nodo(list* list, Paddle* pad) {
	if(pad == NULL)
		return NULL;
	nodo* iterator = list->head;
	while(iterator!=NULL) {
		if(!equals_paddle(iterator->pad, pad)) {
			iterator = iterator->next;
		} else {
			return iterator;
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