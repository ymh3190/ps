#include <stdio.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  char buf[101];
  fscanf(fd, "%s", buf);

  int c = 0;
  for (int i = 0; i < 101; i++) {
    if (buf[i] == '\0') break;
    if (buf[i] == 'c' && (buf[i + 1] == '=' || buf[i + 1] == '-')) {
      c++;
      i += 1;
      continue;
    }
    if (buf[i] == 'd' && (buf[i + 1] == '-')) {
      c++;
      i += 1;
      continue;
    }
    if (buf[i] == 'd' && buf[i + 1] == 'z' && buf[i + 2] == '=') {
      c++;
      i += 2;
      continue;
    }
    if (buf[i] == 'l' && buf[i + 1] == 'j') {
      c++;
      i += 1;
      continue;
    }
    if (buf[i] == 'n' && buf[i + 1] == 'j') {
      c++;
      i += 1;
      continue;
    }
    if ((buf[i] == 's' || buf[i] == 'z') && buf[i + 1] == '=') {
      c++;
      i += 1;
      continue;
    }
    c++;
  }

  printf("%d", c);
  fclose(fd);
  return 0;
}