#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  int n;
  fscanf(fd, "%d", &n);

  // char buf[n][n + 1];
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j <= i; j++) {
  //     buf[i][j] = '*';
  //   }
  //   for (int j = n - 1; j > i; j--) {
  //     buf[i][j] = '\0';
  //   }
  // }

  // for (int i = 0; i < n; i++) {
  //   printf("%s\n", buf[i]);
  // }

  // char (*buf)[n + 1] = calloc('\0', sizeof(char) * n * (n + 1));
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j <= i; j++) {
  //     buf[i][j] = '*';
  //   }
  // }

  // for (int i = 0; i < n; i++) {
  //   printf("%s\n", buf[i]);
  // }
  // free(buf);

  // char (*buf)[n + 1] = malloc(sizeof(char) * n * (n + 1));
  // memset(buf, '\0', sizeof(char) * n * (n + 1));
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j <= i; j++) {
  //     buf[i][j] = '*';
  //   }
  // }

  // for (int i = 0; i < n; i++) {
  //   printf("%s\n", buf[i]);
  // }
  // free(buf);

  fclose(fd);
  return 0;
}