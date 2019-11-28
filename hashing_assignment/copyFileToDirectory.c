#include "header_files/declarations.h"

//A function to copy the file to the desired directory
int copyFileToDirectory(char* rootDirectory, File file) {

	FILE* fp1, * fp2;
	char filePath[300] = "";
	char c;

	strcat(filePath, rootDirectory);
	strcat(filePath, "\\");
	strcat(filePath, file.fileName);

	fp1 = fopen(file.filePath, "r");
	if (fp1 == NULL) {
		printf("An error has occurred while copying the file to the main directory.\n");
		return FALSE;
	}

	fp2 = fopen(filePath, "w");
	if (fp2 == NULL) {
		printf("An error has occurred while copying the file to the main directory.\n");
		return FALSE;
	}

	c = fgetc(fp1);
	while (c != EOF)
	{
		fputc(c, fp2);
		c = fgetc(fp1);
	}

	fclose(fp1);
	fclose(fp2);

	printf("%s is copied to the main directory.\n", file.fileName);

	return TRUE;

}