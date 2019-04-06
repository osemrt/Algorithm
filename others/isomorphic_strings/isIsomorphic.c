#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isIsomorphic(char* s, char* t) {

	int i; int n = strlen(s);
	int arr1[256] = { 0 };
	int arr2[256] = { 0 };

	for (i = 0; i < n; i++) {

		if (arr1[s[i]] != arr2[t[i]])
			return 0;

		arr1[s[i]] = i + 1;
		arr2[t[i]] = i + 1;

	}

	return 1;

}

int main() {

	printf("\n%d", isIsomorphic("honor", "honey"));
	printf("\n%d", isIsomorphic("paper", "title"));
	printf("\n%d", isIsomorphic("egg", "add"));
	
	scanf("\n");
	return 0;
}
