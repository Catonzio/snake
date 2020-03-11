#include "page1.h"
#include <stdlib.h>

page1* print_page1() {
	page1* page = (page1*) malloc(sizeof(page1));
	page->value = 1;
	return page;
}