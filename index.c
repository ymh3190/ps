#include <stdio.h>
#include <string.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  while (1) {
    int sl = 0;
    int sr = 0;
    int ll = 0;
    int lr = 0;
    int flag = 0;

    char s[101];
    fgets(s, sizeof(s), fd);
    s[strcspn(s, "\n")] = '\0';

    if (s[0] == 46) break;

    for (int i = 0; i < strlen(s); i++) {
      if (s[i] == 40) {
        sl++;
      } else if (s[i] == 41) {
        sr++;
        if (sr > sl || (ll - lr == 1 && sl == sr)) flag = 1;
      } else if (s[i] == 91) {
        ll++;
      } else if (s[i] == 93) {
        lr++;
        if (lr > ll) flag = 1;
      } else if (s[i] == 46) {
        if (!flag || (!sl && !sr && !ll && !lr))
          printf("yes\n");
        else
          printf("no\n");
        break;
      }
    }
  }

  fclose(fd);
  return 0;
}