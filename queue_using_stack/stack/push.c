#include "../declarations.h"

/**
*	Adds an element to the top of the stack
*	@param STACK* stack holds the address of the stack
*	@param int data an integer we want to add to the stack.
*	@return INT_MIN to show the error while trying to add the element, otherwise the pushed value.
*/

int push(STACK* stack, int data) {

	if (!isFull(stack)) {
		stack->items[++stack->top] = data;
		return data;
	}
	else
	{
		return INT_MIN;
	}

}