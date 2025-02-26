#include <stdio.h>
#include <string.h>

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    char s[n + 1];
    for (int k = 0; k < n + 1; k++) s[k] = '\0';
    for (int j = i; j < n - 1; j++) {
      strcat(s, " ");
    }
    for (int j = 0; j < i + 1; j++) {
      strcat(s, "*");
    }
    printf("%s\n", s);
  }

  return 0;
}