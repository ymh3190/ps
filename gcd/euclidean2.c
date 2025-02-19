#include <stdio.h>

int findGCD(int a, int b) {
  if (!a) return b;
  return findGCD(b % a, a);
}

// int main() {
//   FILE* fd;
//   fd = fopen("input.txt", "r");

//   int a, b, c, d;
//   fscanf(fd, "%d %d\n%d %d", &a, &b, &c, &d);

//   int x, y;
//   x = a * d + b * c;
//   y = b * d;

//   printf("%d %d", x / findGCD(x, y), y / findGCD(x, y));

//   fclose(fd);
//   return 0;
// }