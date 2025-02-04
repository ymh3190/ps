#include <stdio.h>
#include <stdlib.h>

#include "countingSort.c"

int main() {
  FILE* fptr;
  fptr = fopen("input.txt", "r");

  int n;
  fscanf(fptr, "%d", &n);

  int arrs[n];
  for (int i = 0; i < n; i++) {
    fscanf(fptr, "%d", &arrs[i]);
  }

  countSort(arrs, n);
  for (int i = 0; i < n; i++) {
    printf("%d\n", arrs[i]);
  }

  fclose(fptr);
  return 0;
}