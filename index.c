#include <stdio.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  char a, b;
  short c;
  fscanf(fd, "%hhd %hhd\n%hd", &a, &b, &c);
  fclose(fd);

  a = (b + c) / 60 > 0 ? a + (b + c) / 60 : a;
  b = (b + c) % 60;
  if (a >= 24) a -= 24;
  printf("%hhd %hhd", a, b);
  return 0;
}