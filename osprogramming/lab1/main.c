#include "processheader.h"
#include <stdio.h>

int main() {
  int n;
  char str[1000];
  while (1) {
    printf("Enter Process :\t");
    scanf("%d", &n);
    switch (n) {
    case 1: {
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
      break;
    }
    case 2: {
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
      break;
    }
    case 3: {
      printf("PROCESS 3 : \n");
      printf("Enter a string: ");
      scanf("%s", str);
      lettersInString(str);
      break;
    }
    case 0:
      return 0;

    default:
      printf("Wrong 1:SORT 2:MATRIX 3:CHARS 0:EXIT\n");
    }
  }

  return 0;
}