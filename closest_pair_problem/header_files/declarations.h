#pragma once

#include "common.h"

Point* generateRandomPoints(int N, int max);
int eliminateSamePoints(Point* arr, int N);
void printPoints(Point* points, int N);
void quickSort(Point arr[], int first, int last, int axis);
int partition(Point arr[], int first, int last, int axis);
int swap_x_axis(Point arr[], int index1, int index2);
int swap_y_axis(Point arr[], int index1, int index2);
PairedPoints* bruteForce(Point* points, int left, int right);
float calculateDistance(Point p1, Point p2);
PairedPoints lookNearOfMid(Point split[], int size, float minDistance);
PairedPoints findClosestPair(Point* points, int left, int right);
int readPointsFromFile(Point points[]);
void printClosestPoints(PairedPoints pairedPoints);