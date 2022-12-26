#include "DS.h"

/* p-ийн зааж буй Queue-д x утгыг хийнэ */
void q_push(Queue *p, int x)
{
        /* Энд оруулах үйлдлийг хийнэ үү */
        if (p->len == 0)
        {
                Elm *addable = (Elm *)(malloc(sizeof(Elm)));
                addable->x = x;
                addable->next = NULL;
                p->head = addable;
                p->tail = addable;
                p->len += 1;
        }
        else
        {
                Elm *addable = (Elm *)(malloc(sizeof(Elm)));
                addable->x = x;
                addable->next = NULL;
                p->tail->next = addable;
                p->tail = addable;
                p->len += 1;
        }
}

/* p-ийн зааж буй Queue-с гаргана */
void q_pop(Queue *p)
{
        /* Энд гаргах үйлдлийг хийнэ үү */
        if (p->len == 0)
                return;
        Elm *freeable = p->head;
        p->head = p->head->next;
        p->len -= 1;
        free(freeable);
}

/*
  p-ийн зааж буй Queue-н утгуудыг хэвлэнэ.
  Хамгийн эхний элементээс эхлэн дарааллаар, нэг мөрөнд
  нэг л элемент хэвлэнэ.
 */
void q_print(Queue *p)
{
        /* Энд хэвлэх үйлдлийг хийнэ үү */
        Elm *ptr;
        for (ptr = p->head; ptr != NULL; ptr = ptr->next)
        {
                printf("%d\n", ptr->x);
        }
}
