#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_COUNT 256

#define INT 0
#define CHAR 1
#define STRING 2

typedef struct {
	char* fileNames[MAX_FILE_COUNT];
	char* filePath;
	int count;
}Samples;
