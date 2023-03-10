#include "header.h"
#include <stdio.h>
int main() {
  char str[1000];
  printf("PROCESS 1 : \n");
  int n;
  printf("Enter the size of array: ");
  scanf("%d", &n);
  printf("Enter the elements of array: ");
  int *arr = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  sortElements(arr, n);
  printf("PROCESS 2 : \n");
  printf("Enter rows and columns of matrix: ");
  int n1, m1;
  scanf("%d %d", &n1, &m1);
  int matrix1[n1][m1];
  int matrix2[n1][m1];
  printf("Enter matrix1\n");
  for (int i = 0; i < n1; i++) {
    for (int j = 0; j < m1; j++) {
      scanf("%d", &matrix1[i][j]);
    }
  }
  printf("Enter matrix2\n");
  for (int i = 0; i < n1; i++) {
    for (int j = 0; j < m1; j++) {
      scanf("%d", &matrix2[i][j]);
    }
  }
  matrixAddition(n1, m1, matrix1, matrix2);
  printf("PROCESS 3 : \n");
  printf("Enter a string: ");
  scanf("%s", str);
  lettersInString(str);
  return 0;
}