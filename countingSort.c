/**
 * @param iArrs input array
 * @param N input array length
 */
void countSort(int iArrs[], int N) {
  int M = 0;
  for (int i = 0; i < N; i++) {
    if (iArrs[i] > M) M = iArrs[i];
  }

  int* cArrs = (int*)calloc(M + 1, sizeof(int));

  for (int i = 0; i < N; i++) {
    cArrs[iArrs[i]]++;
  }

  for (int i = 1; i <= M; i++) {
    cArrs[i] += cArrs[i - 1];
  }

  int* oArrs = (int*)malloc(N * sizeof(int));
  for (int i = N - 1; i >= 0; i--) {
    oArrs[cArrs[iArrs[i]] - 1] = iArrs[i];
    cArrs[iArrs[i]]--;
  }

  for (int i = 0; i < N; i++) {
    iArrs[i] = oArrs[i];
  }

  free(cArrs);
  free(oArrs);
}
