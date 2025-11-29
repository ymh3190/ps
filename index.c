#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  int n;
  fscanf(fd, "%d", &n);

  // 2d
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

  // calloc
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

  // malloc & memset
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

  // fix size
  // char buf[101] = {'\0'};
  // for (int i = 0; i < n; i++) {
  //   buf[i] = '*';
  //   printf("%s\n", buf);
  // }

  // char buf[n + 1];
  // for (int i = 0; i < n; i++) {
  //   buf[i] = '*';
  //   buf[i + 1] = '\0';
  //   printf("%s\n", buf);
  // }

  // O(N)
  // char buf[n + 1];
  // for (int i = 0; i < n - 1; i++) {
  //   buf[i] = ' ';
  // }
  // buf[n] = '\0';

  // for (int i = 0; i < n; i++) {
  //   buf[n - 1 - i] = '*';
  //   printf("%s\n", buf);
  // }

  // memset
  // char buf[101];
  // memset(buf, ' ', n);
  // buf[n] = '\0';
  // for (int i = 0; i < n; i++) {
  //   buf[n - 1 - i] = '*';
  //   printf("%s\n", buf);
  // }

  fclose(fd);
  return 0;
}