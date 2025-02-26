#include <stdio.h>
#include <string.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  int n;
  fscanf(fd, "%d", &n);

  for (int i = 0; i < n; i++) {
    char s[n + 1];
    memset(s, ' ', n);
    s[n] = '\0';

    for (int j = 0; j < i + 1; j++) {
      s[n - j - 1] = '*';
    }
    printf("%s\n", s);
  }

  fclose(fd);
  return 0;
}