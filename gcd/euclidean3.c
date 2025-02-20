#include <stdio.h>

int findGCD(int a, int b) {
  if (!a) return b;
  return findGCD(b % a, a);
}

// int main() {
//   FILE* fd;
//   fd = fopen("input.txt", "r");

//   int n;
//   fscanf(fd, "%d", &n);

//   int arrs[n];
//   for (int i = 0; i < n; i++) {
//     fscanf(fd, "%d", &arrs[i]);
//   }

//   int difs[n - 1];
//   for (int i = 1; i < n; i++) {
//     difs[i - 1] = arrs[i] - arrs[i - 1];
//   }

//   int gcd = difs[0];
//   for (int i = 1; i < n - 1; i++) {
//     gcd = findGCD(gcd, difs[i]);
//   }

//   int ret = 0;
//   for (int i = 0; i < n - 1; i++) {
//     ret += difs[i] / gcd - 1;
//   }
//   printf("%d", ret);

//   fclose(fd);
//   return 0;
// }