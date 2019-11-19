#include "header_files/declarations.h"

//A function to read a file path 
//and store them to points[] in a proper manner
int readPointsFromFile(Point points[]) {

	FILE* fp;
	char filePath[200];
	do {

		printf("Drag and drop your file here!\n");
		scanf("%s", filePath);

		fp = fopen(filePath, "r");
		if (fp == NULL) {
			//CSI[2J clears screen, 
			//CSI[H moves the cursor to top-left corner
			printf("\x1B[2J\x1B[H");
			printf("Could not open file: %s\n", filePath);
		}

	} while (fp == NULL);


	char str[20];
	int counter = 0;
	while (fgets(str, 20, fp) != NULL) {
		points[counter].x = atoi(strtok(str, " "));
		points[counter].y = atoi(strtok(NULL, " "));
		counter++;
	}

	fclose(fp);

	return counter;

}