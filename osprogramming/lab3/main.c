#include "processheader.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef void (*process_function_t)();

process_function_t processes[] = {process1, process2, process3};
int num_processes = sizeof(processes) / sizeof(processes[0]);

void switch_processes(struct PCB *current_process, struct PCB *next_process) {
  printf("Switching from process %d to process %d\n",
         current_process->process_id, next_process->process_id);

  current_process->state = 0;         // Assuming 0 means "waiting"
  current_process->process_counter++; // Increment the process counter

  next_process->state = 1; // Assuming 1 means "running"
  next_process->process_counter++;

  processes[next_process->process_id - 1]();

  current_process = next_process;
}

int main() {
  // Create three PCBs for testing
  struct PCB process1 = {1, 1, 0, 0, 10};
  struct PCB process2 = {2, 2, 1, 0, 5}; // Assuming 0 means "not running"
  struct PCB process3 = {3, 3, 0, 0, 3};

  // Start with process 1
  struct PCB *current_process = &process1;

  // Run the processes randomly until all are done
  while (1) {
    // Pick a random process
    int next_process_id = rand() % num_processes + 1;
    struct PCB *next_process = NULL;
    switch (next_process_id) {
    case 1:
      next_process = &process1;
      break;
    case 2:
      next_process = &process2;
      break;
    case 3:
      next_process = &process3;
      break;
    }

    // If the process is not done, switch to it
    if (next_process->process_counter < next_process->time) {
      switch_processes(current_process, next_process);
    }

    // If all processes are done, exit
    if (process1.process_counter >= process1.time &&
        process2.process_counter >= process2.time &&
        process3.process_counter >= process3.time) {
      break;
    }
  }

  return 0;
}
