#include "header_files/declarations.h"

int addFileNameToSamples(char* samplesPath, char* fileName) {
	FILE* fp = fopen(samplesPath, "a");

	if (fp != NULL) {
		fprintf(fp, "\n", fileName);
		fprintf(fp, "%s", fileName);
		fclose(fp);
		printf("%s is added to samples.txt...\n", fileName);
		return TRUE;
	}
	else {
		printf("An error has occurred while appending %s to samples.txt.\n", fileName);
		return FALSE;
	}
}