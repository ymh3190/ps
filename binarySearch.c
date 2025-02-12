#include <stdio.h>

void merge(int arrs[], int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;

  int L[n1];
  for (int i = 0; i < n1; i++) {
    L[i] = arrs[l + i];
  }
  int R[n2];
  for (int j = 0; j < n2; j++) {
    R[j] = arrs[m + 1 + j];
  }

  int i = 0;
  int j = 0;
  int k = l;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
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

void mergeSort(int arrs[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    mergeSort(arrs, l, m);
    mergeSort(arrs, m + 1, r);

    merge(arrs, l, m, r);
  }
}

/**
 * A recursive binary search function. It returns
 * Location of x in given array arrs[low..high] is present,
 * otherwise -1
 * @param arrs input array
 * @param low low index
 * @param high high index
 * @param x target value
 */
int binarySearch(int arrs[], int low, int high, int x) {
  if (high >= low) {
    int mid = low + (high - low) / 2;

    // If the element is present at the middle
    // itself
    if (arrs[mid] == x) return mid;

    // If element is smaller than mid, then
    // it can only be present in left subarray
    if (arrs[mid] > x) return binarySearch(arrs, low, mid - 1, x);

    // else element can only be present
    // in right subarray
    return binarySearch(arrs, mid + 1, high, x);
  }

  // We reach here when element is not
  // present in array
  return -1;
}

// int main() {
//   FILE* fd;
//   fd = fopen("input.txt", "r");

//   int n;
//   fscanf(fd, "%d", &n);
//   int nArrs[n];
//   for (int i = 0; i < n; i++) {
//     fscanf(fd, "%d", &nArrs[i]);
//   }
//   mergeSort(nArrs, 0, n - 1);

//   int m;
//   fscanf(fd, "%d", &m);
//   for (int i = 0; i < m; i++) {
//     int num;
//     fscanf(fd, "%d", &num);
//     int ret = binarySearch(nArrs, 0, n - 1, num);
//     printf("%d ", ret != -1 ? 1 : 0);
//   }

//   // O(N^2)
//   // for (int i = 0; i < m; i++) {
//   //   int flag = 0;
//   //   for (int j = 0; j < n; j++) {
//   //     if (nArrs[j] == mArrs[i]) {
//   //       flag = 1;
//   //       break;
//   //     }
//   //   }
//   //   flag ? printf("1 ") : printf("0 ");
//   // }

//   fclose(fd);
//   return 0;
// }