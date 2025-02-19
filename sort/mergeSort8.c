#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

char t[MAX * (MAX + 1) / 2][MAX + 1];

void merge(char arrs[][1001], int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;

  char L[n1][1001], R[n2][1001];
  for (int i = 0; i < n1; i++) {
    strcpy(L[i], arrs[l + i]);
  }
  for (int j = 0; j < n2; j++) {
    strcpy(R[j], arrs[m + 1 + j]);
  }

  int i = 0;
  int j = 0;
  int k = l;
  while (i < n1 && j < n2) {
    if (strcmp(L[i], R[j]) <= 0) {
      strcpy(arrs[k++], L[i++]);
    } else {
      strcpy(arrs[k++], R[j++]);
    }
  }

  while (i < n1) {
    strcpy(arrs[k++], L[i++]);
  }

  while (j < n2) {
    strcpy(arrs[k++], R[j++]);
  }
}

void mergeSort(char arrs[][1001], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    mergeSort(arrs, l, m);
    mergeSort(arrs, m + 1, r);
    merge(arrs, l, m, r);
  }
}

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  char s[1001];
  fscanf(fd, "%s", s);

  int index = 0;
  int n = strlen(s);
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < n - i + 1; j++) {
      strncpy(t[index], s + i, j);
      t[index][j] = '\0';
      index++;
    }
  }
  mergeSort(t, 0, index - 1);

  int ret = 1;
  for (int i = 1; i < index; i++) {
    if (strcmp(t[i], t[i - 1])) ret++;
  }
  printf("%d", ret);

  fclose(fd);

  return 0;
}