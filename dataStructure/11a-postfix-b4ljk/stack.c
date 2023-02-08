#include "DS.h"
/*
  p-ийн зааж буй Stack-т x утгыг оруулна
 */
void s_push(Stack *p, int x) {
  /* Энд оруулах үйлдлийг хийнэ үү */
  if (p->len == 0) {
    Elm *newElm = (Elm *)malloc(sizeof(Elm));
    newElm->x = x;
    newElm->next = NULL;
    p->len += 1;
    p->top = newElm;
  } else {

    Elm *newElm = (Elm *)malloc(sizeof(Elm));
    newElm->x = x;
    newElm->next = p->top;
    p->len += 1;
    p->top = newElm;
  }
}
/*
  p-ийн зааж буй Stack-аас гарах функц
 */
void s_pop(Stack *p) {
  /* Энд гаргах үйлдлийг хийнэ үү */
  int returnval;
  if (p->len == 0)
    return;
  Elm *next = p->top->next;
  returnval = p->top->x;
  free(p->top);
  p->top = next;
  p->len -= 1;
}
/*
    p-ийн зааж буй Stack-д байгаа элементүүдийг хэвлэх функц.
    Хамгийн сүүлд орсон элементээс эхлэн дарааллаар, нэг мөрөнд
    нэг л элемент хэвлэнэ.
 */
void s_print(Stack *p) {
  /* Энд хэвлэх үйлдлийг хийнэ үү */
  Elm *pt;
  for (pt = p->top; pt != NULL; pt = pt->next) {
    printf("%d\n", pt->x);
  }
}
