#include "declarations.h"

int push(int data) {
	if (!isFull(&stack1)) {
		stack1.items[++stack1.top] = data;
		return data;
	}
	else if (!isFull(&stack2)) {
		stack2.items[++stack2.top] = data;
		return data;
	}
	else {
		printf("Stack Overflow!\n");
		return INT_MIN;
	}
}
