#include <stdio.h>

int isPrime(unsigned int num) {
  if (num < 2) return 0;
  if (num == 2 || num == 3) return 1;
  if (num % 2 == 0 || num % 3 == 0) return 0;

  // 5의 배수, 11의 배수, 13의 배수 체크
  for (unsigned int i = 5; i * i <= num; i += 6) {
    if (num % i == 0 || num % (i + 2) == 0) return 0;
  }
  return 1;
}

// int main() {
//   FILE* fd;
//   fd = fopen("input.txt", "r");

//   unsigned int n;
//   fscanf(fd, "%u", &n);

//   for (unsigned int i = 0; i < n; i++) {
//     unsigned int num;
//     fscanf(fd, "%u", &num);

//     while (!isPrime(num)) {
//       num++;
//     }

//     printf("%u\n", num);
//   }

//   fclose(fd);
//   return 0;
// }
