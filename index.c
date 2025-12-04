#include <stdio.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  int n, m;
  fscanf(fd, "%d %d", &n, &m);

  int a[n][m];
  int b[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      fscanf(fd, "%d", &a[i][j]);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      fscanf(fd, "%d", &b[i][j]);
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d ", a[i][j] + b[i][j]);
    }
    printf("\n");
  }

  fclose(fd);
  return 0;
}