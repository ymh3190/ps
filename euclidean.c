#include <stdio.h>

// 유클리드 호제법
// 2개의 자연수 또는 정수의 최대 공약수를 구하는 알고리즘
int findGCD(int a, int b) {
  if (!a) return b;
  return findGCD(b % a, a);
}

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  int t;
  fscanf(fd, "%d", &t);

  // for (int i = 0; i < t; i++) {
  //   int a, b;
  //   fscanf(fd, "%d %d", &a, &b);

  //   int n;
  //   if (a > b) {
  //     n = a;
  //   } else {
  //     n = b;
  //   }
  //   while (1) {
  //     if (n % a == 0 && n % b == 0) break;
  //     n++;
  //   }
  //   printf("%d\n", n);
  // }

  for (int i = 0; i < t; i++) {
    int a, b;
    fscanf(fd, "%d %d", &a, &b);
    printf("%d\n", (a * b) / findGCD(a, b));
  }

  fclose(fd);
  return 0;
}
