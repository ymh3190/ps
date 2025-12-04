#include <stdio.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  char t[51];
  float g;
  char s[3];
  float sum = 0;
  float b = 0;

  for (int i = 0; i < 20; i++) {
    fscanf(fd, "%s %f %s", t, &g, s);
    if (s[0] == 'P') continue;
    b += g;
    if (s[0] == 'A' && s[1] == '+') {
      sum += g * 4.5;
      continue;
    }
    if (s[0] == 'A' && s[1] == '0') {
      sum += g * 4.0;
      continue;
    }
    if (s[0] == 'B' && s[1] == '+') {
      sum += g * 3.5;
      continue;
    }
    if (s[0] == 'B' && s[1] == '0') {
      sum += g * 3.0;
      continue;
    }
    if (s[0] == 'C' && s[1] == '+') {
      sum += g * 2.5;
      continue;
    }
    if (s[0] == 'C' && s[1] == '0') {
      sum += g * 2.0;
      continue;
    }
    if (s[0] == 'D' && s[1] == '+') {
      sum += g * 1.5;
      continue;
    }
    if (s[0] == 'D' && s[1] == '0') {
      sum += g * 1.0;
      continue;
    }
  }

  printf("%f", sum / b);
  fclose(fd);
  return 0;
}