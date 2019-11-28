#include "header_files/declarations.h"

//A function to read a file path 
//and store them to points[] in a proper manner
Samples getSamplesFileFromUser() {

	//================================================================//
	//Reading samples.txt path from the user						  //
	FILE* fp;														  //
	char* samplesFilePath = (char*)createArrayFromHeap(CHAR, 300);	  //
	do {															  //
																	  //
		printf("Drag and drop samples.txt\n");						  //
		scanf("%s", samplesFilePath);								  //
																	  //
		fp = fopen(samplesFilePath, "r");							  //
		if (fp == NULL) {											  //
			clearScreen();											  //
			printf("Could not open file: %s\n", samplesFilePath);	  //
		}															  //
																	  //
	} while (fp == NULL);											  //
	//================================================================//


	Samples samples;

	//================================================================//
	//Getting samples.txt file path									  //
	char* tmp;														  //
	char* str = (char*)createArrayFromHeap(CHAR, 300);				  //
	strcpy(str, samplesFilePath);									  //		 
	tmp = releaseUnusedSpace(str);									  //
	samples.samplesPath = tmp;										  //
	//================================================================//


	//================================================================//  
	//rid of the file name to get 									  //
	//the root directory path of samples.txt						  //
	int k = strlen(samplesFilePath);								  //
																	  //
	while (samplesFilePath[k] != '\\')								  //
		k--;														  //
	samplesFilePath[k] = '\0';										  //
	char* rootDirectory = releaseUnusedSpace(samplesFilePath);		  //
	samples.rootDirectory = rootDirectory;							  //
	//================================================================// 



	//================================================================//
	//Reading all file names in samples.txt							  //
	int i = 0;														  //
	char* dummy;													  //
	char* filePath;													  //
																	  //
	File* file;														  //
																	  //
	while (fgets(str, 100, fp) != NULL) {							  //
		file = (File*)createArrayFromHeap(REGULAR_FILE, 1);			  //
		// to rid of \n												  //
		if (str[strlen(str) - 1] == '\n')							  //
			str[strlen(str) - 1] = '\0';							  //
																	  //
		file->fileName = releaseUnusedSpace(str);					  //
		dummy = (char*)createArrayFromHeap(CHAR, 300);				  //
		dummy[0] = '\0';											  //
		strcat(dummy, rootDirectory);								  //
		strcat(dummy, "\\");										  //
		strcat(dummy, file->fileName);								  //
																	  //
		file->filePath = releaseUnusedSpace(dummy);					  //
		free(dummy);												  //
		samples.files[i] = file;									  //
		i++;														  //
	}																  //
	//================================================================//



	//"i" now holds the total file count
	samples.count = i;


	free(samplesFilePath);
	free(str);
	fclose(fp);

	return samples;

}