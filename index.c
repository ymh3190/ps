#include <stdio.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  int n;
  int m;
  fscanf(fd, "%d %d", &n, &m);

  int buf[n];
  for (int i = 0; i < n; i++) {
    buf[i] = 0;
  }

  for (int i = 0; i < m; i++) {
    int a, b, c;
    fscanf(fd, "%d %d %d", &a, &b, &c);
    a -= 1;
    b -= 1;
    for (a; a <= b; a++) {
      buf[a] = c;
    }
  }

  for (int i = 0; i < n; i++) {
    printf("%d ", buf[i]);
  }
  fclose(fd);
  return 0;
}