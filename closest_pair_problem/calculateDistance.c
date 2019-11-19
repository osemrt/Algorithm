#include "header_files/declarations.h"

//A utility function to find Euclidian distance 
//between two points
float calculateDistance(Point p1, Point p2) {
	int diffX = p1.x - p2.x;
	int diffY = p1.y - p2.y;
	return sqrt(pow(diffX, 2) + pow(diffY, 2));
}