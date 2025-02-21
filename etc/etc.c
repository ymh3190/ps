#include <stdio.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  int n;
  fscanf(fd, "%d", &n);

  int ret = 1;
  for (int i = 2; i * i < n + 1; i++) {
    ret++;
  }
  printf("%d", ret);

  fclose(fd);
  return 0;
}