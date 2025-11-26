#include <stdio.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  char h, m;
  fscanf(fd, "%hhd %hhd", &h, &m);
  fclose(fd);

  if (m >= 45) {
    printf("%hhd %hhd", h, m - 45);
    return 0;
  }

  h = h < 1 ? 23 : h - 1;
  m = m + 15 >= 60 ? m - 45 : m + 15;
  printf("%hhd %hhd", h, m);
  return 0;
}