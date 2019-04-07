#include "../declarations.h"

/**
*	Shows us to whether the stack is now full or not
*	@param STACK* stack holds the address of the stack
*	@return TRUE for a full stack otherwise FALSE
*/

int isFull(STACK* stack) {

	if (stack->top == MAX_SIZE - 1)
		return TRUE;
	else
		return FALSE;

}

