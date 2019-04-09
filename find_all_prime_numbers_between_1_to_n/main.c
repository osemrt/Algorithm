#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE 1
#define FALSE 0


int* primeNumbers(int n);
int* createArray(int size);

int main() {

	srand(time(NULL));
	int n = rand() % 256;

	printf("n: %d", n);
	primeNumbers(n);

	return;
}

int* primeNumbers(int n) {

	int* arr = createArray(n + 1);

	for (int i = 4; i <= n; i += 2)
		arr[i] = FALSE;

	arr[2] = TRUE;

	for (int i = 1; i <= n; i += 2)
		arr[i] = TRUE;

	int limit = sqrt(n);

	for (int i = 3; i <= limit; i += 2) {

		if (arr[i] == TRUE) {

			for (int j = i * i; j <= n; j += i)
				arr[j] = FALSE;

		}

	}


	printf("\n[ ");
	if (arr != NULL) {
		for (int i = 2; i <= n; i++) {
			if (arr[i])
				printf("%d ", i);
		}
	}
	printf("]\n");

	arr;

}

int* createArray(int size) {
	int* arr = (int*)malloc(sizeof(int) * size);
	return arr;
}