#include <stdio.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  char buf[100];
  int i = 0;
  while (1) {
    if (fscanf(fd, "%c", &buf[i]) == EOF) break;
    if (buf[i] == '\n') {
      buf[i] = '\0';
      i = 0;
      printf("%s\n", buf);
      continue;
    }
    i++;
  }

  fclose(fd);
  return 0;
}