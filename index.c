#include <stdio.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  char x;
  fscanf(fd, "%d", &x);
  printf("%d", x);

  fclose(fd);
  return 0;
}