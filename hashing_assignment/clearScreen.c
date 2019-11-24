#include "header_files/declarations.h"

//Clears the command line screen by using a regular expression
//It is used in showMenu()
void clearScreen() {
	//CSI[2J clears screen, 
	//CSI[H moves the cursor to top-left corner
	printf("\x1B[2J\x1B[H");
}