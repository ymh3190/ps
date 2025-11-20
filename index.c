#include <stdio.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  short a, b;
  fscanf(fd, "%hd %hd", &a, &b);
  printf("%d\n%d\n%d\n%d\n%d\n", a + b, a - b, a * b, a / b, a % b);
  fclose(fd);
  return 0;
}