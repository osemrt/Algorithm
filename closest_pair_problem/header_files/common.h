#pragma once

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define x_axis 1
#define y_axis 0


typedef struct {
	int x;
	int y;
}Point;

typedef struct {
	Point p1;
	Point p2;
}PairedPoints;

