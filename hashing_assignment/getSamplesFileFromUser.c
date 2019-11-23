#include "header_files/declarations.h"

//A function to read a file path 
//and store them to points[] in a proper manner
Samples getSamplesFileFromUser() {


	FILE* fp;
	char* samplesFilePath = (char*)createArrayFromHeap(CHAR, 300);
	do {

		printf("Drag and drop samples.txt\n");
		scanf("%s", samplesFilePath);

		fp = fopen(samplesFilePath, "r");
		if (fp == NULL) {
			//CSI[2J clears screen, 
			//CSI[H moves the cursor to top-left corner
			printf("\x1B[2J\x1B[H");
			printf("Could not open file: %s\n", samplesFilePath);
		}

	} while (fp == NULL);

	Samples samples;
	char* tmp;


	//================================================================//
	//Getting samples.txt file path									  //
	char* str = (char*)createArrayFromHeap(CHAR, 300);				  //
	strcpy(str, samplesFilePath);									  //		 
	tmp = releaseUnusedSpace(str);									  //
	samples.samplesPath = tmp;										  //
	//================================================================//



	//================================================================  
	//rid of the file name 											   
	//to find the root directory path								   
	int k = strlen(samplesFilePath);

	while (samplesFilePath[k] != '\\')
		k--;
	samplesFilePath[k] = '\0';
	char* rootDirectory = releaseUnusedSpace(samplesFilePath);
	samples.rootDirectory = rootDirectory;
	//================================================================ 



	//================================================================
	int i = 0;
	char* dummy;
	char* filePath;

	File* file;

	while (fgets(str, 100, fp) != NULL) {
		file = (File*)createArrayFromHeap(REGULAR_FILE, 1);
		// to rid of \n
		if (str[strlen(str) - 1] == '\n')
			str[strlen(str) - 1] = '\0';
		file->fileName = releaseUnusedSpace(str);
		dummy = (char*)createArrayFromHeap(CHAR, 300);
		dummy[0] = '\0';
		strcat(dummy, rootDirectory);
		strcat(dummy, "\\");
		strcat(dummy, file->fileName);

		file->filePath = releaseUnusedSpace(dummy);
		free(dummy);
		samples.files[i] = file;
		i++;
	}
	//================================================================



	//"i" now holds the total file count
	samples.count = i;

	free(samplesFilePath);
	free(str);
	fclose(fp);

	return samples;

}