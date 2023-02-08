#include "DS.h"
#include <stdio.h>

/*
  p-ийн зааж буй CBTree-д x утгыг оруулна
*/
void cb_push(CBTree *p, int x) {
  p->tree.a[p->tree.len] = x;
  p->tree.len += 1;
}

/*
  p-ийн зааж буй CBTree-д idx индекстэй оройны зүүн хүүгийн индексийг буцаана.
  Зүүн хүү байхгүй бол -1 буцаана.
*/
int cb_left(const CBTree *p, int idx) {
  /* Энд зүүн хүүхдийн индексийг буцаах үйлдлийг хийнэ үү */
  if (idx * 2 + 1 < p->tree.len)
    return idx * 2 + 1;
  else
    return -1;
}

/*
  p-ийн зааж буй CBTree-д idx индекстэй оройны баруун хүүгийн индексийг буцаана.
  Баруун хүү байхгүй бол -1 буцаана.
*/
int cb_right(const CBTree *p, int idx) {
  /* Энд баруун хүүхдийн индексийг буцаах үйлдлийг хийнэ үү */
  if (idx * 2 + 2 < p->tree.len)
    return idx * 2 + 2;
  else
    return -1;
}

/*
  p-ийн зааж буй CBTree-с x тоог хайн
  хамгийн эхэнд олдсон индексийг буцаана.
  Олдохгүй бол -1 утгыг буцаана.
*/
int cb_search(const CBTree *p, int x) { /* Энд хайх үйлдлийг хийнэ */
}

/*
  p-ийн зааж буй CBTree-д idx индекстэй зангилаанаас дээшхи бүх өвөг эцэгийг
  олох үйлдлийг хийнэ. Тухайн орой өөрөө өвөг эцэгт орохгүй. Өвөг эцэг бүрийг
  нэг шинэ мөрөнд хэвлэнэ. Өвөг эцэгийг доороос дээшхи дарааллаар хэвлэнэ.
*/
void cb_ancestors(const CBTree *p, int idx) {
  /* Энд өвөг эцгийг олох үйлдлийг хийнэ үү */
}

/*
  p-ийн зааж буй CBTree-ийн өндрийг буцаана
*/
int cb_height(const CBTree *p) { /* Энд өндрийг олох үйлдлийг хийнэ */
}

/*
  p-ийн зааж буй CBTree-д idx оройны ах, дүү оройн дугаарыг буцаана.
  Тухайн оройн эцэгтэй адил эцэгтэй орой.
  Ах, дүү нь байхгүй бол -1-г буцаана.
*/
int cb_sibling(const CBTree *p, int idx) {
  /* Энд ах, дүүг олох үйлдлийг хийнэ үү */
}

/*
  p-ийн зааж буй CBTree-г idx дугаартай зангилаанаас эхлэн preorder-оор хэвлэ.
  Орой бүрийг нэг шинэ мөрөнд хэвлэнэ.
*/
void cb_preorder(const CBTree *p, int idx) {
  Stack s;
  int i;
  s.len = 0;
  s.top = NULL;
  s_push(&s, idx);
  while (s.len > 0) {
    i = s.top->x;
    s_pop(&s);
    if (i != -1) {
      printf("%d\n", p->tree.a[i]);
      s_push(&s, cb_right(p, i));
      s_push(&s, cb_left(p, i));
    }
  }
}

/*
  p-ийн зааж буй CBTree-г idx дугаартай зангилаанаас эхлэн in-order-оор хэвлэ.
  Орой бүрийг нэг шинэ мөрөнд хэвлэнэ.
*/
void cb_inorder(const CBTree *p, int idx) {
  /* Энд in-order-оор хэвлэх үйлдлийг хийнэ үү */
  Stack s;
  int i;
  s.len = 0;
  s.top = NULL;
  i = idx;
  while (s.len > 0 || i != -1) {
    if (i != -1) {
      s_push(&s, i);
      i = cb_left(p, i);
    } else {
      i = s.top->x;
      s_pop(&s);
      printf("%d\n", p->tree.a[i]);
      i = cb_right(p, i);
    }
  }
}

/*
  p-ийн зааж буй CBTree-г idx дугаартай зангилаанаас эхлэн post-order-оор хэвлэ.
  Орой бүрийг нэг шинэ мөрөнд хэвлэнэ.
 */
void cb_postorder(const CBTree *p, int idx) {
  /* Энд post-order-оор хэвлэх үйлдлийг хийнэ үү */
  Stack s;
  int i, j;
  s.len = 0;
  s.top = NULL;
  i = idx;
  while (s.len > 0 || i != -1) {
    if (i != -1) {
      s_push(&s, i);
      i = cb_left(p, i);
    } else {
      i = s.top->x;
      j = cb_right(p, i);
      if (j != -1) {
        i = j;
      } else {
        printf("%d\n", p->tree.a[i]);
        s_pop(&s);
        while (s.len > 0 && cb_right(p, s.top->x) == i) {
          i = s.top->x;
          printf("%d\n", p->tree.a[i]);
          s_pop(&s);
        }
        if (s.len > 0) {
          i = cb_right(p, s.top->x);
        } else {
          i = -1;
        }
      }
    }
  }
}

/*
  p-ийн зааж буй CBTree-с idx дугаартай зангилаанаас доошхи бүх навчийг олно.
  Навч тус бүрийн утгыг шинэ мөрөнд хэвлэнэ.
  Навчыг зүүнээс баруун тийш олдох дарааллаар хэвлэнэ.
*/
void cb_leaves(const CBTree *p, int idx) {
  /* Энд навчуудыг үйлдлийг хийнэ үү */
}

/*
  p-ийн зааж буй CBTree-д idx индекстэй оройноос доошхи бүх үр садыг хэвлэнэ.
  Тухайн орой өөрөө үр сад болохгүй.
  Үр, сад бүрийг нэг шинэ мөрөнд хэвлэнэ. Үр садыг pre-order дарааллаар хэлэх
  ёстой.
*/
void cb_descendants(const CBTree *p, int idx) {
  /* Энд үр садыг олох үйлдлийг хийнэ үү */
}

/*
  p-ийн зааж буй Tree-д хэдэн элемент байгааг буцаана.
  CBTree-д өөрчлөлт оруулахгүй.
*/
int cb_size(const CBTree *p) { /* Энд хэмжээг олох үйлдлийг хийнэ үү */
}

/*
  p-ийн зааж буй CBTree-д x утгаас үндэс хүртэлх оройнуудын тоог буцаана.
  x тоо олдохгүй бол -1-г буцаана.
*/
int cb_level(const CBTree *p, int x) {
  /* Энд түвшинг олох үйлдлийг хийнэ үү */
}
