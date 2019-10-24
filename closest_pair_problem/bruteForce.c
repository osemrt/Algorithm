#include "header_files/declarations.h"

PairedPoints* bruteForce(Point* points, int left, int right) {

	int minDistance = INT_MAX;
	double calculatedDistance;
	PairedPoints* closestPaired = (PairedPoints*)malloc(sizeof(PairedPoints));

	for (int i = left; i <= right; i++) {
		for (int j = i + 1; j <= right; j++) {
			calculatedDistance = calculateDistance(points[i], points[j]);
			if (calculatedDistance < minDistance) {
				closestPaired->p1 = points[i];
				closestPaired->p2 = points[j];
				closestPaired->distance = calculatedDistance;
			}
		}
	}

	return closestPaired;

}