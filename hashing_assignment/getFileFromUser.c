#include "header_files/declarations.h"

//A function to add a file after creating the table
File getFileFromUser() {

	//================================================================//
	//Reading the file path											  //
	FILE* fp;														  //
	char* filePath = (char*)createArrayFromHeap(CHAR, 200);			  //
	do {															  //
																	  //
		printf("Drag and drop your file\n");						  //
		scanf("%s", filePath);										  //
																	  //
		fp = fopen(filePath, "r");									  //
		if (fp == NULL) {											  //
			clearScreen();											  //
			printf("Could not open file: %s\n", filePath);			  //
		}															  //
																	  //
	} while (fp == NULL);											  //
	//================================================================//

	File file;
	file.filePath = releaseUnusedSpace(filePath);

	//Getting the file name from the given file path
	char* token, * last;
	last = token = strtok(filePath, "\\");
	while (token != NULL) {
		last = token;
		token = strtok(NULL, "\\");
	}

	file.fileName = releaseUnusedSpace(last);
	free(filePath);

	fclose(fp);

	return file;

}