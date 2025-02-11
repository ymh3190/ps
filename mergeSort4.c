typedef struct {
  int i;
  int v;
} pos;

void merge(pos arrs[], int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;

  pos L[n1], R[n2];
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
    if (L[i].v <= R[j].v) {
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

void mergeSort(pos arrs[], int l, int r) {
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

//   pos arrs[n];
//   int rets[n];
//   for (int i = 0; i < n; i++) {
//     fscanf(fd, "%d", &arrs[i].v);
//     arrs[i].i = i;
//   }
//   mergeSort(arrs, 0, n - 1);

//   int index = 0;
//   rets[arrs[0].i] = index;
//   for (int i = 1; i < n; i++) {
//     if (arrs[i].v != arrs[i - 1].v) index++;
//     rets[arrs[i].i] = index;
//   }

//   for (int i = 0; i < n; i++) {
//     printf("%d ", rets[i]);
//   }

//   fclose(fd);
//   return 0;
// }