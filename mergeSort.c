/**
 * @param arrs input array
 * @param l left
 * @param m middle
 * @param r right
 */
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

/**
 * @param arrs input array
 * @param l left
 * @param r right
 */
void mergeSort(int arrs[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;

    mergeSort(arrs, l, m);
    mergeSort(arrs, m + 1, r);

    merge(arrs, l, m, r);
  }
}
