#include <stdio.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  int t;
  fscanf(fd, "%d", &t);

  char buf[20];
  int r;
  for (int i = 0; i < t; i++) {
    fscanf(fd, "%d %s", &r, buf);
    for (int j = 0; j < 20; j++) {
      if (buf[j] == '\0') break;
      for (int k = 0; k < r; k++) {
        printf("%c", buf[j]);
      }
    }
    printf("\n");
  }

  fclose(fd);
  return 0;
}