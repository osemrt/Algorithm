#include "declarations.h"

int isFull(STACK* stack) {
	if (stack->top == MAX_SIZE - 1)
		return TRUE;
	else
		return FALSE;
}