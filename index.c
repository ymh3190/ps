#include <stdio.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  int n;
  fscanf(fd, "%d", &n);

  char buf[101];
  int c = n;
  for (int i = 0; i < n; i++) {
    fscanf(fd, "%s", buf);
    char t[26] = {0};
    int idx = 0;
    int flag = 0;
    for (int j = 0; j < 100; j++) {
      if (buf[j] == '\0') break;
      for (int k = 0; k < idx; k++) {
        if (t[k] == buf[j]) {
          c--;
          break;
        }
      }
      if (flag) {
        c--;
        break;
      }
      if (buf[j] == buf[j + 1]) {
        continue;
      }
      t[idx] = buf[j];
      idx++;
    }
  }

  printf("%d", c);
  fclose(fd);
  return 0;
}