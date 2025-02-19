#include <stdio.h>
#include <string.h>

void merge(char arrs[][501], int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;

  char L[n1][501], R[n2][501];
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
    if (strcmp(L[i], R[j]) <= 0) {
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

void mergeSort(char arrs[][501], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    mergeSort(arrs, l, m);
    mergeSort(arrs, m + 1, r);
    merge(arrs, l, m, r);
  }
}

int binarySearch(char arrs[][501], int low, int high, char x[501]) {
  if (high >= low) {
    int mid = low + (high - low) / 2;
    if (!strcmp(arrs[mid], x)) return mid;
    if (strcmp(arrs[mid], x) > 0) return binarySearch(arrs, low, mid - 1, x);
    return binarySearch(arrs, mid + 1, high, x);
  }
  return -1;
}

// int main() {
//   FILE* fd;
//   fd = fopen("input.txt", "r");

//   int n, m;
//   fscanf(fd, "%d %d", &n, &m);
//   char nArrs[n][501];
//   for (int i = 0; i < n; i++) {
//     fscanf(fd, "%s", nArrs[i]);
//   }
//   mergeSort(nArrs, 0, n - 1);

//   int ret = 0;
//   for (int i = 0; i < m; i++) {
//     char str[501];
//     fscanf(fd, "%s", str);
//     ret += binarySearch(nArrs, 0, n - 1, str) != -1 ? 1 : 0;
//   }
//   printf("%d", ret);

//   fclose(fd);
//   return 0;
// }