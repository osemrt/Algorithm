#include "header_files/declarations.h"

//A function to read a file path 
//and store them to points[] in a proper manner
Samples getSamplesFileFromUser() {


	FILE* fp;
	char* filePath = (char*)createArrayFromHeap(200, CHAR);
	do {

		printf("Drag and drop samples file\n");
		scanf("%s", filePath);

		fp = fopen(filePath, "r");
		if (fp == NULL) {
			//CSI[2J clears screen, 
			//CSI[H moves the cursor to top-left corner
			printf("\x1B[2J\x1B[H");
			printf("Could not open file: %s\n", filePath);
		}

	} while (fp == NULL);

	Samples samples;

	int i = 0;
	char* str[100];
	while (fgets(str, 100, fp) != NULL) {
		samples.fileNames[i] = releaseUnusedSpace(str);
		i++;
	}

	//"i" holds the total file count
	samples.count = i;

	//rid of the file name 
	//to find the root directory path
	int k = strlen(filePath);
	while (filePath[k] != '\\')
		k--;
	filePath[k] = '\0';
	filePath = releaseUnusedSpace(filePath);
	samples.filePath = filePath;

	fclose(fp);

	return samples;

}