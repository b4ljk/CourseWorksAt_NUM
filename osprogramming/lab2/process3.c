#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PCB {
  int process_id;      // Process ID
  int priority;        // Process Priority
  int state;           // Process State
  int process_counter; // Process counter value
  // Add other fields as necessery
};

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

int main() {
  char str[100];
  while (1) {
    scanf("%s", str);
    lettersInString(str);
  }
  return 0;
}