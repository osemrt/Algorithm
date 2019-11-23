#include "header_files/declarations.h"

int addFileToHashTable(char* filePath, char* fileName) {
	FILE* fp = fopen(filePath, "r");
	if (fp == NULL) {
		printf("%s could not be added to the table...\n", filePath);
		return -1;
	}
	else {
		unsigned long int fileKey = calculateFileKey(fp);
		Entry* entry = createEntry(filePath, fileName);
		int index = ht_put(fp, fileKey, entry);
		fclose(fp);
		return index;
	}
}