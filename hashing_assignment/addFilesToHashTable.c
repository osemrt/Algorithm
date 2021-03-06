#include "header_files/declarations.h"

//Adds a file to the table in the proper manner
int addFileToHashTable(char* filePath, char* fileName) {
	FILE* fp = fopen(filePath, "r");
	if (fp == NULL) {
		printf("\n%s could not be added to the table...\n", filePath);
		return -1;
	}
	else {
		unsigned long long int fileKey = calculateFileKey(fp);
		Entry* entry = createEntry(filePath, fileName);
		int index = ht_put(fp, fileKey, entry);
		fclose(fp);
		return index;
	}
}
