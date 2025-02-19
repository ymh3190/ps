#include <stdio.h>

int findGCD(int a, int b) {
  if (!a) return b;
  return findGCD(b % a, a);
}

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  int n;
  fscanf(fd, "%d", &n);

  int arrs[n];
  for (int i = 0; i < n; i++) {
    fscanf(fd, "%d", &arrs[i]);
  }

  int m = arrs[1] - arrs[0];
  for (int i = 1; i < n; i++) {
    if (arrs[i] - arrs[i - 1] < m) m = arrs[i] - arrs[i - 1];
  }
  m = m > 2 ? 2 : m;

  int ret = 0;
  for (int i = 1; i < n; i++) {
    int t = arrs[i] - arrs[i - 1];
    printf("%d ", t);
    while (t / m >= m) {
      ret++;
      t -= m;
    }
  }
  printf("\n%d", ret);

  fclose(fd);
  return 0;
}