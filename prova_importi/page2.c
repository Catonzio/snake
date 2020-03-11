#include "page2.h"
#include <stdlib.h>

page2* print_page2() {
	page2* page = (page2*) malloc(sizeof(page2));
	page->value = 2;
	return page;
}