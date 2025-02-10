#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "quickSort3.c"

int main() {
  FILE* fptr;
  fptr = fopen("input.txt", "r");

  int n;
  fscanf(fptr, "%d", &n);

  str arrs[n];
  for (int i = 0; i < n; i++) {
    fscanf(fptr, "%s", arrs[i].s);
    arrs[i].len = strlen(arrs[i].s);
  }

  qsort(arrs, n, sizeof(str), compare);
  for (int i = 0; i < n; i++) {
    if (strcmp(arrs[i + 1].s, arrs[i].s) || i == n - 1) {
      printf("%s\n", arrs[i].s);
    }
  }

  fclose(fptr);
  return 0;
}