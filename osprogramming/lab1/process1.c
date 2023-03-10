#include "header.h"

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

void merge(int a[], int low, int high) {}

void mergeSrt(int a[], int low, int high) {
  int size = high - low;
  mergeSrt(a, low, high / 2);
  mergeSrt(a, low + size / 2, high);
  merge(a, low, high);
}