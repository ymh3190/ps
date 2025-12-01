#include <stdio.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  int n;
  int m;
  fscanf(fd, "%d %d", &n, &m);

  int buf[n];
  for (int i = 0; i < n; i++) {
    buf[i] = i + 1;
  }

  for (int i = 0; i < m; i++) {
    int a, b;
    fscanf(fd, "%d %d", &a, &b);
    a -= 1;
    b -= 1;
    int t = buf[a];
    buf[a] = buf[b];
    buf[b] = t;
  }

  for (int i = 0; i < n; i++) {
    printf("%d ", buf[i]);
  }
  fclose(fd);
  return 0;
}