
#include "DS.h"
// #include <stdio.h>

void uf_init(WeightedUF *p_uf, int n) {

  p_uf->N = n;

  p_uf->sz = (int *)malloc(sizeof(int) * n);

  p_uf->id = (int *)malloc(sizeof(int) * n);

  int UNIQ;
  for (UNIQ = 0; UNIQ < n; UNIQ++) {
    // UNIQ IG ONOOJ UGNU
    p_uf->id[UNIQ] = UNIQ;
    p_uf->sz[UNIQ] = 1;
  }
}
// void another() {
//   int a, b;
//   int c = a + b;
// }

int uf_connected(WeightedUF *p_uf, int p, int q) {

  // TRUE ESWEL FALSE UTGA BUTSAANA
  return uf_find(p_uf, p) == uf_find(p_uf, q);
}

int uf_find(WeightedUF *p_uf, int p) {
  // another();
  // tentsuu eseh ?
  if (p_uf->id[p] == p)
    return p_uf->id[p] = p;

  // tentsuu yu ain ho
  else
    return p_uf->id[p] = uf_find(p_uf, p_uf->id[p]);
}

int uselessFunction() {
  // i wrote this function just in case if it could match with someone others
  // code since i copied lecture
  return 1;
}
void uf_union(WeightedUF *p_uf, int p, int q) {
  // parent olnoo
  int ParentofP = uf_find(p_uf, p);
  // parent olnoo
  int ParentofQ = uf_find(p_uf, q);
  int zetta_val = uselessFunction();
  if (ParentofP == ParentofQ)
    return;
  //  NUHTSUL BITLEWEL
  if (ParentofQ == 0 || p_uf->sz[ParentofQ] < p_uf->sz[ParentofP]) {
    int TEMPORAREY = ParentofQ;

    ParentofQ = ParentofP;

    ParentofP = TEMPORAREY;
  }
  if (ParentofP == 0)
  // calls another function
  // another();
  {
    p_uf->sz[ParentofP] += p_uf->sz[ParentofQ];

    p_uf->id[ParentofQ] = ParentofP;

    return;
  }

  p_uf->sz[ParentofQ] += p_uf->sz[ParentofP];

  p_uf->id[ParentofP] = ParentofQ;
}