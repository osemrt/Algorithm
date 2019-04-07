#include "../declarations.h"

/**
*	Prints all stack elements in top-down fashion
*	@param STACK* stack holds the address of the stack
*/

void print(STACK* stack) {


	printf("\n-----------\n");
	if (!isEmpty(stack)) {
		int top = stack->top;
		while (top >= 0) {
			printf("%d\n", stack->items[top--]);
		}		
	}
	else {
		printf("Empty Stack!\n");
	}
	printf("-----------\n");


}