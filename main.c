#include <stdio.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  int buf[3];
  for (int i = 0; i < 3; i++) {
    fscanf(fd, "%d", &buf[i]);
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (j == i) continue;
      if (buf[j] > buf[i]) {
        int t = buf[j];
        buf[j] = buf[i];
        buf[i] = t;
      }
    }
  }

  int a, b, c;
  a = buf[0];
  b = buf[1];
  c = buf[2];

  if (c >= a + b) {
    printf("%d", a + b + (a + b - 1));
  } else {
    printf("%d", a + b + c);
  }

  fclose(fd);
  return 0;
}