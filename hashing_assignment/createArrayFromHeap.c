#include "header_files/declarations.h"

//A function to allocate memory in the heap in the desired manner
//and if it is not created then it ends the program
void* createArrayFromHeap(int TYPE, int size) {

	void* arr;
	switch (TYPE)
	{
	case INT:
		arr = (int*)malloc(sizeof(int) * size);
		break;
	case CHAR:
		arr = (char*)malloc(sizeof(char) * size);
		break;
	case STRING:
		arr = (char**)malloc(sizeof(char*) * size);
		break;

	case ENTRY:
		arr = (Entry*)malloc(sizeof(Entry) * size);
		break;

	case HASH_TABLE:
		arr = (HashTable*)malloc(sizeof(HashTable) * size);
		break;

	case HASH_NODE:
		arr = (HashNode*)malloc(sizeof(HashNode) * size);
		break;

	case REGULAR_FILE:
		arr = (File*)malloc(sizeof(File) * size);
		break;

	default:
		arr = (void*)malloc(size);
		break;
	}

	if (arr == NULL) {
		printf("An error has occurred while creating the array!\n");
		exit(1);
	}

	return arr;

}