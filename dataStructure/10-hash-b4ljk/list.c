#include "DS.h"
#include "string.h"

/* p-ийн зааж буй List-д x утгыг төгсгөлд хийнэ */
void l_push_back(List *p, Student x) {
  /* Энд оруулах үйлдлийг хийнэ үү */
  Elm *addable = (Elm *)(malloc(sizeof(Elm)));
  addable->x = x;
  if (p->len == 0) {
    p->head = addable;
    p->tail = addable;
    addable->next = NULL;
    p->len += 1;
  } else {
    addable->next = NULL;
    p->tail->next = addable;
    p->tail = addable;
    p->len += 1;
  }
}

/* p-ийн зааж буй List-д x утгыг эхэнд хийнэ
   Бүх элементүүд нэг нэг байрлал хойшилно.
 */
void l_push_front(List *p, Student x) {
  /* Энд оруулах үйлдлийг хийнэ үү */
  if (p->len == 0) {
    Elm *addable = (Elm *)(malloc(sizeof(Elm)));
    p->head = addable;
    p->tail = addable;
    addable->x = x;
    addable->next = NULL;
    p->len += 1;
  } else {
    Elm *addable = (Elm *)(malloc(sizeof(Elm)));
    addable->x = x;
    addable->next = p->head;
    p->head = addable;
    p->len += 1;
  }
}

/*
  p-ийн зааж буй List-д x утгыг pos байрлалд хийнэ
  pos болон түүнээс хойшхи элементүүд нэг байрлал ухарна.
  Тухайн байрлал List-ийн сүүлийн индексээс их бол төгсгөлд орно.
 */
void l_insert(List *p, Student x, int pos) {
  /* Энд оруулах үйлдлийг хийнэ үү */
  if (pos >= p->len) {
    l_push_back(p, x);
  } else if (pos <= 0) {
    l_push_front(p, x);
  } else {
    Elm *addable = (Elm *)(malloc(sizeof(Elm)));
    addable->x = x;
    Elm *temp = p->head;
    int i;
    for (i = 0; i < pos - 1; i++) {
      temp = temp->next;
    }
    addable->next = temp->next;
    temp->next = addable;
    p->len += 1;
  }
}

/*
  p-ийн зааж буй List-н эхлэлээс гаргана.
  List-ийн бүх элементүүд нэг нэг байрлал урагшилна
 */
void l_pop_front(List *p) {
  /* Энд гаргах үйлдлийг хийнэ үү */
  if (p->len == 0) {
    return;
  } else if (p->len == 1) {
    free(p->head);
    p->head = NULL;
    p->tail = NULL;
    p->len -= 1;
  } else {
    Elm *temp = p->head;
    p->head = p->head->next;
    free(temp);
    p->len -= 1;
  }
}

/* p-ийн зааж буй List-н төгсгөлөөс гаргана */
void l_pop_back(List *p) {
  /* Энд гаргах үйлдлийг хийнэ үү */
  if (p->len == 0)
    return;
  if (p->len == 1) {
    free(p->head);
    p->head = NULL;
    p->tail = NULL;
    p->len -= 1;
    return;
  }
  Elm *clone = p->head;
  while (clone->next != p->tail) {
    clone = clone->next;
  }
  free(p->tail);
  p->tail = clone;
  p->tail->next = NULL;
  p->len -= 1;
}

/* p-ийн зааж буй List-н pos байрлалаас гаргана.
   pos болон түүнээс хойшхи элементүүд нэг байрлал урагшилна.
   pos байрлалаас гарах боломжгүй бол юу ч хийхгүй.
 */
void l_erase(List *p, int pos) {
  /* Энд гаргах үйлдлийг хийнэ үү */
  if (pos == 0) {
    l_pop_front(p);
    return;
  } else if (pos == p->len - 1) {
    l_pop_back(p);
    return;
  } else if (pos > p->len - 1) {
    return;
  }
  Elm *clone;
  int i;
  for (clone = p->head, i = 0; i < p->len; i++) {
    if (i == pos - 1) {
      Elm *temp = clone->next->next;
      free(clone->next);
      clone->next = temp;
      p->len -= 1;
      return;
    }
    clone = clone->next;
  }
}

/*
  p-ийн зааж буй List-н утгуудыг хэвлэнэ.
  Хамгийн эхний элементээс эхлэн дарааллаар, нэг мөрөнд
  нэг л элемент хэвлэнэ.
 */
void l_print(List *p) {
  Elm *clone;
  for (clone = p->head; clone != NULL; clone = clone->next) {
    printf("%s %s %s\n", clone->x.id, clone->x.ner, clone->x.ovog);
  }
}

/*
  p-ийн зааж буй List-с id-тай оюутныг хайн олдсон хаягийг буцаана.
  Олдохгүй бол NULL хаяг буцаана.
 */
Elm *l_search(List *p, const char id[]) {
  /*
    Энд хайх үйлдлийг хийнэ үү.
   */
  if (p->len == 0)
    return NULL;
  if (strcmp(p->tail->x.id, id) == 0) {
    return p->tail;
  }
  Elm *clone;
  for (clone = p->head; clone != NULL; clone = clone->next) {
    if (strcmp(clone->x.id, id) == 0) {
      return clone;
    }
  }
  return NULL;
}
