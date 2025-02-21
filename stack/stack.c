#include <stdio.h>

void push(int arrs[], int *len, int v) {
  arrs[*len] = v;
  (*len)++;
  //   *len += 1;
}

int pop(int arrs[], int *len) {
  int index = *len - 1;
  if (index < 0) return -1;
  int num = arrs[index];
  arrs[index] = 0;
  (*len)--;
  return num;
}

int getSize(int *len) { return *len; }

int isEmpty(int *len) { return *len == 0 ? 1 : 0; }

int get(int arrs[], int *len) {
  int index = *len - 1;
  if (index < 0) return -1;
  return arrs[index];
}

int main() {
  FILE *fd;
  fd = fopen("input.txt", "r");

  int n;
  fscanf(fd, "%d", &n);

  int arrs[n];
  for (int i = 0; i < n; i++) {
    arrs[i] = 0;
  }

  int len = 0;
  for (int i = 0; i < n; i++) {
    int cmd;
    fscanf(fd, "%d", &cmd);

    if (cmd == 1) {
      int num;
      fscanf(fd, "%d", &num);
      push(arrs, &len, num);
      continue;
    }

    if (cmd == 2) {
      printf("%d\n", pop(arrs, &len));
      continue;
    }

    if (cmd == 3) {
      printf("%d\n", getSize(&len));
      continue;
    }

    if (cmd == 4) {
      printf("%d\n", isEmpty(&len));
      continue;
    }

    if (cmd == 5) {
      printf("%d\n", get(arrs, &len));
      continue;
    }
  }

  fclose(fd);
  return 0;
}