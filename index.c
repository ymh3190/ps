#include <stdio.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  int a, b;
  fscanf(fd, "%d %d", &a, &b);
  printf("%d", a + b);

  return 0;
}