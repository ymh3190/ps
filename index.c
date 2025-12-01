#include <stdio.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  int buf[30];
  for (int i = 0; i < 30; i++) {
    buf[i] = i + 1;
  }

  for (int i = 0; i < 28; i++) {
    int t;
    fscanf(fd, "%d", &t);
    for (int j = 0; j < 30; j++) {
      if (buf[j] == t) {
        buf[j] = 0;
        break;
      }
    }
  }

  for (int i = 0; i < 30; i++) {
    if (buf[i]) printf("%d ", buf[i]);
  }

  fclose(fd);
  return 0;
}