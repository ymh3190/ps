#include <stdio.h>

void push(int arrs[], int* len, int v) { arrs[(*len)++] = v; }
int pop(int arrs[], int* len) { return arrs[--(*len)]; }

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  int n;
  fscanf(fd, "%d", &n);

  int arrs[n];
  int len = 0;
  int num = 1;
  for (int i = 0; i < n; i++) {
    int t;
    fscanf(fd, "%d", &t);

    if (t == num) {
      num++;
    } else {
      push(arrs, &len, t);
    }
    while (len > 0 && arrs[len - 1] == num) {
      pop(arrs, &len);
      num++;
    }
  }
  printf(!len ? "Nice" : "Sad");

  fclose(fd);
  return 0;
}