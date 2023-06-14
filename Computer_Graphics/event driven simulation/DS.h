#ifndef __MYHEAP_H
#define __MYHEAP_H

#include <string.h>

typedef struct {
  float x, y;
  float speedX, speedY;
  int count;
  float radius;
} point;

struct Event {
  point *a;
  point *b;
  float collisionTime;
  int countA;
  int countB;
  // x for 0, y for 1;
};
typedef struct Event Event;

struct Array {
  Event a[100000];
  int len;
};

// Heap
struct Heap {
  struct Array heap;
};
typedef struct Heap Heap;
#define h_arr heap.a
#define h_len heap.len

int less(Event *, Event *);
void insert(Heap *, const Event);
Event delMin(Heap *);
void swim(Heap *p, int);
void sink(Heap *p, int);
float timeToHit(point *a, point *b);

#endif
