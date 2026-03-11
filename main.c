#include <stdio.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  int n;
  fscanf(fd, "%d", &n);

  printf("%ld\n2", (long int)(n - 1) * n / 2);

  fclose(fd);
  return 0;
}