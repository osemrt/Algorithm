#include "../declarations.h"

/**
*	Decreases the stack top pointer by one
*	@param STACK* stack holds the address of the stack
*	@return INT_MIN to show the error while trying to pop the element, otherwise the popped value.
*/

int pop(STACK* stack) {

	if (!isEmpty(stack)) {
		--stack->top;
		return stack->items[stack->top + 1];
	}
	else {
		return INT_MIN;
	}

}