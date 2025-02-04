/**
 * @param arrs input array
 * @param n last index
 */
void insertSort(int arrs[], int n) {
  for (int i = 1; i < n; i++) {
    int key = arrs[i];
    int j = i - 1;
    while (j >= 0 && arrs[j] > key) {
      arrs[j + 1] = arrs[j];
      j--;
    }
    arrs[j + 1] = key;
  }
}
