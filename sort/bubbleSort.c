/**
 * @param arrs input array
 * @param n last index
 */
void bubbleSort(int arrs[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arrs[j + 1] < arrs[j]) {
        int t = arrs[j + 1];
        arrs[j + 1] = arrs[j];
        arrs[j] = t;
      }
    }
  }
}
