void swap(int* xp, int* yp) {
  int tmp = *xp;
  *xp = *yp;
  *yp = tmp;
}

int partition(int arrs[], int low, int high) {
  int pivot = arrs[high];
  int i = low - 1;
  for (int j = low; j <= high - 1; j++) {
    if (arrs[j] < pivot) {
      i++;
      swap(&arrs[i], &arrs[j]);
    }
  }
  swap(&arrs[i + 1], &arrs[high]);
  return i + 1;
}

void quickSort(int arrs[], int low, int high) {
  if (low < high) {
    int pi = partition(arrs, low, high);

    quickSort(arrs, low, pi - 1);
    quickSort(arrs, pi + 1, high);
  }
}