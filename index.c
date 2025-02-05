#include <stdio.h>

#include "quickSort2.c"

int main() {
  FILE* fptr;
  fptr = fopen("input.txt", "r");

  int n;
  fscanf(fptr, "%d", &n);

  int arrs[n][2];
  for (int i = 0; i < n; i++) {
    fscanf(fptr, "%d %d", &arrs[i][0], &arrs[i][1]);
  }

  quickSort(arrs, 0, n - 1);
  for (int i = 0; i < n; i++) {
    printf("%d %d\n", arrs[i][0], arrs[i][1]);
  }

  fclose(fptr);
  return 0;
}