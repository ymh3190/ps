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

int lowerBound(int arrs[], int low, int high, int x) {
  if (low > high) return low;
  int mid = low + (high - low) / 2;
  if (arrs[mid] >= x) return lowerBound(arrs, low, mid - 1, x);
  return lowerBound(arrs, mid + 1, high, x);
}

int upperBound(int arrs[], int low, int high, int x) {
  if (low > high) return low;
  int mid = low + (high - low) / 2;
  if (arrs[mid] <= x) return upperBound(arrs, mid + 1, high, x);
  return upperBound(arrs, low, mid - 1, x);
}

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");
  int n;
  fscanf(fd, "%d", &n);
  int arrs[n];
  for (int i = 0; i < n; i++) {
    fscanf(fd, "%d", &arrs[i]);
  }
  mergeSort(arrs, 0, n - 1);
  for (int i = 0; i < n; i++) {
    printf("%d ", arrs[i]);
  }
  printf("\n\n");

  int m;
  fscanf(fd, "%d", &m);
  for (int i = 0; i < m; i++) {
    int num;
    fscanf(fd, "%d", &num);
    int lower = lowerBound(arrs, 0, n - 1, num);
    int upper = upperBound(arrs, 0, n - 1, num);
    printf("%d %d %d\n", upper, lower, upper - lower);
  }

  fclose(fd);
  return 0;
}