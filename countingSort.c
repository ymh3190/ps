/**
 * @param arr input array
 * @param n input array length
 */
void countSort(int arr[], int n) {
  int max = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] > max) max = arr[i];
  }

  int* cArrs = (int*)calloc(max + 1, sizeof(int));
  for (int i = 0; i < n; i++) {
    cArrs[arr[i]]++;
  }
  for (int i = 1; i <= max; i++) {
    cArrs[i] += cArrs[i - 1];
  }

  int* mArrs = (int*)malloc(n * sizeof(int));
  // geeksforgeeks guide
  for (int i = n - 1; i >= 0; i--) {
    mArrs[cArrs[arr[i]] - 1] = arr[i];
    cArrs[arr[i]]--;
  }
  // for (int i = 0; i < n; i++) {
  //   mArrs[cArrs[arr[i]] - 1] = arr[i];
  //   cArrs[arr[i]]--;
  // }
  for (int i = 0; i < n; i++) {
    arr[i] = mArrs[i];
  }

  free(cArrs);
  free(mArrs);
}
