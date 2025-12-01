#include <stdio.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  int buf[42];
  for (int i = 0; i < 42; i++) {
    buf[i] = 0;
  }

  for (int i = 0; i < 10; i++) {
    int t;
    fscanf(fd, "%d", &t);
    buf[t % 42] = 1;
  }

  int c = 0;
  for (int i = 0; i < 42; i++) {
    if (buf[i]) c++;
  }
  printf("%d", c);

  fclose(fd);
  return 0;
}