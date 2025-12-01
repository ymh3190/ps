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

  int m = buf[0];
  for (int i = 0; i < n; i++) {
    if (buf[i] > m) m = buf[i];
  }

  float sum = 0;
  for (int i = 0; i < n; i++) {
    sum += (float)buf[i] / m;
  }
  printf("%f", sum * 100 / n);

  fclose(fd);
  return 0;
}