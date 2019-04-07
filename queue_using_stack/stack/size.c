#include "../declarations.h"

/**
*	Returns the number of the elements in the stack
*	@param STACK* stack holds the address of the stack
*	@return '0' if there is no element in the stack, otherwise a non-zero value.
*/

int size(STACK* stack) {

	if (!isEmpty(stack))
		return stack->top + 1;
	else
		return 0;
}