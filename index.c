#include <stdio.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  char s[51];
  fscanf(fd, "%s", s);

  printf("%s?\?!", s);
  fclose(fd);
  return 0;
}