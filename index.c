#include <stdio.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  char buf[5][16] = {0};
  for (int i = 0; i < 5; i++) {
    fscanf(fd, "%s", buf[i]);
  }

  for (int j = 0; j < 15; j++) {
    for (int i = 0; i < 5; i++) {
      if (buf[i][j] == '\0') continue;
      printf("%c", buf[i][j]);
    }
  }
  fclose(fd);
  return 0;
}