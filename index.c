#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  int n;
  fscanf(fd, "%d", &n);

  fclose(fd);
  return 0;
}