#include "header_files/declarations.h"

void printClosestPoints(PairedPoints pairedPoints) {
	printf("\nThe closest paired points:\n");
	printf("x: %d, y: %d\n", pairedPoints.p1.x, pairedPoints.p1.y);
	printf("x: %d, y: %d\n", pairedPoints.p2.x, pairedPoints.p2.y);
	printf("distance: %f\n", pairedPoints.distance);
}