#include "header_files/declarations.h"

//A function returns the key value of a file 
//by calculating the key of each word in the file
unsigned long long int calculateFileKey(FILE* fp) {

	unsigned long long int sum = 0;
	char str[100];
	unsigned long long int key = 0;
	while (fgets(str, 100, fp) != NULL) {
		key = stringToKey(str);
		sum = sum ^ key;
	}

	rewind(fp);

	return sum;

}