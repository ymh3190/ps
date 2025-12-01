#include <stdio.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  char buf[101];
  fscanf(fd, "%s", buf);

  for (int i = 0; i < 101; i++) {
    if (buf[i] == '\0') {
      printf("%d", i);
      break;
    }
  }

  fclose(fd);
  return 0;
}