#include "header_files/declarations.h"

//Calculates the hash table size after reading samples.txt
//in the proper manner
int calculateTableSize(int n) {

	int tableSize = ceil(n / LOAD_FACTOR);
	while (!isPrime(tableSize)) {
		tableSize++;
	}

	return tableSize;
}