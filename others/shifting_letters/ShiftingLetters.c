#include <stdio.h>

char* shiftingLetters(char* S, int* shifts, int shiftsSize) {

	int i;
	long int totalShift = 0;

	char* W = (char*)malloc(sizeof(char)*(strlen(S)+1));
	strcpy(W, S);

	printf("%s\n%s\n", W, S);

	for (i = shiftsSize - 1; i >= 0; i--) {

		totalShift = totalShift + shifts[i];

		W[i] = (W[i] + totalShift - ('a' % 26)) % 26 + 'a';

	}

	return W;

}

int main() {

	
	int arr1[] = { 3,5,9 };
	
	printf("%s", shiftingLetters("abc", arr1, 3));
	
	scanf("\n");
	return 0;
}
