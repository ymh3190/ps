#include <stdio.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  int n;
  fscanf(fd, "%d", &n);

  if (n == 1) {
    printf("1");
    return 0;
  }

  int size = 0;
  int l = 1;
  for (int i = 2; i <= n; i++) {
    size++;
    if ((float)size / (6 * l) > 1) {
      size = 1;
      l++;
    }
  }

  printf("%d", l + 1);

  fclose(fd);
  return 0;
}