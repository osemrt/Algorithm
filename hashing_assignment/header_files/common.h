#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INT 0
#define CHAR 1
#define STRING 2
#define ENTRY 3
#define HASH_TABLE 4
#define HASH_NODE 5

#define MAX_FILE_COUNT 256

typedef struct {
	char* fileNames[MAX_FILE_COUNT];
	char* filePath;
	int count;
}Samples;

enum entryStatus { EMPTY, DELETED, OCCUPIED };

typedef struct HashNode {
	int key;
	int value;
}HashNode;

typedef struct Entry {
	struct HashNode* hashNode;
	enum entryStatus status;
}Entry;

typedef struct {
	struct Entry* arr;
	int size;
}HashTable;


