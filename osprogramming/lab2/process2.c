#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct PCB {
  int process_id;      // Process ID
  int priority;        // Process Priority
  int state;           // Process State
  int process_counter; // Process counter value
  // Add other fields as necessery
};

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

void matrixAddition(int n, int m, int matrix1[n][m], int matrix2[n][m]) {
  int i, j;
  int result[n][m];
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      result[i][j] = matrix1[i][j] + matrix2[i][j];
    }
  }
  printMatrix(n, m, result);
}
int main() {
  int n, m;
  while (1) {
    if (getchar() == 27) {
      printf("ESC key pressed. Program stopped.\n");
      break;
    }
    scanf("%d %d", &n, &m);
    srand(time(NULL));
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
    matrixAddition(n, m, matrix1, matrix2);
  }
  return 0;
}