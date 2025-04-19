#include <stdlib.h>
#include <stdio.h>

#define ARRAY_SQUARE 2
#define ARRAY_RECT 3

void matrixAddition(int result[][ARRAY_SQUARE], int matrix1[][ARRAY_SQUARE]) {
  // Using the known dimensions of the arrays
  for(int i = 0; i < ARRAY_SQUARE; i++) {
    for (int j = 0; j < ARRAY_SQUARE; j++) {
    result[i][j] += matrix1[i][j];
    }
  }
}

void scalarMult(int result[][ARRAY_RECT], int constant) {
  for(int i = 0; i < ARRAY_SQUARE; i++) {
    for (int j = 0; j < ARRAY_RECT; j++) {
      result[i][j] *= constant;
    }
  }
}

void matrixMultiplication(int result[][ARRAY_SQUARE],
			  int matrix1[][ARRAY_RECT], int matrix2[][ARRAY_SQUARE]) {
  // Using default values of 2 and 3 for the test problem
  for (int i = 0; i < ARRAY_SQUARE; i++) {
    for (int j = 0; j < ARRAY_RECT; j++) {
      result[i][j] = 0;
      for (int k = 0; k < ARRAY_RECT; k++) {
	result[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }
}

void transpose(int input[][ARRAY_RECT], int result[][ARRAY_SQUARE]) {
  // Apologies if I'm supposed to pass the row and column sizes as parameters
  for(int i = 0; i < ARRAY_RECT; i++) {
    for (int j = 0; j < ARRAY_SQUARE; j++) {
      result[i][j] = input[j][i];
    }
  }
}

int main() {
  int rowsA, colsA;
  int rowsB, colsB;
  int rowsC, colsC;
  // Matrix A initialization
  printf("Input size of A:\n");
  printf("Input number of rows: ");
  scanf("%d", &rowsA);
  printf("Input number of columns: ");
  scanf("%d", &colsA);
  int A[rowsA][colsA];
  printf("Input values of A:\n");
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      printf("Input value at [%d][%d]: ", i, j);
      scanf("%d", &A[i][j]);
    }
  }
  // Matrix B initialization
  printf("Input size of B:\n");
  printf("Input number of rows: ");
  scanf("%d", &rowsB);
  printf("Input number of columns: ");
  scanf("%d", &colsB);
  int B[rowsB][colsB];
  printf("Input values of B:\n");
  for (int i = 0; i < rowsB; i++) {
    for (int j = 0; j < colsB; j++) {
      printf("Input value at [%d][%d]: ", i, j);
      scanf("%d", &B[i][j]);
    }
  }
  // Matrix C initialization
  printf("Input size of C:\n");
  printf("Input number of rows: ");
  scanf("%d", &rowsC);
  printf("Input number of columns: ");
  scanf("%d", &colsC);
  int C[rowsC][colsC];
  printf("Input values of C:\n");
  for (int i = 0; i < rowsC; i++) {
    for (int j = 0; j < colsC; j++) {
      printf("Input value at [%d][%d]: ", i, j);
      scanf("%d", &C[i][j]);
    }
  }
  // Matrix D initialization
  int D[rowsB][rowsC];
  
  // Calculate the test equation
  // Scalar multiplication
  int scalar;
  printf("Input scalar: ");
  scanf("%d", &scalar);
  scalarMult(B, scalar);
  // Transposition
  int tempMatrix[colsC][rowsC];
  transpose(C, tempMatrix);
  // Matrix multiplication
  matrixMultiplication(D, B, tempMatrix);
  // Matrix addition
  matrixAddition(D, A);

  printf("Equation results - elements of matrix D\n");
  for (int i = 0; i < rowsB; i++) {
    for(int j = 0; j < rowsC; j++) {
      printf("%d ", D[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}
