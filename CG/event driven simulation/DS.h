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
        int collisionTime;
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

int less(const Msg *, const Msg *);
void insert(Heap *, const Msg);
Msg delMin(Heap *);

#endif
