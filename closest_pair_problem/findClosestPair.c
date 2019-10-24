#include "header_files/declarations.h"

PairedPoints findClosestPair(Point* points, int left, int right) {

	int numOfPoints = (right - left) + 1;
	if (numOfPoints <= 3)
		return *bruteForce(points, left, right);

	int mid = (left + right) / 2;

	PairedPoints minPPL = findClosestPair(points, left, mid);
	PairedPoints minPPR = findClosestPair(points, mid + 1, right);

	PairedPoints minPP;
	if (minPPL.distance < minPPR.distance)
		minPP = minPPL;
	else
		minPP = minPPR;

	Point split[MAX];
	int j = 0;
	for (int i = left; i <= right; i++) {
		if (abs(points[i].x - points[mid].x) < minPP.distance) {
			split[j] = points[i];
			j++;
		}
	}

	PairedPoints PPM = lookNearOfMid(split, j, minPP.distance);

	if (PPM.distance != INT_MIN)
		return PPM;
	else
		return minPP;

}