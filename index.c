#include <stdio.h>

short f1(short* a, short* b, short* c) { return (*a + *b) % *c; }
short f2(short* a, short* b, short* c) { return ((*a % *c) + (*b % *c)) % *c; }
short f3(short* a, short* b, short* c) { return (*a * *b) % *c; }
short f4(short* a, short* b, short* c) { return ((*a % *c) * (*b % *c)) % *c; }

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");
  short a, b, c;
  fscanf(fd, "%hd %hd %hd", &a, &b, &c);
  printf("%hd\n%hd\n%hd\n%hd\n", f1(&a, &b, &c), f2(&a, &b, &c), f3(&a, &b, &c),
         f4(&a, &b, &c));
  fclose(fd);
  return 0;
}