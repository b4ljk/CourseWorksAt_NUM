#include "DS.h"
#include <stdio.h>
#include <stdlib.h>

int is_space(int x) {
  switch (x) {
  case ' ':
  case '\t':
  case '\n':
  case '\r':
  case '\f':
  case '\v':
  case '\0':
    return 1;
  default:
    return 0;
  }
  return 0;
}

int priority(char x) {
  if (x == '(')
    return 0;
  if (x == '+' || x == '-')
    return 1;
  if (x == '*' || x == '/' || x == '%')
    return 2;
  return 0;
}

int convert_to_int(const char s[]) {
  int len = strlen(s);
  int t = 0, i;
  for (i = 0; i < len; i++)
    t = t * 10 + s[i] - '0';
  return t;
}

void tokenize(const char s[], List *p_list) {
  char tmp[EQUATION_LENGTH];
  int i, j, k, len;
  j = 0;
  struct Token x;
  len = strlen(s);
  for (i = 0; i <= len; i++) {
    if ('0' <= s[i] && s[i] <= '9') {
      /* цифр орж ирлээ */
      tmp[j] = s[i];
      j++;
    } else {
      /* тэмдэгт орж ирлээ */
      if (j != 0) { /* Хөрвүүлэх тоо байгаа эсэх */
        tmp[j] = '\0';
        j = 0;
        /* хадгалсан цифрийн цувааг int-рүү хөрвүүл */
        k = convert_to_int(tmp);
        x.flag = 1;
        x.val = k;
        /*
          Жагсаалтанд x элемнтийг оруулах
          Жагсаалтын push_back функцыг дуудна
        */
        l_push_back(p_list, x);
      }
      /*
        тэмдэгтийг жагсаалтанд оруулах
        Жагсаалтын push_back функцыг дуудна
       */
      if (is_space(s[i])) /* хоосон зай, шинэ мөрийг хаяна. */
        continue;

      /*
        Энд +, -, *, /, (, ) тэмдэгтүүдийг жагсаалтад оруулна.
       */
      x.flag = 0;
      x.op = s[i];
      l_push_back(p_list, x);
    }
  }

  /* Тэмдэгтэн цуваанаас салгасан тэгшитгэлийг хэвлэх
     Жагсаалтын print функцыг дуудна.
   */
  /* l_print(p_list); */
}

/*
  p_token - жагсаалтад байгаа тэгштгэлийг postfix-рүү хөрвүүлнэ
 */
void convert_to_postfix(List *p_token, List *p_post) {
  Stack s;
  s.top = NULL;
  s.len = 0;
  int ctr = 0;
  for (TokenElm *looper = p_token->head; looper != NULL;
       looper = looper->next) {
    ctr += 1;
    if (looper->x.flag == 1) {
      l_push_back(p_post, looper->x);
    } else if (looper->x.flag == 0) {
      if (looper->x.op == '(') {
        s_push(&s, looper->x.op);
      } else if (looper->x.op == ')') {
        while (s.top->x != '(') {
          Token x;
          x.flag = 0;
          x.op = s.top->x;
          l_push_back(p_post, x);
          s_pop(&s);
        }
        s_pop(&s);
      } else {
        while (s.len != 0 && priority(s.top->x) >= priority(looper->x.op)) {
          Token x;
          x.flag = 0;
          x.op = s.top->x;
          l_push_back(p_post, x);
          s_pop(&s);
        }
        s_push(&s, looper->x.op);
      }
    }
  }
  while (s.len != 0) {
    Token x;
    x.flag = 0;
    x.op = s.top->x;
    l_push_back(p_post, x);
    s_pop(&s);
  }
}
int solve(List *p_post) {
  Stack s;
  s.top = NULL;
  s.len = 0;
  for (TokenElm *looper = p_post->head; looper != NULL; looper = looper->next) {
    if (looper->x.flag == 1) {
      s_push(&s, looper->x.val);
    } else if (looper->x.flag == 0) {
      int a = s.top->x;
      s_pop(&s);
      int b = s.top->x;
      s_pop(&s);
      if (looper->x.op == '+') {
        s_push(&s, a + b);
      } else if (looper->x.op == '-') {
        s_push(&s, b - a);
      } else if (looper->x.op == '*') {
        s_push(&s, a * b);
      } else if (looper->x.op == '/') {
        s_push(&s, b / a);
      } else if (looper->x.op == '%') {
        s_push(&s, b % a);
      }
    }
  }
  return s.top->x;
}
