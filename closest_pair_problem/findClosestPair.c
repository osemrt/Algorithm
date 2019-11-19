#include "header_files/declarations.h"


PairedPoints findClosestPair(Point* points, int left, int right) {

	//the number of elements in the subarray
	int numOfPoints = (right - left) + 1;

	//Termination condition for the recursive function
	//Calling brute force If the subarray has 3 or fewer members
	if (numOfPoints <= 3)
		return *bruteForce(points, left, right);

	//Finding the middle point
	int mid = (left + right) / 2;

	//minimum paired points on the left of the mid (minPPL)
	PairedPoints minPPL = findClosestPair(points, left, mid);
	//minimum paired points on the right of the mid (minPPL)
	PairedPoints minPPR = findClosestPair(points, mid + 1, right);

	//defining minimum paired point(minPP) 
	//after finding minPPL and minPPR
	PairedPoints minPP;
	if (minPPL.distance < minPPR.distance)
		minPP = minPPL;
	else
		minPP = minPPR;

	//Stores all element their distance is less than minPP.distance to points[mid]
	Point split[MAX];
	int j = 0;
	for (int i = left; i <= right; i++) {
		if (abs(points[i].x - points[mid].x) < minPP.distance) {
			split[j] = points[i];
			j++;
		}
	}

	//Now, we inspect split pair points
	PairedPoints PPM = lookNearOfMid(split, j, minPP.distance);

	//
	if (PPM.distance != FLT_MAX)
		return PPM;
	else
		return minPP;

}