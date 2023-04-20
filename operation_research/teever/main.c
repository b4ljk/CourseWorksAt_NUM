#include <stdio.h>

int sum(int arr[], int len) {
  int s = 0;
  for (int i = 0; i < len; i++) {
    s += arr[i];
  }
  return s;
}

int main() {
  int col, row, temp;
  int cols[100], rows[100], matrix[100][100], result[100][100];
  int i, j, Z = 0;

  printf("enter the number of Ai\n");
  scanf("%d", &col);

  printf("enter the numbers for Ai\n");
  for (i = 0; i < col; i++) {
    scanf("%d", &temp);
    cols[i] = temp;
  }

  printf("enter the number of Bj\n");
  scanf("%d", &row);

  printf("enter the numbers for Bj\n");
  for (i = 0; i < row; i++) {
    scanf("%d", &temp);
    rows[i] = temp;
  }

  printf("enter the matrix\n");
  for (i = 0; i < col; i++) {
    for (j = 0; j < row; j++) {
      scanf("%d", &temp);
      matrix[i][j] = temp;
    }
  }

  if (sum(cols, col) != sum(rows, row)) {
    rows[row] = sum(cols, col) - sum(rows, row);
    for (i = 0; i < col; i++) {
      matrix[i][row] = 0;
    }
    row++;
  }

  for (i = 0; i < col; i++) {
    for (j = 0; j < row; j++) {
      if (cols[i] == 0 || rows[j] == 0) {
        result[i][j] = -1;
      } else {
        temp = (cols[i] < rows[j]) ? cols[i] : rows[j];
        result[i][j] = temp;
        cols[i] -= temp;
        rows[j] -= temp;
        if (cols[i] == 0 && rows[j] == 0) {
          result[i][j + 1] = 0;
        }
      }
    }
  }

  for (i = 0; i < col; i++) {
    for (j = 0; j < row; j++) {
      printf("%d\t", result[i][j]);
    }
    printf("\n");
  }

  for (i = 0; i < col; i++) {
    for (j = 0; j < row; j++) {
      if (result[i][j] == -1) {
        continue;
      }
      Z += result[i][j] * matrix[i][j];
    }
  }

  printf("Z = %d\n", Z);

  return 0;
}
