#include <stdio.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  fclose(fd);
  return 0;
}