#include "declarations.h"

int isEmpty(STACK* stack) {
	if (stack->top == -1)
		return TRUE;
	else
		return FALSE;
}