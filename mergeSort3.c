#include <stdio.h>

typedef struct {
  int age;
  int i;
  char name[101];
} mem;

void merge(mem arrs[], int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;

  mem L[n1], R[n2];
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
    if (L[i].age < R[j].age || (L[i].age == R[j].age && L[i].i < R[j].i)) {
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

void mergeSort(mem arrs[], int l, int r) {
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

//   mem arrs[n];
//   for (int i = 0; i < n; i++) {
//     fscanf(fd, "%d %s", &arrs[i].age, arrs[i].name);
//     arrs[i].i = i;
//   }

//   mergeSort(arrs, 0, n - 1);
//   for (int i = 0; i < n; i++) {
//     printf("%d %s\n", arrs[i].age, arrs[i].name);
//   }
//   return 0;
// }