#include "header_files/declarations.h"

//A function to add a file name to samples.txt
int addFileNameToSamples(char* samplesPath, char* fileName) {
	FILE* fp = fopen(samplesPath, "a");

	if (fp != NULL) {
		fprintf(fp, "\n", fileName);
		fprintf(fp, "%s", fileName);
		fclose(fp);
		printf("\n%s is added to samples.txt...\n", fileName);
		return TRUE;
	}
	else {
		printf("An error has occurred while appending %s to samples.txt.\n", fileName);
		return FALSE;
	}
}