#include "header_files/declarations.h"

//A function to remove duplicated elements 
//in points[] and returns new size(N) for points[]
//unused memory could be freed after shifting
int eliminateSamePoints(Point* arr, int N) {

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; ) {

			//increment j variable after shifting
			if ((arr[i].x == arr[j].x) && (arr[i].y == arr[j].x)) {

				for (int k = j; k < N; k++) {
					arr[k] = arr[k + 1];
				}

				N--;

			}
			else {
				j++;
			}


		}
	}

	return N;

}