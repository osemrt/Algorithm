#include "header_files/declarations.h"

void showMenu() {

	Samples samples;
	File file;
	int choice;
	int index;
	do
	{
		printf("\n\n");
		printf("\tMENU");
		printf("\n------------------------------\n");
		printf("1:Add Samples.txt");
		printf("\n2:Add a regular file");
		printf("\n3:Print hash table");
		printf("\n4:Exit");
		printf("\n------------------------------\n");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:

			clearScreen();
			samples = getSamplesFileFromUser();
			int tableSize = calculateTableSize(samples.count);
			ht_create(tableSize);
			addSamplesToHashTable(samples);


			break;
		case 2:

			clearScreen();
			file = getFileFromUser();
			index = addFileToHashTable(file.filePath, file.fileName);

			if (index != SAME) {
				addFileNameToSamples(samples.samplesPath, file.fileName);
				copyFileToDirectory(samples.rootDirectory, file);
			}
			

			break;		
		case 3:

			clearScreen();
			ht_print();

			break;
		case 4:
			exit(0);
			break;
		default:
			printf("Invalid Input. Please Enter valid Input.\n\n ");
		}
	} while (choice != 4);

	return 0;
}



