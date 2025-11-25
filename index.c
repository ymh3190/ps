#include <stdbool.h>
#include <stdio.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  short x, y;
  fscanf(fd, "%hd\n%hd", &x, &y);
  fclose(fd);

  bool isQ1 = x > 0 && y > 0;
  if (isQ1) {
    printf("1");
    return 0;
  }

  bool isQ2 = x < 0 && y > 0;
  if (isQ2) {
    printf("2");
    return 0;
  }

  bool isQ3 = x < 0 && y < 0;
  if (isQ3) {
    printf("3");
    return 0;
  }

  bool isQ4 = x > 0 && y < 0;
  if (isQ4) {
    printf("4");
    return 0;
  }

  return 1;
}