#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define COLUMN 4
#define ROW 4
#define	SEED1 4
#define SEED2 8
#define HIGH 14



/* fillGrid populates the array with random integers */

void fillGrid(int grid[][COLUMN], int seed, int high)
{
	srand(seed);
	for (int i = 0; i < ROW; i++)
		for (int k = 0; k < COLUMN; k++)
			grid[i][k] = rand() % high;
}

/* prints the grid supplied as an argument */

void printGrid(int grid[][COLUMN])
{
	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COLUMN; k++)
			printf("%5d", grid[i][k]);
		printf("\n\n");
	}
	puts("");
}

/* computes the product of two elements */

int dotProduct(int num1, int num2)
{
	return num1*num2;
}

int main(void)
{	
	int gridA[ROW][COLUMN] = { };
	int gridB[ROW][COLUMN] = { };
	int gridC[ROW][COLUMN] = { };
	fillGrid(gridA, SEED1, HIGH);
	fillGrid(gridB, SEED2, HIGH);
	

	/* print initial matrices */
	puts("Matrix 1---");
	printGrid(gridA);
	puts("Matrix 2---");
	printGrid(gridB);

	/* 
	 * This loop is for the matrix multiplication. This allows us to compute the dot product by taking
	 * independant elements in a row and multiplying them by their equivalent element in a column. In 
	 * the inner loop, for a given row, we're adding all of the products together and storing the 
	 * result in gridC at the appropriate location. We repeat this process for every column in gridB, 
	 * finally printing the result.
	 */

	for (int h = 0; h < ROW; h++)
		for (int i = 0; i < ROW; i++)
			for (int j = 0; j < COLUMN; j++)
				gridC[h][i] += dotProduct(gridA[h][j], gridB[j][i]);			

	
	puts("Final Matrix---");
	printGrid(gridC);

			
	return 0;
}
