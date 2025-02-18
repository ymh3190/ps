#include <stdio.h>

void merge(int arrs[], int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;

  int L[n1], R[n2];
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
    if (L[i] <= R[j]) {
      arrs[k++] = L[i++];
    } else {
      arrs[k++] = R[j++];
    }
  }

  while (i < n1) {
    arrs[k++] = L[i++];
  }

  while (j < n2) {
    arrs[k++] = R[j++];
  }
}

void mergeSort(int arrs[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    mergeSort(arrs, l, m);
    mergeSort(arrs, m + 1, r);
    merge(arrs, l, m, r);
  }
}

int binarySearch(int arrs[], int low, int high, int x) {
  if (low <= high) {
    int mid = low + (high - low) / 2;
    if (arrs[mid] == x) return mid;
    if (arrs[mid] > x) return binarySearch(arrs, low, mid - 1, x);
    return binarySearch(arrs, mid + 1, high, x);
  }
  return -1;
}

// int main() {
//   FILE* fd;
//   fd = fopen("input.txt", "r");

//   int n, m;
//   fscanf(fd, "%d %d", &n, &m);

//   int nArrs[n], mArrs[m];
//   for (int i = 0; i < n; i++) {
//     fscanf(fd, "%d", &nArrs[i]);
//   }
//   for (int i = 0; i < m; i++) {
//     fscanf(fd, "%d", &mArrs[i]);
//   }
//   mergeSort(nArrs, 0, n - 1);
//   mergeSort(mArrs, 0, m - 1);

//   int ret = 0;
//   for (int i = 0; i < m; i++) {
//     int index = binarySearch(nArrs, 0, n - 1, mArrs[i]);
//     if (index == -1) ret++;
//   }
//   for (int i = 0; i < n; i++) {
//     int index = binarySearch(mArrs, 0, m - 1, nArrs[i]);
//     if (index == -1) ret++;
//   }
//   printf("%d", ret);

//   fclose(fd);
//   return 0;
// }