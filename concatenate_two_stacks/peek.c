#include "declarations.h"

int peek() {
	if (!isEmpty(&stack2)) {
		return stack2.items[stack2.top];
	}
	else if (!isEmpty(&stack1)) {
		return stack1.items[stack1.top];
	}
	else {
		return INT_MIN;
	}
}