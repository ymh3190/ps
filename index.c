#include <stdio.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  char n;
  fscanf(fd, "%hhd", &n);
  fclose(fd);

  char arrs[9][11];
  for (char i = 0; i < 9; i++) {
    sprintf(arrs[i], "%hhd * %hhd = %hhd", n, i + 1, n * (i + 1));
    printf("%s\n", arrs[i]);
  }

  return 0;
}