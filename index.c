#include <stdio.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  char buf[100];
  fscanf(fd, "%s", buf);

  int arrs[26];
  for (int i = 0; i < 26; i++) {
    arrs[i] = -1;
  }

  for (int i = 0; i < 100; i++) {
    if (buf[i] == '\0') break;
    for (int j = 0; j < 26; j++) {
      if (arrs[j] == -1 && j + 97 == buf[i]) {
        arrs[j] = i;
        break;
      }
    }
  }

  for (int i = 0; i < 26; i++) {
    printf("%d ", arrs[i]);
  }
  fclose(fd);
  return 0;
}