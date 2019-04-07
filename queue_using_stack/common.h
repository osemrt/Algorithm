#pragma once

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5
#define TRUE 1
#define FALSE 0

typedef struct {
	int items[MAX_SIZE];
	int top;
}STACK;

STACK stack1, stack2;