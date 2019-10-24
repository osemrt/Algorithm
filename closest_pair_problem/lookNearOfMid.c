#include "header_files/declarations.h"

PairedPoints lookNearOfMid(Point split[], int size, int minDistance) {

	quickSort(split, 0, size - 1, y_axis);
	printPoints(split, size);
	PairedPoints closestPairedPoints;
	closestPairedPoints.distance = INT_MIN; //to control

	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (abs(split[i].y - split[j].y) < minDistance) {
				closestPairedPoints.p1 = split[i];
				closestPairedPoints.p2 = split[j];
				closestPairedPoints.distance = calculateDistance(split[i], split[j]);
			}
			

		}
	}

	return closestPairedPoints;

}