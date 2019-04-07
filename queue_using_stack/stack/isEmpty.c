#include "../declarations.h"

/**
*	Shows us to whether the stack is now empty or not
*	@param STACK* stack holds the address of the stack
*	@return TRUE for an empty stack otherwise FALSE
*/

int isEmpty(STACK* stack) {
	if (stack->top == -1)
		return TRUE;
	else
		return FALSE;
}
