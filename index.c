#include <stdio.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  int a, b;
  while (1) {
    if (fscanf(fd, "%d %d", &a, &b) == EOF) break;
    printf("%d\n", a + b);
  }
  fclose(fd);
  return 0;
}