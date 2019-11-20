#include "header_files/declarations.h"

char* releaseUnusedSpace(char* str) {

	int i = 0;
	while (str[i++] != NULL)
		i++;

	//Total character count
	int count = i;
	char* newStr = (char*)createArrayFromHeap(count + 1, CHAR);
	strcpy(newStr, str);

	return newStr;
}