#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H

#include "processheader.h"
#include <stdio.h>
#include <stdlib.h>

struct Elm {
  struct PCB *pcb;
  struct Elm *next;
};
typedef struct Elm Elm;

struct Queue {
  Elm *head;
  Elm *tail;
  int len;
};
typedef struct Queue Queue;

void q_push(Queue *, struct PCB *);
void q_pop(Queue *);
void q_print(Queue *);
Elm *q_front(Queue *);
int check_if_process_in_queue(Queue *p, struct PCB *x);

#endif