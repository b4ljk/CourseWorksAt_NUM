#include "processheader.h"
#include <stdlib.h>

void printMatrix(int n, int m, int matrix[n][m]) {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      printf("%d\t", matrix[i][j]);
    }
    printf("\n");
  }
  printf("--------------------------\n");
}

void process2() {
  int n, m;
  n = rand() % 10;
  m = rand() % 10;
  int matrix1[n][m];
  int matrix2[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      matrix1[i][j] = rand() % 100;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      matrix2[i][j] = rand() % 100;
    }
  }
  printf("MATRIX1\n");
  printMatrix(n, m, matrix1);
  printf("MATRIX2\n");
  printMatrix(n, m, matrix2);
  printf("RESULT\n");
  int i, j;
  int result[n][m];
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      result[i][j] = matrix1[i][j] + matrix2[i][j];
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      printf("%d\t", result[i][j]);
    }
    printf("\n");
  }
}