#include <stdio.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  int n, b;
  fscanf(fd, "%d %d", &n, &b);

  int buf[30] = {0};
  int idx = 0;
  while (1) {
    if (n <= 0) {
      idx--;
      break;
    }
    int t = n % b;
    if (t >= 10) {
      buf[idx] = t + 55;
    } else {
      buf[idx] = t;
    }
    idx++;
    n /= b;
  }

  for (int i = idx; i >= 0; i--) {
    if (buf[i] >= 10) {
      printf("%c", buf[i]);
      continue;
    }
    printf("%d", buf[i]);
  }

  fclose(fd);
  return 0;
}