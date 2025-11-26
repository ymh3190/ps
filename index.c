#include <stdio.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  char a, b, c;
  fscanf(fd, "%hhd %hhd %hhd", &a, &b, &c);
  fclose(fd);

  if (a == b && b == c) {
    printf("%hu", 10000 + 1000 * a);
    return 0;
  }

  if (a == b) {
    printf("%hd", 1000 + 100 * a);
    return 0;
  }

  if (b == c) {
    printf("%hd", 1000 + 100 * b);
    return 0;
  }

  if (c == a) {
    printf("%hd", 1000 + 100 * c);
    return 0;
  }

  if (a > b && a > c) {
    printf("%hd", 100 * a);
    return 0;
  }
  if (b > a && b > c) {
    printf("%hd", 100 * b);
    return 0;
  }

  printf("%hd", 100 * c);
  return 0;
}