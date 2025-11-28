#include <stdio.h>
#include <stdlib.h>

// option 1
// char buf[1000000][6];

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  int t;
  fscanf(fd, "%d", &t);

  // option 2
  // static char buf[1000000][6];
  char (*buf)[6] = (char (*)[6])malloc(sizeof(char) * 1000000 * 6);
  int a, b;
  for (int i = 0; i < t; i++) {
    fscanf(fd, "%d %d", &a, &b);
    sprintf(buf[i], "%d\n", a + b);
  }
  for (int i = 0; i < t; i++) {
    printf("%s", buf[i]);
  }
  free(buf);
  fclose(fd);
  return 0;
}