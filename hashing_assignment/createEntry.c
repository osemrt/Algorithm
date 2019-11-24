#include "header_files/declarations.h"

//Creates an empty entry with filePath and fileName
Entry* createEntry(char* filePath, char* fileName) {
	Entry* entry = (Entry*)createArrayFromHeap(ENTRY, 1);
	entry->status = OCCUPIED;
	entry->hashNode = (HashNode*)createArrayFromHeap(HASH_NODE, 1);
	entry->hashNode->filePath = filePath;
	entry->hashNode->fileName = fileName;
	return entry;
}