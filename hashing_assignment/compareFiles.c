#include "header_files/declarations.h"

//A function to check whether 
//the contents of the two files are the same or not
int compareFiles(FILE* fp1, FILE* fp2) {

	// Move the file pointer to the start.
	rewind(fp1);
	rewind(fp2);

	char ch1;
	char ch2;

	do {
		ch1 = fgetc(fp1);
		ch2 = fgetc(fp2);

		if (ch1 != ch2)
			return FALSE;

	} while (ch1 != EOF && ch2 != EOF);


	return TRUE;

}