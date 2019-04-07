#include "declarations.h"

int deQueue() {

	if (isEmpty(&stack1))
		return INT_MIN;

	return pop(&stack1);

}