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

void sortElements(int arr[], int n) {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      if (arr[i] > arr[j]) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
  for (i = 0; i < n; i++) {
    printf("%d\t", arr[i]);
  }
  printf("\n");
}

int main() {
  int n;
  while (1) {
    scanf("%d", &n);
    srand(time(NULL));
    int unsorted[n];
    for (int i = 0; i < n; i++) {
      unsorted[i] = rand() % 100;
    }
    sortElements(unsorted, n);
  }
  return 0;
}