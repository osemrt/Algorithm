#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> 

//Constants are used to increase code readability 
//when handling function return values
#define TRUE 1
#define FALSE 0
#define SAME -2

//According to the given formula, we have to know 
//the number of added elements to the table.
//So, I assumed the number of files 
//in "samples.txt" is MAX_FILE_COUNT in the first read.
#define MAX_FILE_COUNT 256

//A constant used in stringToKey()
//to calculate the key of a string
#define PRIME 29

//Load factor value in the given formula
#define LOAD_FACTOR 0.6

//All constants in the below 
//are used in createArrayFromHeap() 
//to do not deal with malloc() return value
//if it returns NULL.
#define INT 0
#define CHAR 1
#define STRING 2
#define ENTRY 3
#define HASH_TABLE 4
#define HASH_NODE 5
#define REGULAR_FILE 6


//A structure for samples.txt
typedef struct Samples{
	//files in samples.txt
	struct File* files[MAX_FILE_COUNT];
	//the root directory of samples.txt
	char* rootDirectory;
	//samples.txt path (rootDirectory/samples.txt)
	char* samplesPath;
	//the number of files inside of samples.txt
	int count;
}Samples;

//Each file consists of a fileName and filePath
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