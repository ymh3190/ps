#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(char** arrs, int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;

  char** L = (char**)malloc(n1 * sizeof(char*));
  char** R = (char**)malloc(n2 * sizeof(char*));
  for (int i = 0; i < n1; i++) {
    L[i] = arrs[l + i];
  }
  for (int j = 0; j < n2; j++) {
    R[j] = arrs[m + 1 + j];
  }

  int i = 0;
  int j = 0;
  int k = l;
  while (i < n1 && j < n2) {
    if (strlen(L[i]) < strlen(R[j]) ||
        (strlen(L[i]) == strlen(R[j]) && strcmp(L[i], R[j]) < 0)) {
      arrs[k] = L[i];
      i++;
    } else {
      arrs[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arrs[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arrs[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(char** arrs, int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    mergeSort(arrs, l, m);
    mergeSort(arrs, m + 1, r);

    merge(arrs, l, m, r);
  }
}

// int main() {
//   FILE* fd;
//   fd = fopen("input.txt", "r");

//   int n;
//   fscanf(fd, "%d", &n);

//   char** arrs = (char**)malloc(n * sizeof(char*));
//   for (int i = 0; i < n; i++) {
//     arrs[i] = (char*)malloc(51 * sizeof(char));
//     fscanf(fd, "%s", arrs[i]);
//   }

//   mergeSort(arrs, 0, n - 1);
//   for (int i = 0; i < n; i++) {
//     printf("%s\n", arrs[i]);
//     free(arrs[i]);
//   }

//   fclose(fd);
//   return 0;
// }