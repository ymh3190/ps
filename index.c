#include <math.h>
#include <stdio.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  int n;
  fscanf(fd, "%d", &n);

  printf("%d", (int)pow((pow(2, n) + 1), 2));

  fclose(fd);
  return 0;
}