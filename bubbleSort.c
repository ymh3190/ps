void swap(int* xp, int* yp) {
  int tmp = *xp;
  *xp = *yp;
  *yp = tmp;
}

/**
 * @param arrs input array
 * @param n last index
 */
void bubbleSort(int arrs[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arrs[j + 1] < arrs[j]) {
        swap(&arrs[j], &arrs[j + 1]);
      }
    }
  }
}
