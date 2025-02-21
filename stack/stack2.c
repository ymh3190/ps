#include <stdio.h>

void push(int arrs[], int* len, int v) { arrs[(*len)++] = v; }

int pop(int arrs[], int* len) {
  if (*len - 1 < 0) return -1;
  return arrs[--(*len)];
}

int isEmpty(int arrs[], int* len) {
  if (!(*len)) return 1;
  return 0;
}

int get(int arrs[], int* len) {
  if (*len - 1 < 0) return -1;
  return arrs[*len - 1];
}

int main() {
  int n;
  scanf("%d", &n);

  int arrs[n], len = 0;
  for (int i = 0; i < n; i++) {
    int cmd;
    scanf("%d", &cmd);

    if (cmd == 1) {
      int num;
      scanf("%d", &num);
      push(arrs, &len, num);
      continue;
    }

    if (cmd == 2) {
      printf("%d\n", pop(arrs, &len));
      continue;
    }

    if (cmd == 3) {
      printf("%d\n", len);
      continue;
    }

    if (cmd == 4) {
      printf("%d\n", isEmpty(arrs, &len));
      continue;
    }

    if (cmd == 5) {
      printf("%d\n", get(arrs, &len));
      continue;
    }
  }

  return 0;
}