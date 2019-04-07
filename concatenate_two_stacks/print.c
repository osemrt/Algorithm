#include "declarations.h"

void print() {

	int size;
	
	size = stack2.top;
	while (size >= 0) {
		printf("%d -> ", stack2.items[size--]);
	}


	size = stack1.top;
	while (size >= 0) {
		printf("%d -> ", stack1.items[size--]);
	}

	printf("\n");
}