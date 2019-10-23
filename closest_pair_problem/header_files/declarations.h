#pragma once

#include "common.h"

Point* generateRandomPoints(int N);
int eliminateSamePoints(Point* arr, int N);
void printPoints(Point* points, int N);
void quickSort(Point arr[], int first, int last, int axis);
int partition(Point arr[], int first, int last, int axis);
int swap(int arr[], int index1, int index2);