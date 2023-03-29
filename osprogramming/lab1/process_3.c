#include "processheader.h"
#include <stdio.h>

void lettersInString(char *str) {
  int i;
  int letters[26];
  for (i = 0; i < 26; i++) {
    letters[i] = 0;
  }
  for (i = 0; i < strlen(str); i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      letters[str[i] - 'a']++;
    } else if (str[i] >= 'A' && str[i] <= 'Z') {
      letters[str[i] - 'A']++;
    }
  }
  for (i = 0; i < 26; i++) {
    printf("%c: %d\n", 'A' + i, letters[i]);
  }
}