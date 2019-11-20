#include "header_files/declarations.h"

char* releaseUnusedSpace(char* str) {

	int i = 0;
	while (str[i++] != NULL)
		i++;

	//Total character count
	int count = i;
	char* newStr = (char*)createArrayFromHeap(CHAR, count + 1);
	strcpy(newStr, str);

	return newStr;
}