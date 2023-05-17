#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void process1();
void process2();
void process3();
// void process1(int arr[], int n);
// void process2(int n, int m, int matrix1[n][m], int matrix2[n][m]);
// void process3(char *str);

struct PCB {
  int process_id;      // Process ID
  int priority;        // Process Priority
  int state;           // Process State
  int process_counter; // Process counter value
  int time;            // Process time
};