#pragma once

#include "common.h"

Samples getSamplesFileFromUser();
File getFileFromUser();
void* createArrayFromHeap(int TYPE, int size);
char* releaseUnusedSpace(char* str);
unsigned long int calculateFileKey(FILE* fp);
unsigned long long int stringToKey(char* str);
int ht_put(FILE* fp1, unsigned long int key, Entry* entry);
void ht_create(int size);
void ht_print();
int isPrime(int num);
int calculateTableSize(int n);
int hash(unsigned long long int key, int i);
void showMenu();
Entry* createEntry(char* filePath, char* fileName);
int addFileToHashTable(char* filePath, char* fileName);
void ht_create(int size);
void addSamplesToHashTable(Samples samples);
int addFileNameToSamples(char* samplesPath, char* fileName);
int copyFileToDirectory(char* rootDirectory, File file);
void clearScreen();
int compareFiles(FILE* fp1, FILE* fp2);
