#include <stdio.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  char buf[101];
  int size = 0;
  while (1) {
    if (fscanf(fd, "%c", &buf[size]) == EOF) break;
    if (buf[size] == '\n') break;
    size++;
  }
  buf[size] = '\0';

  int mid = size / 2;
  for (int i = 0; i < mid; i++) {
    if (buf[i] != buf[size - 1 - i]) {
      printf("0");
      return 0;
    }
  }
  printf("1");

  fclose(fd);
  return 0;
}