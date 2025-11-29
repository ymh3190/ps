#include <stdio.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  int n, x;
  fscanf(fd, "%d %d", &n, &x);

  int buf[n];
  for (int i = 0; i < n; i++) {
    fscanf(fd, "%d", &buf[i]);
  }

  for (int i = 0; i < n; i++) {
    if (buf[i] < x) printf("%d ", buf[i]);
  }
  fclose(fd);
  return 0;
}