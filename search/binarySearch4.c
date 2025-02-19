#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(char arrs[][21], int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;

  char L[n1][21], R[n2][21];
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
      strcpy(arrs[k++], L[i++]);
    } else {
      strcpy(arrs[k++], R[j++]);
    }
  }

  while (i < n1) {
    strcpy(arrs[k++], L[i++]);
  }

  while (j < n2) {
    strcpy(arrs[k++], R[j++]);
  }
}

void mergeSort(char arrs[][21], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    mergeSort(arrs, l, m);
    mergeSort(arrs, m + 1, r);
    merge(arrs, l, m, r);
  }
}

int binarySearch(char arrs[][21], int low, int high, char* x) {
  if (low <= high) {
    int mid = low + (high - low) / 2;
    if (strcmp(arrs[mid], x) == 0) return mid;
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

//   char nArrs[n][21], mArrs[m][21];
//   for (int i = 0; i < n; i++) {
//     fscanf(fd, "%s", nArrs[i]);
//   }
//   for (int i = 0; i < m; i++) {
//     fscanf(fd, "%s", mArrs[i]);
//   }
//   mergeSort(nArrs, 0, n - 1);
//   mergeSort(mArrs, 0, m - 1);

//   int ret = 0;
//   //   char rets[m][21];
//   char** rets = (char**)calloc(m, sizeof(char*));

//   for (int i = 0; i < m; i++) {
//     int index = binarySearch(nArrs, 0, n - 1, mArrs[i]);
//     rets[i] = "";
//     // strcpy(rets[i], "");
//     if (index == -1) continue;
//     ret++;
//     rets[i] = mArrs[i];
//     // strcpy(rets[i], mArrs[i]);
//   }

//   printf("%d\n", ret);
//   for (int i = 0; i < m; i++) {
//     if (strlen(rets[i]) == 0) continue;
//     printf("%s\n", rets[i]);
//   }

//   free(rets);
//   fclose(fd);
//   return 0;
// }