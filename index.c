#include <stdio.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  int t;
  fscanf(fd, "%d", &t);

  char buf[1000];
  for (int i = 0; i < t; i++) {
    fscanf(fd, "%s", buf);
    for (int j = 0; j < 1000; j++) {
      if (buf[j] == '\0') {
        printf("%c%c\n", buf[0], buf[j - 1]);
        break;
      }
    }
  }

  fclose(fd);
  return 0;
}