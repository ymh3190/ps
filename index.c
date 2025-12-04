#include <math.h>
#include <stdio.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  char buf[31];
  int b;
  fscanf(fd, "%s %d", buf, &b);

  int size = 0;
  for (int i = 0; i < 31; i++) {
    if (buf[i] == '\0') break;
    size++;
  }

  int s = 0;
  int e = size - 1;
  for (int i = 0; i < size; i++) {
    if (buf[i] >= 'A' && buf[i] <= 'Z') {
      s += (buf[i] - 55) * (int)pow(b, e);
      e--;
      continue;
    }
    s += (buf[i] - 48) * (int)pow(b, e);
    e--;
  }

  printf("%d", s);
  fclose(fd);
  return 0;
}