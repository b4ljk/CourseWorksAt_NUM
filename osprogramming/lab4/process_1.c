#include "processheader.h"

void process1() {

  srand(time(NULL));
  int random = rand() % 100;
  int unsorted[random];
  for (int i = 0; i < random; i++) {
    unsorted[i] = rand() % 100;
  }

  int i, j;
  for (i = 0; i < random; i++) {
    for (j = i + 1; j < random; j++) {
      if (unsorted[i] > unsorted[j]) {
        int temp = unsorted[i];
        unsorted[i] = unsorted[j];
        unsorted[j] = temp;
      }
    }
  }
  for (i = 0; i < random; i++) {
    printf("%d\t", unsorted[i]);
  }
  printf("\n");
}