#include "list.h"
#include <stdio.h>
#include <stdlib.h>

void getNodo(list* list) {
	int x,y;
	printf("Inserire le coordinate del paddle da eliminare: \n");
	printf("x: ");
	scanf("%d", &x);
	printf("y: ");
	scanf("%d", &y);
	Paddle* pad = create_paddle(x, y);
	nodo* nodo = remove_nodo(list, pad);
	if(nodo != NULL) {
		print_paddle(pad);
		printf("\n");
	} else {
		printf("Nessun paddle con quelle coordinate.\n");
	}
	printf("nuova lista\n\n");
	print_list(list);
}

int main() {
	list* list = create_list();
	add_element(list, create_paddle(1,1));
	add_element(list, create_paddle(2,2));
	add_element(list, create_paddle(3,3));
	add_element(list, create_paddle(4,4));
	add_element(list, create_paddle(5,5));
	add_element(list, create_paddle(6,6));
	print_list(list);
	getNodo(list);

}