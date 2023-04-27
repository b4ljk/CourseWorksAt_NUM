#include "DS.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MEMSIZE 2560

struct Memory {
  int is_allocated;
  int process_id;
  int start_address;
  int end_address;
};
typedef struct Memory Memory;
Queue current_queue;

Memory memory[MEMSIZE];

typedef void (*process_function_t)();
process_function_t processes[] = {process1, process2, process3};
int num_processes = sizeof(processes) / sizeof(processes[0]);

void switch_processes(struct PCB **current_process, struct PCB **next_process) {
  printf("Switching from process %d to process %d\n",
         (*current_process)->process_id, (*next_process)->process_id);
  sleep(1);

  (*current_process)->state = 0;         // Assuming 0 means "waiting"
  (*current_process)->process_counter++; // Increment the process counter

  (*next_process)->state = 1; // Assuming 1 means "running"
  (*next_process)->process_counter++;

  processes[(*next_process)->process_id - 1]();

  *current_process = *next_process;
}

int allocate_memory(struct PCB *process) {
  int continous_memory = 0;
  int start_address = 0;
  int end_address = 0;
  for (int i = 0; i < MEMSIZE; i++) {
    if (memory[i].is_allocated == 0) {
      continous_memory++;
      if (continous_memory == process->memory) {
        start_address = i - process->memory + 1;
        end_address = i;
        break;
      }
    } else {
      continous_memory = 0;
    }
  }
  if (start_address == 0 && end_address == 0) {
    printf("Not enough memory for process %d\n", process->process_id);
    return 0;
  }
  process->start_address = start_address;
  process->end_address = end_address;
  for (int i = start_address; i <= end_address; i++) {
    memory[i].is_allocated = 1;
    memory[i].process_id = process->process_id;
    memory[i].start_address = start_address;
    memory[i].end_address = end_address;
  }
  printf("Allocated memory for process %d\n", process->process_id);
  return 1;
}

int deallocate_memory(struct PCB *process) {
  for (int i = process->start_address; i <= process->end_address; i++) {
    memory[i].is_allocated = 0;
    memory[i].process_id = 0;
    memory[i].start_address = 0;
    memory[i].end_address = 0;
  }
  printf("Deallocated memory for process %d\n", process->process_id);
  return 1;
}

int main() {
  // os process
  struct PCB os = {0, 0, 1, 0, 0, 400};
  allocate_memory(&os);
  current_queue.head = current_queue.tail = NULL;
  current_queue.len = 0;

  // Create three PCBs for testing
  struct PCB process1 = {1, 1, 0, 0, 10, 600};
  struct PCB process2 = {2, 2, 1, 0, 5, 1000}; // Assuming 0 means "not running"
  struct PCB process3 = {3, 3, 0, 0, 3, 300};
  struct PCB process4 = {3, 3, 0, 0, 3, 700};
  struct PCB process5 = {3, 3, 0, 0, 3, 500};

  // Start with process 1
  struct PCB *current_process = &process1;
  struct PCB *next_process = NULL;

  // Run the processes randomly until all are done
  while (1) {
    // Pick a random process
    int next_process_id = rand() % num_processes + 1;
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

    if (current_process->process_id == next_process->process_id) {
      continue;
    }

    if (!check_if_process_in_queue(&current_queue, next_process) &&
        allocate_memory(next_process)) {
      q_push(&current_queue, next_process);
    } else {
      deallocate_memory(current_queue.head->pcb);
      printf("Current queue length: %d\n", current_queue.len);
      q_pop(&current_queue);
      switch_processes(&current_process, &next_process);
    }

    // // If all processes are done, exit
    //! if (process1.process_counter >= process1.time &&
    //     process2.process_counter >= process2.time &&
    //     process3.process_counter >= process3.time) {
    //   break;
    // }
  }

  return 0;
}
