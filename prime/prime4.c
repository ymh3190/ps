#include <stdio.h>

#define MAX 1000001
int arrs[MAX] = {0};

int getPrime(int n) {
  if (n < 2) return 0;
  if (n == 2 || n == 3) return 1;
  if (n % 2 == 0 || n % 3 == 0) return 0;
  for (int i = 5; i * i < n + 1; i += 6) {
    if (n % i == 0 || n % (i + 2) == 0) return 0;
  }
  return 1;
}

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  for (int i = 2; i < MAX; i++) {
    if (getPrime(i)) arrs[i] = i;
  }

  int t;
  fscanf(fd, "%d", &t);
  for (int i = 0; i < t; i++) {
    int n;
    fscanf(fd, "%d", &n);

    int ret = 0;
    for (int i = 2; i < n; i++) {
      if (arrs[n - i] + arrs[i] == n) ret++;
      if (n - i == i) ret++;
    }
    printf("%d\n", ret / 2);
  }

  fclose(fd);
  return 0;
}