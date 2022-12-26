#include "DS.h"
// #include <cstdio>
#include <stdio.h>
/*
  Графыг эхлүүлэх функц: `g` графын хөршүүдийг хадгалах жагсаалтан хүснэгтийг
  эхлүүлэх функц. Санах ойг бэлдэж, жагсаалтын `head`, `tail` утгуудад `NULL`
  онооно.
 */
void gr_init_graph(Graph *g, int n) {
  int i;
  g->adj = (List *)malloc(sizeof(List) * (n + 1));
  g->n = n;
  for (i = 0; i <= n; i++) {
    g->adj[i].head = g->adj[i].tail = NULL;
    g->adj[i].len = 0;
  }
}

/*
  Төвшний нэвтрэлтийн функц: `g` граф дээр `s` оройгоос эхлэн төвшний
  нэвтрэлтийг хийнэ. `pi`: Төвшний нэвтрэлт хийсний дараа `pi[u]` нь `u` оройд
  ямар оройгоос ирснийг хадгална.
 */
void gr_bfs(Graph *g, int s, int pi[]) {
  /* Энд функцийг хэрэгжүүл */
  Queue q;
  q.head = q.tail = NULL;
  q.len = 0;
  q_push(&q, s);
  int i;
  while (q.len != 0) {
    i = q.head->x;
    q_pop(&q);
    for (Elm *u = g->adj[i].head; u != NULL; u = u->next) {
      if (pi[u->x] == -1 && pi[i] != u->x) {
        pi[u->x] = i;
        q_push(&q, u->x);
      }
    }
  }
}

/*
  Замын оройнуудыг хэвлэх функц: `pi` хүснэгтээс `s`, `t` орой хоорондын замын
  мэдээллийг хэвлэнэ. Хамгийн эхний мөрөнд замын уртыг, дараагийн мөрөнд `s`
  оройгоос эхлэн ямар оройгоор дамжиж очиж байгаа оройнуудыг 1 хоосон зайгаар
  тусгаарлан хэвлэнэ. Хэрэв зам байхгүй бол `-1` гэсэн ганц утга хэвлэнэ.
 */
void gr_print_path(int pi[], int s, int t) {
  Stack st;
  st.len = 0;
  st.top = NULL;
  int counter = 0;
  int i;
  for (i = t; i != -1; i = pi[i]) {
    s_push(&st, i);
    counter += 1;
  }
  if (st.top->x == s) {
    printf("%d\n", counter);
    while (st.len != 0) {
      counter = st.top->x;
      s_pop(&st);
      printf("%d ", counter);
    }
  } else {
    printf("%d", -1);
  }
}

/*
  Ирмэг нэмэх функц: `g` графын ирмэгүүдийг хадгалах `adj` жагсаалтан хүснэгтэд
  ирмэг нэмнэ. Уг граф нь чиглэлгүй граф тул `x`-с `y`, `y`-с `x` гэсэн хоёр
  ирмэгийг оруулна.
 */
//! CORRECT
void gr_add_edge(Graph *g, int x, int y) {
  l_push_back(&g->adj[x], y);
  l_push_back(&g->adj[y], x);
}
