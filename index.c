#include <stdio.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  int n;
  fscanf(fd, "%d", &n);

  int size = 2 * n - 1;
  char buf[size + 1];

  int mid = size / 2;
  for (int i = 0; i <= mid; i++) {
    for (int j = 0; j < mid - i; j++) {
      buf[j] = ' ';
    }
    buf[mid + i] = '*';
    buf[mid - i] = '*';
    buf[mid + i + 1] = '\0';
    printf("%s\n", buf);
  }

  for (int i = 0; i < mid; i++) {
    buf[i] = ' ';
    buf[size - 1 - i] = ' ';
    buf[size - i] = '\0';
    printf("%s\n", buf);
  }

  // 출력 형식 오류
  // int size = 2 * n - 1;
  // char buf[size];
  // for (int i = 0; i < size; i++) {
  //   buf[i] = ' ';
  // }

  // int mid = (size) / 2;
  // for (int i = 0; i <= mid; i++) {
  //   buf[mid - i] = '*';
  //   buf[mid + i] = '*';
  //   for (int j = 0; j < size; j++) {
  //     printf("%c", buf[j]);
  //   }
  //   printf("\n");
  // }
  // for (int i = 0; i < mid; i++) {
  //   buf[i] = ' ';
  //   buf[size - 1 - i] = ' ';
  //   for (int j = 0; j < size; j++) {
  //     printf("%c", buf[j]);
  //   }
  //   printf("\n");
  // }

  fclose(fd);
  return 0;
}