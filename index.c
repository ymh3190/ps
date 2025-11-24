#include <stdio.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  int x, y;
  fscanf(fd, "%d\n%d", &x, &y);

  int a = y % 10;
  int b = (y / 10) % 10;
  int c = (y / 100);
  printf("%d\n%d\n%d\n%d\n", x * a, x * b, x * c,
         x * a + 10 * (x * b) + 100 * (x * c));
  fclose(fd);
  return 0;
}