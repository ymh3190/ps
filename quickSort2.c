void swap(int (*a)[2], int (*b)[2]) {
  if ((*a)[0] == (*b)[0]) {
    if ((*a)[1] > (*b)[1]) {
      int t = (*a)[1];
      (*a)[1] = (*b)[1];
      (*b)[1] = t;
    }
    return;
  }

  int t = (*a)[0];
  (*a)[0] = (*b)[0];
  (*b)[0] = t;

  t = (*a)[1];
  (*a)[1] = (*b)[1];
  (*b)[1] = t;
}

int partition(int arrs[][2], int low, int high) {
  int pivot = arrs[high][0];
  int i = low - 1;

  for (int j = low; j <= high - 1; j++) {
    if (arrs[j][0] < pivot) {
      i++;
      swap(&arrs[i], &arrs[j]);
    }
  }
  swap(&arrs[i + 1], &arrs[high]);
  return i + 1;
}

void quickSort(int arrs[][2], int low, int high) {
  if (low < high) {
    int pi = partition(arrs, low, high);

    quickSort(arrs, low, pi - 1);
    quickSort(arrs, pi + 1, high);
  }
}