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

  while (1) {
    int n;
    fscanf(fd, "%d", &n);
    if (n == 0) break;

    int ret = 0;
    for (int i = n + 1; i < 2 * n + 1; i++) {
      ret += isPrime(i);
    }
    printf("%d\n", ret);
  }

  fclose(fd);

  return 0;
}