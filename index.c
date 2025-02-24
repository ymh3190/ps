#include <stdio.h>
#include <string.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  while (1) {
    char s[101];
    fgets(s, sizeof(s), fd);
    if (s[0] == 46) break;
    s[strcspn(s, "\n")] = '\0';

    int sl = 0;
    int sr = 0;
    int ll = 0;
    int lr = 0;
    int flag = 0;

    for (int i = 0; i < strlen(s); i++) {
      if (s[i] == '(') {
        sl++;
      } else if (s[i] == ')') {
        sr++;
        if (sr > sl || (ll - lr == 1 && sl == sr)) flag = 1;
      } else if (s[i] == '[') {
        ll++;
      } else if (s[i] == ']') {
        lr++;
        if (lr > ll) flag = 1;
      }
    }

    flag ? printf("no\n") : printf("yes\n");
  }

  fclose(fd);
  return 0;
}