#include <stdio.h>
#include <stdlib.h>

#include "quickSort2.c"

int main() {
  FILE* fptr;
  fptr = fopen("input.txt", "r");

  int n;
  fscanf(fptr, "%d", &n);

  struct pos arrs[n];
  for (int i = 0; i < n; i++) {
    fscanf(fptr, "%d %d", &arrs[i].x, &arrs[i].y);
  }

  qsort(arrs, n, sizeof(struct pos), compare);
  for (int i = 0; i < n; i++) {
    printf("%d %d\n", arrs[i].x, arrs[i].y);
  }

  fclose(fptr);
  return 0;
}