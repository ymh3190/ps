#include <stdio.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  int n;
  fscanf(fd, "%d", &n);

  char buf[n + 1];
  fscanf(fd, "%s", buf);

  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += buf[i] - 48;  // '0'
  }

  printf("%d", sum);
  fclose(fd);
  return 0;
}