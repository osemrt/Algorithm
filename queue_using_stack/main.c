#include "declarations.h"

int main() {


	clear(&stack1);
	clear(&stack2);

	enQueue(1);
	enQueue(2);
	enQueue(3);
	enQueue(4);
	enQueue(5);
	enQueue(6);

	deQueue();
	deQueue();
	deQueue();
	deQueue();
	deQueue();
	deQueue();
	deQueue();


	return 0;
}