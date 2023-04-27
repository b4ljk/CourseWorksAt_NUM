#include "processheader.h"
#include <stdio.h>

void generate_random_string(char *str, int length) {
  srand(time(NULL)); // seed the random number generator with current time

  const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  const int charset_length = sizeof(charset) - 1; // length of the character set

  for (int i = 0; i < length; ++i) {
    str[i] =
        charset[rand() %
                charset_length]; // pick a random character from the set and
                                 // assign it to the i-th position of the string
  }
  str[length] = '\0'; // add the null terminator at the end of the string
}

void process3() {
  char *str = malloc(100 * sizeof(char));
  generate_random_string(str, 100);
  printf("%s\n", str);
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