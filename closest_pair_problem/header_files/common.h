#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define x_axis 1
#define y_axis 0

#define MAX 2000 //for split array


typedef struct {
	int x;
	int y;
}Point;

typedef struct {
	Point p1;
	Point p2;
	float distance;
}PairedPoints;

