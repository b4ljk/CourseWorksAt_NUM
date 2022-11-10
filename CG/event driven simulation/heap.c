#include "DS.h"
#include <math.h>
// #include "math.h"
/*
  Хоёр зурвасын чухлыг харьцуулах функц.
  b нь илүү чухал бол 1, бусад үед 0-ыг буцаах функц.
  Өөрөөр хэлбэл a < b үйлдэл юм.
*/
int less(Event *a, Event *b) {
  // Энд жиших үйлдийг хийнэ
  if (!a || !b)
    return 0;
  if (b->collisionTime > a->collisionTime) {
    return 1;
  } else if (b->collisionTime == a->collisionTime) {
    return 1;
  } else {
    return 0;
  }
}

/*
  Оруулах функц. heap зарчмаар чухлын дарааллыг баримтлан оруулна.
  Ингэхдээ хамгийн чухал зурвас heap-ын оройд хадгалагдана.
  x зурвасыг p-ын зааж буй heap бүтцэд оруулна.
 */
void insert(Heap *p, const Event x) {
  // Энд оруулах үйлдлийг хийнэ
  if (p->heap.len > 0) {
    p->heap.len += 1;
    p->heap.a[p->heap.len - 1] = x;
    swim(p, p->heap.len - 1);
    sink(p, p->heap.len - 1);
  } else {
    p->heap.a[0] = x;
    p->heap.len = 1;
  }
}
// replace үйлдэл
void replace(Event *a, Event *b) {
  Event temp = *b;
  *b = *a;
  *a = temp;
}
/*
  Heap бүтцийн swim үйлдэл.
  k нь swim үйлдлийг p-ын зааж буй heap дээр эхлүүлэх индекс.
 */
void swim(Heap *p, int k) {
  // Энд swim үйлдлийг хийнэ
  int i = k;
  while (i > 0 && less(&p->heap.a[i], &p->heap.a[(i - 1) / 2])) {

    replace(&p->heap.a[i], &p->heap.a[(i - 1) / 2]);
    i = (i - 1) / 2;
  }
}

/*
  Heap бүтцийн sink үйлдэл.
  k нь sink үйлдлийг p-ын зааж буй heap дээр эхлүүлэх индекс.
 */
void sink(Heap *p, int k) {
  // Энд sink үйлдлийг хийнэ
  int i = k;
  while (2 * i + 1 < p->heap.len) {
    int j = 2 * i + 1;
    if (j < p->heap.len - 1 && less(&p->heap.a[j + 1], &p->heap.a[j])) {
      j++;
    }
    if (less(&p->heap.a[i], &p->heap.a[j])) {
      break;
    }
    replace(&p->heap.a[i], &p->heap.a[j]);
    i = j;
  }
}

/*
  p-ын зааж буй heap бүтцээс оройн элементийг гаргаад буцаах функц.
  Гаргасны дараа орой бүрийн хувьд heap зарчим хадгалах ёстой.
 */
Event delMin(Heap *p) {
  // Энд хамгийн багыг гаргах үйлдлийг хийнэ
  replace(&p->heap.a[0], &p->heap.a[p->heap.len - 1]);
  p->heap.len -= 1;
  sink(p, 0);
  return p->heap.a[p->heap.len];
}

float timeToHit(point *a, point *b) {
  if (a == b)
    return -1;
  float dx = b->x - a->x;
  float dy = b->y - a->y;
  float dvx = b->speedX - a->speedY;
  float dvy = b->speedY - a->speedY;
  float dvdr = dx * dvx + dy * dvy;
  if (dvdr > 0)
    return -1;
  float dvdv = dvx * dvx + dvy * dvy;
  if (dvdv == 0)
    return -1;
  float drdr = dx * dx + dy * dy;
  float sigma = a->radius / 10 + b->radius / 10;
  float d = (dvdr * dvdr) - dvdv * (drdr - sigma * sigma);
  if (d < 0)
    return -1;
  return -(dvdr + sqrt(d)) / dvdv;
}
