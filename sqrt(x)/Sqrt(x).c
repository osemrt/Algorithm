#include <stdio.h>
#include <stdlib.h>

int mySqrt(int x) {
	
	int i = 0;
	int flag = 1;	
	unsigned int x2;

	while (i < 50000 & flag) {
		x2 = i * i;
		if (x2 > x)
			flag = 0;
		i++;

	}

	return i - 2;

}

int main() {

	srand(time(NULL));
	int num = rand() % 2147483647;

	printf("%d : %d", num, mySqrt(num));

	return 0;
}
