#include <stdio.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  int buf[9];
  int i = 0;
  while (1) {
    if (fscanf(fd, "%d", &buf[i]) == EOF) break;
    i++;
  }

  int max = buf[0];
  int idx = 0;
  for (int i = 0; i < 9; i++) {
    if (buf[i] > max) {
      max = buf[i];
      idx = i + 1;
    }
  }

  printf("%d\n%d", max, idx);
  fclose(fd);
  return 0;
}