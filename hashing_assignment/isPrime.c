#include "header_files/declarations.h"

//A function to check whether 
//the given number is a prime number or not
int isPrime(int num) {

	// Corner cases
	if (num <= 1)
		return FALSE;
	if (num <= 3)
		return TRUE;

	// This is checked so that we can skip 
	// middle five numbers in below loop
	if (num % 2 == 0 || num % 3 == 0)
		return FALSE;

	int i;
	for (i = 5; i * i <= num; i = i + 6)
		if (num % i == 0 || num % (i + 2) == 0)
			return FALSE;

	return TRUE;


}