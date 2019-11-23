#include "header_files/declarations.h"

int calculateTableSize(int n) {

	int tableSize = ceil(n / LOAD_FACTOR);

	while (!isPrime(tableSize)) {
		tableSize++;
	}

	return tableSize;
}