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
    int a;
    int b;
    fscanf(fd, "%d %d", &a, &b);
    a -= 1;
    b -= 1;
    for (int j = a; j < b; j++) {
      int t = buf[j];
      buf[j] = buf[b];
      buf[b] = t;
      b--;
    }
  }

  for (int i = 0; i < n; i++) {
    printf("%d ", buf[i]);
  }

  fclose(fd);
  return 0;
}