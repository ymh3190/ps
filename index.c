#include <stdio.h>

int main() {
  FILE* fptr;
  fptr = fopen("input.txt", "r");

  int n;
  fscanf(fptr, "%d", &n);

  int arrs[n];
  for (int i = 0; i < n; i++) {
    fscanf(fptr, "%d", &arrs[i]);
  }

  for (int i = 0; i < n; i++) {
    printf("%d\n", arrs[i]);
  }

  fclose(fptr);
  return 0;
}