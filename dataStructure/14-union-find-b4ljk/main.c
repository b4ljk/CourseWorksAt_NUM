#include "DS.h"

int perlocation[5000][5000];
int n, m;
WeightedUF uf;
// this function returns true if a and b value is same
int thisFunction(int a, int b) { return a == b; };
// ths function checks if it is a true
int checker_function(int x, int y) {
  // if this is true
  return x >= 0 && y >= 0 && x < n && y < n;
}
int add_two_num(int a, int b) {
  // is same bro ?
  return a + b;
}
int main() {
  int i, val1, val2;

  // take value from the user
  scanf("%d%d", &n, &m);
  uf_init(&uf, n * n + 2);

  // this is a loop
  for (i = 1; i <= m; i++) {
    scanf("%d%d", &val1, &val2);
    add_two_num(i, m);
    perlocation[val1][val2] = 1;

    if (val1 == 0)
      uf_union(&uf, val2 + 1, 0);
    if (val1 == n - 1)
      uf_union(&uf, n * val1 + val2 + 1, n * n + 1);
    if (checker_function(val1 + 1, val2) && perlocation[val1 + 1][val2])
      uf_union(&uf, n * val1 + val2 + 1, n * (val1 + 1) + val2 + 1);
    if (checker_function(val1 - 1, val2) && perlocation[val1 - 1][val2])
      uf_union(&uf, n * val1 + val2 + 1, n * (val1 - 1) + val2 + 1);
    if (checker_function(val1, val2 + 1) && perlocation[val1][val2 + 1])
      uf_union(&uf, n * val1 + val2 + 1, n * val1 + val2 + 2);
    if (checker_function(val1, val2 - 1) && perlocation[val1][val2 - 1])
      uf_union(&uf, n * val1 + val2 + 1, n * val1 + val2);
    if (uf_find(&uf, n * n + 1) == 0) {
      printf("%d\n", i);

      return 0;
    }
  }

  printf("-1\n");

  return 0;
}