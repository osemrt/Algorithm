#include "declarations.h"

int pop() {
	if (!isEmpty(&stack2)) {
		--stack2.top;
		return stack2.items[stack2.top + 1];
	}
	else if(!isEmpty(&stack1)) {
		--stack1.top;
		return stack1.items[stack1.top + 1];
	}
	else {
		printf("Stack Underflow!\n");
		return INT_MIN;
	}
}