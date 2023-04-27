#include "DS.h"

/* p-ийн зааж буй Queue-д x утгыг хийнэ */
void q_push(Queue *p, struct PCB *x) {
  /* Энд оруулах үйлдлийг хийнэ үү */
  if (p->len == 0) {
    Elm *addable = (Elm *)(malloc(sizeof(Elm)));
    addable->pcb = x;
    addable->next = NULL;
    p->head = addable;
    p->tail = addable;
    p->len += 1;
  } else {
    Elm *addable = (Elm *)(malloc(sizeof(Elm)));
    addable->pcb = x;
    addable->next = NULL;
    p->tail->next = addable;
    p->tail = addable;
    p->len += 1;
  }
}

/* p-ийн зааж буй Queue-с гаргана */
void q_pop(Queue *p) {
  /* Энд гаргах үйлдлийг хийнэ үү */
  if (p->len == 0)
    return;
  Elm *freeable = p->head;
  p->head = p->head->next;
  p->len -= 1;
  free(freeable);
}

Elm *q_front(Queue *p) {
  /* Энд үзэх үйлдлийг хийнэ үү */
  return p->head;
}

int check_if_process_in_queue(Queue *p, struct PCB *x) {
  if (p->len == 0)
    return 0;
  Elm *ptr;
  for (ptr = p->head; ptr != NULL; ptr = ptr->next) {
    if (ptr->pcb->process_id == x->process_id) {
      return 1;
    }
  }
  return 0;
}

/*
  p-ийн зааж буй Queue-н утгуудыг хэвлэнэ.
  Хамгийн эхний элементээс эхлэн дарааллаар, нэг мөрөнд
  нэг л элемент хэвлэнэ.
 */
void q_print(Queue *p) {
  /* Энд хэвлэх үйлдлийг хийнэ үү */
  Elm *ptr;
  for (ptr = p->head; ptr != NULL; ptr = ptr->next) {
    printf("%d\n", ptr->pcb->process_id);
  }
}
