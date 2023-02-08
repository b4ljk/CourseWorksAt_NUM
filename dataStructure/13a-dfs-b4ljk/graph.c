#include "DS.h"
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
  Гүний нэвтрэлтийн функц: `g` граф дээр гүний нэвтрэлт хийн холбоост
  бүрдлүүдийн талаарх даалгаварт заагдсан мэдээллийг хэвлэнэ.
 */
int grapher(Graph *g, int idx, int *cc, int *parents, int compnum) {
  Elm *elm;
  compnum++;
  parents[idx] = idx;
  for (elm = g->adj[idx].head; elm != NULL; elm = elm->next) {
    if (parents[elm->x] == -1 && parents[idx] != elm->x) {
      parents[elm->x] = idx;
      compnum = grapher(g, elm->x, cc, parents, compnum);
    }
  }
  return compnum;
}
void gr_connected_components(Graph *g, int *cc) {
  // init cc
  int connectedComponent = 0;
  int compItems = 0;
  int parents[g->n + 1];
  int j = 1;
  for (int i = 0; i <= g->n; i++) {
    parents[i] = -1;
  }
  for (int i = 1; i <= g->n; i++) {
    if (parents[i] == -1) {
      cc[j++] = grapher(g, i, cc, parents, compItems);
      connectedComponent++;
    }
  }
  cc[0] = connectedComponent;
}

/*
  Ирмэг нэмэх функц: `g` графын ирмэгүүдийг хадгалах `adj` жагсаалтан хүснэгтэд
  ирмэг нэмнэ. Уг граф нь чиглэлгүй граф тул `x`-с `y`, `y`-с `x` гэсэн хоёр
  ирмэгийг оруулна.
 */
void gr_add_edge(Graph *g, int x, int y) {
  l_push_back(&g->adj[x], y);
  l_push_back(&g->adj[y], x);
}
