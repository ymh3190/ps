#include <stdio.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  int n;
  fscanf(fd, "%d", &n);

  int buf[100][100] = {0};
  int r, c;
  for (int i = 0; i < n; i++) {
    fscanf(fd, "%d %d", &r, &c);
    r -= 1;
    c -= 1;
    for (int j = r; j < r + 10; j++) {
      for (int k = c; k < c + 10; k++) {
        if (buf[j][k]) continue;
        buf[j][k]++;
      }
    }
  }

  int s = 0;
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      s += buf[i][j];
    }
  }

  printf("%d", s);
  fclose(fd);
  return 0;
}