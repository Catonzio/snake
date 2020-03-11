#include "../snake.h"

void print_nodo(int num, int isPrev, nodo* nodo) {
	if(nodo == NULL)
		printf("Nodo%d NULL", num);
	else {
		if(isPrev == 1) {
			printf("Prev%d: ", num);
		} else {
			printf("Del%d: ", num);
		}
		print_paddle(nodo->pad);
	}
	printf("\n");
}

int main() {
	list* list = create_list();
	//aggiungo gli elementi alla lista
	Paddle* pad1 = create_paddle(1,1,'1');
	Paddle* pad2 = create_paddle(1,2,'2');
	Paddle* pad3 = create_paddle(1,3,'3');
	add_element(list, pad1);
	add_element(list, pad2);
	add_element(list, pad3);
	//stampo la lista
	print_list(list);
	printf("\n");
	//prendo il primo nodo (prev del 2)
	nodo* prev1 = get_nodo(list, pad2)->prev;
	print_nodo(1, 1, prev1);
	//prendo il secondo nodo (prevo del 3)
	nodo* prev2 = get_nodo(list, pad3)->prev;
	print_nodo(2, 1, prev2);
	//prendo il nodo 0 (prev dell'1) -> NULL
	nodo* prev0 = get_nodo(list, pad1)->prev;
	print_nodo(0, 1, prev0);
	//provo ad eliminare un nodo e verifico i predecessori
	nodo* del2 = remove_nodo(list, pad2);
	print_nodo(2, 0, del2);

	nodo* prev1_2 = get_nodo(list, pad3)->prev;
	print_nodo(12, 1, prev1_2);

	nodo* del1 = remove_nodo(list, pad1);
	print_nodo(1, 0, del1);

	nodo* prev0_1 = get_nodo(list, pad3)->prev;
	print_nodo(0, 1, prev0_1);

	//alla fine, ristampo la lista
	printf("\n");
	print_list(list);

}
