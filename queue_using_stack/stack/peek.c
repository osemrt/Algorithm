#include "../declarations.h"

/**
*	Returns the most top element in the stack
*	@param STACK* stack holds the address of the stack
*	@return the most top element, otherwise INT_MIN to show the error
*/

int peek(STACK* stack) {

	if (!isEmpty(stack))
		return stack->items[stack->top];
	else
		return INT_MIN;

}