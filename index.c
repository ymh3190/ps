#include <stdio.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");
  short a, b, c;
  fscanf(fd, "%hd %hd %hd", &a, &b, &c);
  short arrs[4];
  *arrs = (a + b) % c;
  *(arrs + 1) = ((a % c) + (b % c)) % c;
  *(arrs + 2) = (a * b) % c;
  *(arrs + 3) = ((a % c) * (b % c)) % c;
  for (int i = 0; i < 4; i++) {
    printf("%hd\n", *(arrs + i));
  }

  fclose(fd);
  return 0;
}