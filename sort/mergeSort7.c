#include <stdio.h>
#include <string.h>

typedef struct {
  char name[21];
  int i;
} mons;

void merge(mons arrs[], int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;

  mons L[n1], R[n2];
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
    if (strcmp(L[i].name, R[j].name) <= 0) {
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

void mergeSort(mons arrs[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    mergeSort(arrs, l, m);
    mergeSort(arrs, m + 1, r);
    merge(arrs, l, m, r);
  }
}

int binarySearch(mons arrs[], int low, int high, char x[21]) {
  if (low <= high) {
    int mid = low + (high - low) / 2;
    if (!strcmp(arrs[mid].name, x)) return mid;
    if (strcmp(arrs[mid].name, x) > 0)
      return binarySearch(arrs, low, mid - 1, x);
    return binarySearch(arrs, mid + 1, high, x);
  }
  return -1;
}

// int main() {
//   FILE* fd;
//   fd = fopen("input.txt", "r");
//   int n, m;
//   fscanf(fd, "%d %d", &n, &m);

//   char arrs[n][21];
//   mons sort[n];
//   for (int i = 0; i < n; i++) {
//     fscanf(fd, "%s", arrs[i]);
//     strcpy(sort[i].name, arrs[i]);
//     sort[i].i = i + 1;
//   }
//   mergeSort(sort, 0, n - 1);

//   for (int i = 0; i < m; i++) {
//     int num;
//     if (fscanf(fd, "%d", &num)) {
//       printf("%s\n", arrs[num - 1]);
//       continue;
//     }
//     char str[21];
//     fscanf(fd, "%s", str);
//     printf("%d\n", sort[binarySearch(sort, 0, n - 1, str)].i);
//   }

//   fclose(fd);
//   return 0;
// }