#include <stdio.h>
#include "page1.h"
#include "page2.h"

void main() {
	page1* page1 = print_page1();
	page2* page2 = print_page2();
	printf("page1 -> %d; page2 -> %d.\n", page1->value, page2->value);
}