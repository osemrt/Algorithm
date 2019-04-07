#include "declarations.h"

int enQueue(int data) {

	if (isFull(&stack1))
		return INT_MIN;

	while (!isEmpty(&stack1)) {
		push(&stack2, pop(&stack1));
	}

	push(&stack1, data);

	while (!isEmpty(&stack2)) {
		push(&stack1, pop(&stack2));
	}

	return data;

}