#include <stdio.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  short n;
  fscanf(fd, "%hd", &n);
  printf("%d", n * (n + 1) / 2);

  return 0;
}