#include "header_files/declarations.h"

void clearScreen() {
	//CSI[2J clears screen, 
	//CSI[H moves the cursor to top-left corner
	printf("\x1B[2J\x1B[H");
}