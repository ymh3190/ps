#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  int n;
  fscanf(fd, "%d", &n);

  int arrs[n];
  for (int i = 0; i < n; i++) {
    fscanf(fd, "%d", &arrs[i]);
  }

  for (int i = 0; i < n; i++) {
    printf("%d\n", arrs[i]);
  }
  return 0;
}