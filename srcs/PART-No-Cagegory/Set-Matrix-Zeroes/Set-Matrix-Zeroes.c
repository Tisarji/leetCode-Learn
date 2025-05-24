// 73. Set Matrix Zeroes
// Medium
// Topics
// Companies
// Hint
// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

// You must do it in place.

 

// Example 1:


// Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]
// Example 2:


// Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
// Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

// Constraints:

// m == matrix.length
// n == matrix[0].length
// 1 <= m, n <= 200
// -231 <= matrix[i][j] <= 231 - 1
 

// Follow up:

// A straightforward solution using O(mn) space is probably a bad idea.
// A simple improvement uses O(m + n) space, but still not the best solution.
// Could you devise a constant space solution?

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void	setZeroes(int **matrix, int matrixSize, int *matrixColSize)
{
	int row = matrixSize;
	int col = *matrixColSize;
	bool firstRowZero = false;
	bool firstColZero = false;

	for (int j = 0; j < col; j++) {
		if (matrix[0][j] == 0) {
			firstRowZero = true;
			break;
		}
	}

	for (int i = 0; i < row; i++) {
		if (matrix[i][0] == 0) {
			firstColZero = true;
			break;
		}
	}

	for (int i = 1; i < row; i++) {
		for (int j = 1; j < col; j++) {
			if (matrix[i][j] == 0) {
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	}

	for (int i = 1; i < row; i++) {
		for (int j = 1; j < col; j++) {
			if (matrix[i][0] == 0 || matrix[0][j] == 0) {
				matrix[i][j] = 0;
			}
		}
	}

	if (firstRowZero) {
		for (int j = 0; j < col; j++) {
			matrix[0][j] = 0;
		}
	}

	if (firstColZero) {
		for (int i = 0; i < row; i++) {
			matrix[i][0] = 0;
		}
	}
}

// int main(void)
// {
// 	int matrix[3][3] = {
// 		{1, 1, 1},
// 		{1, 0, 1},
// 		{1, 1, 1}
// 	};
// 	int *matrixPtr[3];
// 	for (int i = 0; i < 3; i++) {
// 		matrixPtr[i] = matrix[i];
// 	}
// 	int matrixColSize = 3;
// 	setZeroes(matrixPtr, 3, &matrixColSize);
// 	for (int i = 0; i < 3; i++) {
// 		for (int j = 0; j < 3; j++) {
// 			printf("%d ", matrix[i][j]);
// 		}
// 		printf("\n");
// 	}
// 	return 0;
// }
