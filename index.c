#include <stdio.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  int n;
  fscanf(fd, "%d", &n);

  if (n == 1) return 0;

  while (1) {
    if (n == 1) break;
    if (n % 2 == 0) {
      n /= 2;
      printf("2\n");
      continue;
    }
    if (n % 3 == 0) {
      n /= 3;
      printf("3\n");
      continue;
    }
    if (n % 5 == 0) {
      n /= 5;
      printf("5\n");
      continue;
    }
    if (n % 7 == 0) {
      n /= 7;
      printf("7\n");
      continue;
    }
    for (int i = 11; i <= n; i += 6) {
      if (n % i == 0) {
        n /= i;
        printf("%d\n", i);
        break;
      }
      if (n % (i + 2) == 0) {
        n /= i + 2;
        printf("%d\n", i + 2);
        break;
      }
    }
  }

  fclose(fd);
  return 0;
}