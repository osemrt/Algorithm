#pragma once

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 5

typedef struct {
	int items[MAX_SIZE];
	int top;

}STACK;

STACK stack1, stack2;

