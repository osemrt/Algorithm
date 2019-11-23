#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> 

#define INT 0
#define CHAR 1
#define STRING 2
#define ENTRY 3
#define HASH_TABLE 4
#define HASH_NODE 5
#define REGULAR_FILE 6

#define TRUE 1
#define FALSE 0
#define SAME -2

#define MAX_FILE_COUNT 256
#define PRIME 29
#define LOAD_FACTOR 0.6

typedef struct Samples{
	//files in samples.txt
	struct File* files[MAX_FILE_COUNT];
	//the root directory of samples.txt
	char* rootDirectory;
	//sample.txt path (rootDirectory/samples.txt)
	char* samplesPath;
	//the number of filenames inside of samples.txt
	int count;
}Samples;

typedef struct File {
	char* fileName;
	char* filePath;
}File;

enum entryStatus { EMPTY, DELETED, OCCUPIED };

typedef struct HashNode {
	char* fileName;
	char* filePath;
}HashNode;

typedef struct Entry {
	struct HashNode* hashNode;
	enum entryStatus status;
}Entry;

typedef struct {
	struct Entry* arr;
	int size;
}HashTable;


HashTable* hashTable;