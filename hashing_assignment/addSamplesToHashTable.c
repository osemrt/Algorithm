#include "header_files/declarations.h"

void addSamplesToHashTable(Samples samples) {
	int i = 0;
	int N = samples.count;
	int index;
	for (i = 0; i < N; i++) {
		File* file = samples.files[i];
		index = addFileToHashTable(file->filePath, file->fileName);

		if (index != -1) {
			printf("\n\"%s\" was sucessfully added to HashTable...", file->fileName);
		}
		else {
			printf("\nAn error has occurred while adding \"%s\" to HashTable...", file->fileName);
		}
	}

}