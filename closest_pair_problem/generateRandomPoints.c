#include "header_files/declarations.h"

//A function that returns a random point array 
//that will be used to test the algorithm.
Point* generateRandomPoints(int N) {

	//Crating an point array with "N" size
	Point* points = (Point*) malloc(sizeof(Point) * N);
	if (points == NULL) {
		printf("An error has occurred while allocating memory!\n");
		exit(0);
	}

	//Populate the newly created point array
	//with random numbers
	//Also, subtract N/2 to allow negative points
	for (int i = 0; i < N; i++) {
		points[i].x = (rand() % N) - (N / 2);
		points[i].y = (rand() % N) - (N / 2);
	}

	return points;

}