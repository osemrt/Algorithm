#include "header_files/declarations.h"

//A utility function to print points[]
void printPoints(Point* points, int N) {

	printf("     x  |    y  \n");
	printf("------------------\n");
	for (int i = 0; i < N; i++) {
		printf("%4d:  %4d  |  %4d\n", i, points[i].x, points[i].y);
	}

}