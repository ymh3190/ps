#include <stdio.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  char buf[1000000];
  int c = 0;
  while (1) {
    if (fscanf(fd, "%s", buf) == EOF) break;
    c++;
  }

  printf("%d", c);
  fclose(fd);
  return 0;
}