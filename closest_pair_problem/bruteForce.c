#include "header_files/declarations.h"

PairedPoints* bruteForce(Point* points, int left, int right) {

	float minDistance = FLT_MAX;
	float calculatedDistance;
	PairedPoints* closestPaired = (PairedPoints*)malloc(sizeof(PairedPoints));
	closestPaired->distance = FLT_MAX;

	for (int i = left; i <= right-1; i++) {
		for (int j = i + 1; j <= right; j++) {
			calculatedDistance = calculateDistance(points[i], points[j]);
			if (calculatedDistance < minDistance) {
				closestPaired->p1 = points[i];
				closestPaired->p2 = points[j];
				closestPaired->distance = calculatedDistance;
				minDistance = calculatedDistance;
			}
		}
	}

	return closestPaired;

}