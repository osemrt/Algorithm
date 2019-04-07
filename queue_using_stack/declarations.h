#pragma once

#include "common.h"

int enQueue(int data);
int deQueue();

//Stack Functions
int isFull(STACK* stack);
int isEmpty(STACK* stack);
int pop(STACK* stack);
int peek(STACK* stack);
int size(STACK* stack);
int push(STACK* stack, int data);
void print(STACK* stack);
void clear(STACK* stack);