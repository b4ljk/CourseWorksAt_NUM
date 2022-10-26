#ifndef __MYHEAP_H
#define __MYHEAP_H

#include <string.h>

typedef struct
{
        float x;
        float y;
        float radius;
        float speedX;
        float speedY;
} point;

struct Msg
{
        point *a;
        float collisionTime;
        // x for 0, y for 1;
        int whichWall;
};
typedef struct Msg Msg;

struct Array
{
        Msg a[10000];
        int len;
};

// Heap
struct Heap
{
        struct Array heap;
};
typedef struct Heap Heap;
#define h_arr heap.a
#define h_len heap.len

int less(Msg *, Msg *);
void insert(Heap *, const Msg);
Msg delMin(Heap *);
void swim(Heap *p, int);
void sink(Heap *p, int);

#endif
