#include <stdio.h>
#include <stdlib.h>	
#include <string.h>

#define TRUE  1
#define FALSE 0


int** createMatrix(int, int);
void fillMatrix(int**, int, int);
void printMatrix(int**, int, int);
int generateNum();

void findIslands(int**, int, int, int**);
void DFS(int**, int, int, int**, int, int);
int dr[] = { 0,1,-1 };
int dc[] = { 0,1,-1 };

int islandCounter;

int main() {

	srand(time(NULL));
	int row = generateNum();
	int col = generateNum();

	int** matrix = createMatrix(row, col);
	fillMatrix(matrix, row, col);
	printMatrix(matrix, row, col);

	int** resultMatrix = createMatrix(row, col);
	findIslands(matrix, row, col, resultMatrix);
	printMatrix(resultMatrix, row, col);	
	
	return 0;
}

int generateNum() {
	return rand() % 10 + 1;
}

int** createMatrix(int row, int col) {
	int** matrix = malloc(row * sizeof(int*));
	for (int i = 0; i < row; i++)
		matrix[i] = calloc(col, sizeof(int));
	return matrix;
}

void fillMatrix(int** matrix, int row, int col) {
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			matrix[i][j] = generateNum() % 2;
}

void printMatrix(int** matrix, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			printf("%2d ", matrix[i][j]);
		printf("\n");
	}
	printf("\n");
}


void findIslands(int** matrix, int row, int col, int** resultMatrix) {
	for (int i = 0; i < row; i++) 
		for (int j = 0; j < col; j++) 
			if (matrix[i][j] == TRUE) {
				islandCounter++;
				DFS(matrix, i, j, resultMatrix, row, col);

			}
}

void DFS(int** matrix, int i, int j, int** resultMatrix, int row, int col) {

	resultMatrix[i][j] = islandCounter;
	matrix[i][j] = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			if ((i + dr[i] < row) && (i + dr[i] >= 0) && (j + dc[j] < col) && (j + dc[j] >= 0))
				DFS(matrix, i + dr, j + dc, resultMatrix, row, col);
		}


}
