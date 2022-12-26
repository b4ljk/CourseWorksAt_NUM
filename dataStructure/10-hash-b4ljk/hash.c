#include "DS.h"
#include <stdlib.h>
#include <string.h>

/*
  Оюутны мэдээлэл оруулах функц: `p_hash`-ын зааж байгаа хайш хүснэгтэд
  `x`-д хадгалсан оюутны мэдээллийг оруулна.
 */

void ht_insert(HashTable *p_hash, const Student x) {
  int h = ht_hash(x.id);
  Elm *p_elm = l_search(&p_hash->h[h], x.id);
  if (p_elm == NULL)
    l_push_back(&p_hash->h[h], x);
}

/*
  Хайш тооцоолох функц: `s` тэмдэгтэн цувааны хайшыг тооцоолоод,
  тооцоолсон хайшыг буцаах функц.
 */
int ht_hash(const char s[]) {
  unsigned int h = 0, i;
  int len = strlen(s);
  for (i = 0; i < len; i++) {
    h = s[i] + (31 * h);
  }
  return h % (HASH_TABLE_SIZE);
}

/*
  Хайш хүснэгтийн утгуудыг эхлүүлэх функц:  Хайш хүснэгтийн бүх элементийн
  `head`, `tail` утгуудад `NULL` оноох ёстой.
 */
void ht_init(HashTable *p_hash) {
  int i;
  p_hash->h = (List *)malloc(sizeof(List) * HASH_TABLE_SIZE);
  for (i = 0; i < HASH_TABLE_SIZE; i++)
    p_hash->h[i].head = p_hash->h[i].tail = NULL;
}

/*
  Хайх функц: `p_hash`-ыг зааж буй хайш хүснэгтээс `id`-тай оюутныг хайж,
  олдсон оюутны хаягийг буцаах функц. Олдохгүй бол `NULL` хаяг буцаана.
 */
Student *ht_search(HashTable *p_hash, const char id[]) {
  int h = ht_hash(id);
  Elm *p_elm = l_search(&p_hash->h[h], id);
  if (p_elm == NULL)
    return NULL;
  return &p_elm->x;
}

/*
  Мэдээлэл өөрчлөх функц: `p_hash`-ыг зааж буй хайш хүснэгтээс `x.id`-аар
  оюутныг хайж олоод, овог нэрийг `x.ner`, `x.ovog`-оор солино.
  Олдохгүй бол `x` оюутныг шинээр оруулна.
 */
void ht_update(HashTable *p_hash, const Student x) {
  int h = ht_hash(x.id);
  Elm *p_elm = l_search(&p_hash->h[h], x.id);
  if (p_elm == NULL) {
    l_push_back(&p_hash->h[h], x);
  } else {
    strcpy(p_elm->x.ner, x.ner);
    strcpy(p_elm->x.ovog, x.ovog);
  }
}

/*
  Устгах функц: `p_hash`-ыг зааж буй хайш хүснэгтээс `id`-тай оюутныг хайж
  олж устгана. Олдохгүй бол юу ч хийхгүй.
 */
void ht_del(HashTable *p_hash, const char id[]) {
  int h = ht_hash(id);
  List *temp = &p_hash->h[h];
  if (temp->len == 0)
    return;
  if (strcmp(temp->head->x.id, id) == 0) {
    l_pop_front(temp);
    return;
  }
  if (strcmp(temp->tail->x.id, id) == 0) {
    l_pop_back(temp);
    return;
  }
  Elm *looper = temp->head;
  while (looper->next != NULL) {
    if (strcmp(looper->next->x.id, id) == 0) {
      Elm *remove = looper->next;
      looper->next = looper->next->next;
      free(remove);
      temp->len -= 1;
    }
    looper = looper->next;
  }
}

/*
  Хайш хүснэгтийг чөлөөлөх: Ойн цоорхой үүсгэлгүй, бүх элементийг устган,
  хаягийг чөлөөлнө.
 */
void ht_release(HashTable *p_hash) {
  int i;
  for (i = 0; i < HASH_TABLE_SIZE; i++) {
    while (p_hash->h[i].head != NULL)
      l_pop_front(&p_hash->h[i]);
  }
  free(p_hash->h);
}

/*
  Оюутны мэдээллийг хэвлэх функц: `p`-ын зааж буй оюутны овог, нэр, ID-г
  хэвлэнэ.
 */
void student_print(FILE *fout, const Student *p) {
  if (p == NULL)
    fprintf(fout, "xooson\n");
  else
    fprintf(fout, "%s %s %s\n", p->ovog, p->ner, p->id);
}
