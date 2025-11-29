#include <stdio.h>
#include <stdlib.h>
// #include <string.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  int n;
  fscanf(fd, "%d", &n);

  // char buf[n + 1];
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j <= i; j++) {
  //     buf[j] = '*';
  //   }
  //   for (int j = n - 1; j > i; j--) {
  //     buf[j] = '\0';
  //   }
  //   printf("%s\n", buf);
  // }

  // char* buf = malloc(sizeof(char) * (n + 1));
  // memset(buf, '\0', n + 1);
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j <= i; j++) {
  //     buf[j] = '*';
  //   }
  //   printf("%s\n", buf);
  // }

  char* buf = calloc('\0', sizeof(char) * (n + 1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      buf[j] = '*';
    }
    printf("%s\n", buf);
  }

  free(buf);
  fclose(fd);
  return 0;
}