#include "../declarations.h"

/**
*	Sets the stack top pointer to -1
*	@param STACK* stack holds the address of the stack
*/

void clear(STACK* stack) {
	stack->top = -1;
}