#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int a;
  int b;
  int c;
} Buf;

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  int t;
  fscanf(fd, "%d", &t);
  // Buf buf[t];
  Buf* buf = malloc(sizeof(Buf) * t);
  for (int i = 0; i < t; i++) {
    fscanf(fd, "%d %d", &(buf[i].a), &(buf[i].b));
    buf[i].c = buf[i].a + buf[i].b;
  }
  for (int i = 0; i < t; i++) {
    printf("Case #%d: %d + %d = %d\n", i + 1, buf[i].a, buf[i].b, buf[i].c);
  }

  free(buf);
  fclose(fd);
  return 0;
}