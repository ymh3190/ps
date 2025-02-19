#include <stdio.h>
#include <string.h>

void merge(char arrs[][6], int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;

  char L[n1][6], R[n2][6];
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
    if (strcmp(L[i], R[j]) >= 0) {
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

void mergeSort(char arrs[][6], int l, int r) {
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
//   char arrs[n][6];
//   for (int i = 0; i < n; i++) {
//     char name[6], tmp[6];
//     fscanf(fd, "%s %s", name, tmp);
//     strcpy(arrs[i], name);
//   }
//   mergeSort(arrs, 0, n - 1);

//   for (int i = 0; i < n; i++) {
//     if (!strcmp(arrs[i], arrs[i + 1]))
//       i++;
//     else
//       printf("%s\n", arrs[i]);
//   }

//   fclose(fd);
//   return 0;
// }