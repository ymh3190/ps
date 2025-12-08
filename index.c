#include <stdio.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  int t;
  fscanf(fd, "%d", &t);

  int c;
  for (int i = 0; i < t; i++) {
    fscanf(fd, "%d", &c);
    int q = c / 25;
    int d = (c % 25) / 10;
    int n = ((c % 25) % 10) / 5;
    int p = ((c % 25) % 10) % 5;
    printf("%d %d %d %d\n", q, d, n, p);
  }

  fclose(fd);
  return 0;
}