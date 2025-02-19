#include <stdio.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");
  int t;
  fscanf(fd, "%d", &t);

  for (int i = 0; i < t; i++) {
    int a, b;
    fscanf(fd, "%d %d", &a, &b);

    int n;
    if (a > b) {
      n = a;
    } else {
      n = b;
    }
    while (1) {
      if (n % a == 0 && n % b == 0) break;
      n++;
    }
    printf("%d\n", n);
  }

  fclose(fd);
  return 0;
}
