#include "header_files/declarations.h"

//Creates a hash table with the given size
void ht_create(int size) {

	int i;
	hashTable = (HashTable*)createArrayFromHeap(HASH_TABLE, 1);
	hashTable->arr = (Entry*)createArrayFromHeap(ENTRY, size);
	hashTable->size = size;

	for (i = 0; i < hashTable->size; i++) {
		hashTable->arr[i].status = EMPTY;
		hashTable->arr[i].hashNode = (HashNode*)createArrayFromHeap(HASH_NODE, 1);
	}

}

//Adds the given entry to the table as described in the assignment
int ht_put(FILE* fp1, unsigned long long int key, Entry* entry) {

	int i = 0;
	int index = hash(key, i);
	Entry currentEntry = hashTable->arr[index];

	printf("KEY: %ull, ", key);
	printf("INDEX: %d, ", index);
	printf("%s...", entry->hashNode->fileName);


	while (currentEntry.status == OCCUPIED) {

		printf("\nA collision occurred -> %s : %s", entry->hashNode->fileName, currentEntry.hashNode->fileName);

		char* filePath = currentEntry.hashNode->filePath;
		FILE* fp2 = fopen(filePath, "r");
		if (fp2 == NULL) {
			printf("\n%s could not be added to the table...\n", filePath);
			return -1;
		}
		else {

			if (compareFiles(fp1, fp2) == FALSE) {
				i++;
				index = hash(key, i);
				currentEntry = hashTable->arr[index];
				fclose(fp2);
			}
			else {
				fclose(fp2);
				char* newFileName = entry->hashNode->fileName;
				char* currentFileName = currentEntry.hashNode->fileName;
				printf("\n\"%s\" was already added as \"%s\"...\n", newFileName, currentFileName);
				return SAME;
			}

		}
	}

	if (currentEntry.status == EMPTY) {
		hashTable->arr[index] = *entry;
		return index;
	}

}


//Prints all hash table
void ht_print() {

	if (hashTable != NULL) {
		printf("\nPrinting hashTable...\n");
		int i;
		for (i = 0; i < hashTable->size; i++) {
			if (hashTable->arr[i].status == OCCUPIED) {
				printf("%d: (%s)\n", i, hashTable->arr[i].hashNode->fileName);
			}
			else if (hashTable->arr[i].status == EMPTY) {
				printf("%d: %s\n", i, "");
			}
			else {
				printf("%d: %s\n", i, "DELETED!");
			}
		}

	}
	else {
		printf("HashTable is not created yet!\n");
	}




}










