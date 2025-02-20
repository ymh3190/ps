#include <stdio.h>

int isPrime(int num) {
  if (num < 2) return 0;
  if (num == 2 || num == 3) return 1;
  if (num % 2 == 0 || num % 3 == 0) return 0;
  for (int i = 5; i * i < num + 1; i += 6) {
    if (num % i == 0 || num % (i + 2) == 0) return 0;
  }
  return 1;
}

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  int m, n;
  fscanf(fd, "%d %d", &m, &n);

  for (int i = m; i < n + 1; i++) {
    if (isPrime(i)) printf("%d\n", i);
  }

  fclose(fd);

  return 0;
}