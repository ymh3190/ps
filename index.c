#include <stdio.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  char buf_a[4];
  char buf_b[4];

  fscanf(fd, "%s %s", buf_a, buf_b);
  int a = (buf_a[2] - 48) * 100 + (buf_a[1] - 48) * 10 + (buf_a[0] - 48);
  int b = (buf_b[2] - 48) * 100 + (buf_b[1] - 48) * 10 + (buf_b[0] - 48);

  printf("%d", a > b ? a : b);

  fclose(fd);
  return 0;
}