#include "header_files/declarations.h"

//A utility function to print points[]
void printPoints(Point* points, int N) {
	int i;
	printf("--------------------------\n");
	printf("         x   |    y     \n");
	printf("--------------------------\n");
	for (i = 0; i < N; i++) {
		printf("%4d:  %4d  |  %4d\n", i, points[i].x, points[i].y);
	}
	printf("--------------------------\n");

}