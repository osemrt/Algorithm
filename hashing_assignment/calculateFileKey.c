#include "header_files/declarations.h"

//A function returns the key value of a file 
//by calculating the key of each word in the file
unsigned long int calculateFileKey(FILE* fp) {

	unsigned long int sum = 0;
	char* str[100];
	int key;
	while (fgets(str, 100, fp) != NULL) {
		key = stringToKey(str);
		sum = sum ^ key;
	}

	rewind(fp);

	return sum;

}