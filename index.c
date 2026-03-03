#include <stdio.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  int m, n;
  fscanf(fd, "%d\n%d", &m, &n);

  int size = n - m + 1;
  int buf[size];
  for (int i = 0; i < size; i++) {
    buf[i] = 0;
  }

  int idx = 0;
  for (int i = m; i <= n; i++) {
    if (i == 2 || i == 3 || i == 5 || i == 7) {
      buf[idx++] = i;
      continue;
    }
    if (i % 2 == 0 || i % 3 == 0 || i % 5 == 0 || i % 7 == 0) {
      continue;
    }
    for (int j = 11; j <= n; j += 6) {
      if (i != j && i % j == 0) break;
      if (i != (j + 2) && i % (j + 2) == 0) break;
      if (i % j == 0 || i % (j + 2) == 0) {
        buf[idx++] = i;
        break;
      }
    }
  }

  if (idx == 0) {
    printf("-1");
  } else {
    int sum = 0;
    for (int i = 0; i < idx; i++) {
      sum += buf[i];
    }
    printf("%d\n%d", sum, buf[0]);
  }

  fclose(fd);
  return 0;
}