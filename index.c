#include <stdio.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  long long a, b, c;
  fscanf(fd, "%ld %ld %ld", &a, &b, &c);
  printf("%ld", a + b + c);

  fclose(fd);
  return 0;
}