#include <stdio.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  int x;
  fscanf(fd, "%d", &x);

  if (x == 1) {
    printf("1/1");
    return 0;
  }

  int idx = 2;
  while (1) {
    if (idx * (idx + 1) / 2 >= x && (idx - 1) * idx / 2 < x) {
      break;
    }
    idx++;
  }

  int lx = idx * (idx + 1) / 2;
  int a, b;
  if (idx % 2 == 0) {
    a = idx;
    b = 1;
  } else {
    a = 1;
    b = idx;
  }

  for (int i = lx - 1; i >= x; i--) {
    if (idx % 2 == 0) {
      a--;
      b++;
    } else {
      a++;
      b--;
    }
  }

  printf("%d/%d", a, b);

  fclose(fd);
  return 0;
}