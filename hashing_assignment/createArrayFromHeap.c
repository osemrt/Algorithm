#include "header_files/declarations.h"

void* createArrayFromHeap(int size, int TYPE) {

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