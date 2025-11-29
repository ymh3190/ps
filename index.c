#include <stdio.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  int n;
  fscanf(fd, "%d", &n);

  int buf[n];
  for (int i = 0; i < n; i++) {
    fscanf(fd, "%d", &buf[i]);
  }

  int c = 0;
  int v;
  fscanf(fd, "%d", &v);
  for (int i = 0; i < n; i++) {
    if (buf[i] == v) c++;
  }
  printf("%d", c);

  fclose(fd);
  return 0;
}