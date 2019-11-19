#include "header_files/declarations.h"


//A function to find a lower distance than min={minPPL.distance, minPPR.distance}
//in the split region
PairedPoints lookNearOfMid(Point split[], int size, float minDistance) {

	//Sorting the split points according to the y-axis
	quickSort(split, 0, size - 1, y_axis);
	PairedPoints closestPairedPoints;

	//Initializing a default value for closestPairedPoints.distance 
	//because we will check whether a min distance is found or not
	closestPairedPoints.distance = FLT_MAX;

	//A float variable to store calculateDistance() return value
	float calculatedDistance;

	//loop variables
	int i, j;

	for (i = 0; i < size; i++) {
		j = i + 1;

		//Checking split points after sorting them according to the y-axis
		//If the distance of the both them is more than minDistance, we must skip this pair
		//because being the closest pair for this pair is not possible
		//Also, looking only at most six points from the current point is enough
		//to check whether it can be a part of a closest pair or not 
		while (j < size && abs(split[i].y - split[j].y) < minDistance && j < i + 7) {
			calculatedDistance = calculateDistance(split[i], split[j]);
			if (calculatedDistance < minDistance) {
				closestPairedPoints.p1 = split[i];
				closestPairedPoints.p2 = split[j];
				closestPairedPoints.distance = calculatedDistance;
				minDistance = calculatedDistance;
			}
			j++;
		}
	}

	return closestPairedPoints;

}
