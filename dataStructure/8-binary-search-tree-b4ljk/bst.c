
#include "DS.h"
#include <stdlib.h>

/*
  `ptree`-ийн зааж байгаа модонд `x` утгыг оруулна.
  Оруулахдаа хоёртын хайлтын модны зарчмаар оруулах бөгөөд оруулсан
  байрлалаас дээшхи өвөг эцгийн `len`, `height` утгууд өөрчлөгдөнө.
  Мод хоосон байсан бол `ptree->root` хаяг өөрчлөгдөж шинээр орсон оройг заана.
 */
int bs_delMin(BST *ptree);

void put_bs(Elm *item, int x) {
  if (item->x < x) {
    if (item->R) {
      put_bs(item->R, x);
    } else {
      Elm *temp = (Elm *)(malloc(sizeof(Elm)));
      temp->height = 1;
      temp->len = 1;
      temp->L = NULL;
      temp->R = NULL;
      temp->x = x;
      item->R = temp;
      temp->parent = item;
    }
  } else {
    if (item->L) {
      put_bs(item->L, x);
    } else {
      Elm *temp = (Elm *)(malloc(sizeof(Elm)));
      temp->height = 1;
      temp->len = 1;
      temp->L = NULL;
      temp->R = NULL;
      temp->x = x;
      item->L = temp;
      temp->parent = item;
    }
  }
  item->len += 1;
  if (item->R != NULL && item->L != NULL) {
    item->height = (item->L->height > item->R->height) ? item->L->height + 1
                                                       : item->R->height + 1;
  } else if (item->L) {
    item->height = item->L->height + 1;
  } else if (item->R) {
    item->height = item->R->height + 1;
  }
}

void bs_put(BST *ptree, int x) {
  // Функцийг хэрэгжүүлнэ үү
  // Дараах мөрийг устга
  // printf("bs_put() function is not implemented yet\n");

  if (ptree->root == NULL) {
    Elm *addable = NULL;
    addable = (Elm *)(malloc(sizeof(Elm)));
    addable->R = addable->L = NULL;
    addable->height = addable->len = 1;
    addable->x = x;
    addable->parent = NULL;
    ptree->root = addable;
  } else {
    put_bs(ptree->root, x);
  }
}
/*
  `ptree`-ийн зааж байгаа модноос `x` утгыг хайн олдсон оройн `Elm*` хаягийг
  буцаана. Олдохгүй бол `NULL` хаягийг буцаана. Мод дандаа ялгаатай элементүүд
  хадгална гэж үзэж болно.
 */
Elm *bs_get(const BST *ptree, int x) {
  // Функцийг хэрэгжүүлнэ үү
  if (ptree->root == NULL)
    return NULL;
  Elm *temp = ptree->root;
  while (temp != NULL) {
    if (temp->x == x) {
      return temp;
    } else if (temp->x > x) {
      temp = temp->L;
    } else {
      temp = temp->R;
    }
  }
  return NULL;
}

Elm *min(Elm *mn) {
  Elm *temp = mn;
  while (temp != NULL && temp->L != NULL) {
    temp = temp->L;
  }
  return temp;
}

int maxim(int x, int b) { return (x > b) ? x : b; }

int sizee(Elm *p) {
  if (p == NULL) {
    return 0;
  } else {
    return p->len;
  }
}

int heightt(Elm *p) {
  if (p == NULL) {
    return 0;
  } else {
    return p->height;
  }
}

/*
  Устгах функц: ХХМноос `x` утгыг хайж олоод устгана.
  Олдохгүй бол юу ч хийхгүй.
 */
Elm *del(Elm *tvr, int x) {
  Elm *t;
  if (tvr == NULL) {
    free(tvr);
  }
  if (x > tvr->x) {
    tvr->R = del(tvr->R, x);
  } else if (x < tvr->x) {
    tvr->L = del(tvr->L, x);
  } else {
    if (tvr->L == NULL) {
      t = tvr->R;
      free(tvr);
      return t;
    } else if (tvr->R == NULL) {
      t = tvr->L;
      free(tvr);
      return t;
    }
    t = min(tvr->R);

    tvr->x = t->x;

    tvr->R = del(tvr->R, t->x);
  }
  tvr->len = 1 + sizee(tvr->L) + sizee(tvr->R);

  tvr->height = 1 + maxim(heightt(tvr->L), heightt(tvr->R));

  return tvr;
}
void bs_del(BST *ptree, int x) {
  // Функцийг хэрэгжүүлнэ үү
  ptree->root = del(ptree->root, x);
}

// update_height(ptree->root, x);

/*
  Хамгийн багыг устгах функц: ХХМноос хамгийг бага утгыг нь устгах функц.
  Устгасан утгыг буцаана.
 */
int delMin(Elm *item) {
  if (item->L->L) {
    int returner = delMin(item->L);
    item->height = item->L->height + 1;
    item->len = item->L->len + 1;
    return returner;
  } else {
    int returnVal = item->L->x;
    if (item->L->R) {
      Elm *temp;
      temp = item->L;
      item->L = item->L->R;
      free(temp);
      item->height = item->L->height + 1;
      item->len = item->L->len + 1;
    } else {
      free(item->L);
      item->L = NULL;
      item->height = 1;
      item->len = 1;
    }
    return returnVal;
  }
}
int bs_delMin(BST *ptree) {

  // Функцийг хэрэгжүүлнэ үү
  if (ptree->root->L == NULL) {
    if (ptree->root->R != NULL) {
      Elm *temp = ptree->root;
      ptree->root = ptree->root->R;
      int value = temp->x;
      free(temp);
      return value;
    } else {
      int val = ptree->root->x;
      free(ptree->root);
      ptree->root = NULL;
      return val;
    }
  }
  int val = delMin(ptree->root);
  return val;
}

/*
  ХХМыг inorder дарааллаар, нэг мөрөнд нэг утга хэвлэнэ.
 */
void print_inorder(const Elm *p) {
  if (p == NULL)
    return;
  if (p->L)
    print_inorder(p->L);
  printf("%d %d %d\n", p->x, p->len, p->height);
  if (p->R)
    print_inorder(p->R);
}
void bs_inorder(const BST *ptree) {
  // Функцийг хэрэгжүүлнэ үү
  print_inorder(ptree->root);
}

/*
  ХХМноос `x` утгаас эрс бага буюу тэнцүү байх хэдэн орой байгааг олж буцаана.
  Өөрөөр хэлбэл хоёртын хайлтын модны утгуудыг өсөх дарааллаар байрлуулбал
  `x`-ийг оролцуулаад өмнө хэдэн тоо байх вэ? гэсэн үг.
  `x` утга заавал модонд байх албагүй.
 */
int bs_rank(const BST *ptree, int x) {

  //  Функцийг хэрэгжүүлнэ үү
  // return length of left element +1
  if (ptree->root == NULL) {
    return 0;
  } else {
    Elm *temp = ptree->root;
    int retValue = 0;
    while (temp != NULL) {
      if (temp->x == x) {
        if (temp->L != NULL) {
          retValue += temp->L->len + 1;
        } else {
          retValue += 1;
        }
        break;
      } else if (temp->x > x) {
        temp = temp->L;
      } else {
        if (temp->L != NULL) {
          retValue += temp->L->len + 1;
        } else {
          retValue += 1;
        }
        temp = temp->R;
      }
    }
    return retValue;
  }
}

/*
  ХХМноос `x` утгатай оройг хайж олоод, тухайн оройд суурилсан
  дэд модонд хэдэн орой байгааг олж буцаана.
  Олдохгүй бол -1-ийг буцаана.
 */
int bs_size(const BST *ptree, int x) {
  // Функцийг хэрэгжүүлнэ үү
  if (ptree->root == NULL)
    return -1;
  Elm *temp = NULL;
  temp = bs_get(ptree, x);
  if (temp == NULL)
    return -1;
  return temp->len;
}

/*
  XXMноос `x`-ээс бага буюу тэнцүү байх хамгийн их утгын `Elm *` хаягийг олж
  буцаана. Олдохгүй бол `NULL` хаягийг буцаана.
 */
Elm *bs_floor(const BST *ptree, int x) {
  // Функцийг хэрэгжүүлнэ үү
  if (ptree->root == NULL)
    return NULL;
  Elm *temp = ptree->root;
  Elm *floor = NULL;
  while (temp != NULL) {
    if (temp->x > x) {
      temp = temp->L;
    } else if (temp->x == x) {
      return temp;
    } else {
      floor = temp;
      temp = temp->R;
    }
  }
  return floor;
}

/*
  XXMноос `x`-ээс их буюу тэнцүү байх хамгийн бага утгын `Elm *` хаягийг олж
  буцаана. Олдохгүй бол `NULL` хаягийг буцаана.
 */
Elm *bs_ceiling(const BST *ptree, int x) {
  // Функцийг хэрэгжүүлнэ үү
  if (ptree->root == NULL)
    return NULL;
  Elm *temp = ptree->root;
  Elm *ceiling = NULL;
  while (temp != NULL) {
    if (temp->x < x) {
      temp = temp->R;
    } else if (x == temp->x) {
      return temp;
    } else {
      ceiling = temp;
      temp = temp->L;
    }
  }
  return ceiling;
}

/*
  ХХМноос `x` утгатай оройг хайж олоод, тухайн оройд суурилсан
  дэд модны өндөр хэд байгааг олж буцаана. Олдохгүй бол -1-ийг буцаана.
 */
int bs_height(const BST *ptree, int x) {
  // Функцийг хэрэгжүүлнэ үү
  if (ptree->root == NULL)
    return -1;
  Elm *temp = NULL;
  temp = bs_get(ptree, x);
  if (temp == NULL)
    return -1;
  return temp->height;
}
