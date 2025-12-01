#include <stdio.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  char buf[16];
  fscanf(fd, "%s", buf);

  int dials[26] = {3, 3, 3, 4, 4, 4, 5, 5, 5, 6,  6,  6,  7,
                   7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10};

  int s = 0;
  for (int i = 0; i < 16; i++) {
    if (buf[i] == '\0') break;
    s += dials[buf[i] - 65];
  }

  printf("%d", s);
  fclose(fd);
  return 0;
}