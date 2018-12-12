#include <stdio.h>
#include <stdlib.h>
#define FAIL -1

int generateNumber();
int* createArray(int);
void fillArray(int*, int);
void printArray(int*, int);
int partition(int*, int, int);
void quickSort(int*, int, int);
int binarySearch(int*, int, int, int);

void swap(int*, int*);

int main() {

	srand(time(NULL));

	int n = generateNumber();
	int* arr = createArray(n);
	fillArray(arr, n);
	printArray(arr, n);
	quickSort(arr, 0, n - 1);
	printArray(arr, n);
	int x = generateNumber();
	
	int status = binarySearch(arr, 0, n - 1, x);

	if (status == FAIL){ 
		printf("%d not found!", x); 
	}	
	else {
		printf("%d founded!", x);
	}

	return 0;
}

int generateNumber() {
	return (rand() % 40);
}

int* createArray(int n) {
	int* arr = (int*)malloc(n * sizeof(int));
	return arr;
}

void fillArray(int* arr, int n) {

	for (int i = 0; i < n; i++)
		arr[i] = generateNumber();

}

void printArray(int*arr, int n) {
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void quickSort(int* arr, int first, int last) {

	if (last > first) {
		int pivotIndex = partition(arr, first, last);
		quickSort(arr, first, pivotIndex - 1);
		quickSort(arr, pivotIndex + 1, last);
	}
}

int partition(int* arr, int first, int last) {
	int pivot = arr[last];
	int j = first;

	for (int i = first; i < last; i++) {
		if (arr[i] < pivot) {
			swap(&arr[i], &arr[j]);
			j++;
		}
	}
	
	swap(&arr[last], &arr[j]);

	return j;

}

int binarySearch(int* arr, int first, int last, int x) {

	if (last >= first) {
		int mid = (last + first) / 2;
		
		if (arr[mid] == x) {
			return mid;
		} else if (arr[mid] > x)
			return binarySearch(arr, first, mid - 1, x);
		else { //arr[mid] < x
			return binarySearch(arr, mid + 1, last, x);
		}
	}

	return FAIL;
}

void swap(int*a, int*b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
