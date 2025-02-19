#include <stdio.h>
#include <string.h>

void merge(char arrs[][51], int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;

  char L[n1][51], R[n2][51];
  for (int i = 0; i < n1; i++) {
    strcpy(L[i], arrs[l + i]);
  }
  for (int j = 0; j < n2; j++) {
    strcpy(R[j], arrs[m + 1 + j]);
  }

  int i = 0;
  int j = 0;
  int k = l;
  while (i < n1 && j < n2) {
    if (strlen(L[i]) < strlen(R[j]) ||
        (strlen(L[i]) == strlen(R[j]) && strcmp(L[i], R[j]) < 0)) {
      strcpy(arrs[k], L[i]);
      i++;
    } else {
      strcpy(arrs[k], R[j]);
      j++;
    }
    k++;
  }

  while (i < n1) {
    strcpy(arrs[k], L[i]);
    i++;
    k++;
  }

  while (j < n2) {
    strcpy(arrs[k], R[j]);
    j++;
    k++;
  }
}

void mergeSort(char arrs[][51], int l, int r) {
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

//   char arrs[n][51];
//   for (int i = 0; i < n; i++) {
//     fscanf(fd, "%s", arrs[i]);
//   }

//   mergeSort(arrs, 0, n - 1);
//   printf("%s\n", arrs[0]);
//   for (int i = 1; i < n; i++) {
//     if (strcmp(arrs[i], arrs[i - 1])) printf("%s\n", arrs[i]);
//   }

//   fclose(fd);
//   return 0;
// }