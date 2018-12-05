#include <stdio.h>
#include <stdlib.h>

int generateNumber();
void fillArray(int*, int);
void printArray(int*, int);

void quickSort(int*, int, int);
int partition(int*, int, int);
void swap(int*, int*);

int main() {

	srand(time(NULL));

	int n = generateNumber();
	int* arr = malloc(n * sizeof(int));

	fillArray(arr, n);
	printArray(arr, n);
	quickSort(arr, 0, n - 1);
	printArray(arr, n);

	return 0;

}

void fillArray(int* arr, int n) {
	for (int i = 0; i < n; i++)
		arr[i] = generateNumber();

}

int generateNumber() {
	return rand() % 50;

}

void printArray(int* arr, int n) {
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);

	printf("\n");
}

void quickSort(int*arr, int first, int last) {
	if (last>first) {
		int pivotIndex = partition(arr, first, last);		
		quickSort(arr, first, pivotIndex - 1);
		quickSort(arr, pivotIndex + 1, last);
	}

}

int partition(int*arr, int first, int last) {
	int pivot = arr[last];
	int j = first;	

	for (int i = first; i < last; i++){
		if (arr[i] < pivot) {	
			swap(&arr[j], &arr[i]);
			j++;
		}
	}
	
	swap(&arr[j], &arr[last]);

	return j;

}

void swap(int*a, int*b) {	
	int temp = *a;
	*a = *b;
	*b = temp;
}
