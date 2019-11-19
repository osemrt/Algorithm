#include "header_files/declarations.h"

void quickSort(Point arr[], int first, int last, int axis) {

	if (last > first) {
		int pivotIndex = partition(arr, first, last, axis);
		quickSort(arr, first, pivotIndex - 1, axis);
		quickSort(arr, pivotIndex + 1, last, axis);
	}

}

int partition(Point arr[], int first, int last, int axis) {

	int j = first;

	//order by x-axis
	if (axis == x_axis) {

		int i;
		int pivot = arr[last].x;

		for (i = first; i < last; i++) {
			if (arr[i].x < pivot) {
				swap_x_axis(arr, j, i);
				swap_y_axis(arr, j, i);
				j++;
			}
		}

		swap_x_axis(arr, j, last);
		swap_y_axis(arr, j, last);
	}
	//order by y-axis
	else {
		
		int i;
		int pivot = arr[last].y;

		for (i = first; i < last; i++) {
			if (arr[i].y < pivot) {
				swap_x_axis(arr, j, i);
				swap_y_axis(arr, j, i);
				j++;
			}
		}

		swap_x_axis(arr, j, last);
		swap_y_axis(arr, j, last);
	}

	
	return j;
}

int swap_x_axis(Point arr[], int index1, int index2) {

	if (index1 < 0 || index2 < 0)
		return FALSE;

	int temp = arr[index1].x;
	arr[index1].x = arr[index2].x;
	arr[index2].x = temp;

	return TRUE;
}

int swap_y_axis(Point arr[], int index1, int index2) {

	if (index1 < 0 || index2 < 0)
		return FALSE;

	int temp = arr[index1].y;
	arr[index1].y = arr[index2].y;
	arr[index2].y = temp;

	return TRUE;
}