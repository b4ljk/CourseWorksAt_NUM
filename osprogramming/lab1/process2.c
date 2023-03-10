#include "header.h"
void matrixAddition(int n, int m, int matrix1[n][m], int matrix2[n][m]) {
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