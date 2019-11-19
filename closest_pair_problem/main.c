#include "header_files/declarations.h"


int main(int argv, char** argc) {

	srand(time(NULL));
	Point points[MAX];

	//Reading points from the user
	int N = readPointsFromFile(points);

	//Printing all points
	printf("\nPoints\n");
	printPoints(points, N);

	//Sorting the points according to the x-axis
	quickSort(points, 0, N - 1, x_axis);

	//Calling findClosestPair() to find the closest pair
	PairedPoints closestPairedPoints = findClosestPair(points, 0, N - 1);

	//Printing the closest pair to the screen
	printClosestPoints(closestPairedPoints);


	return 0;
}
