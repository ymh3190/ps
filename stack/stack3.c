#include <stdio.h>
#include <string.h>

void push(char arrs[], int* len, char v) { arrs[(*len)++] = v; }
char pop(char arrs[], int* len) {
  if (!*len) return -1;
  return arrs[--(*len)];
}

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  char arrs[102];
  while (fgets(arrs, sizeof(arrs), fd) && arrs[0] != '.') {
    arrs[strcspn(arrs, "\n")] = '\0';

    int flag = 0;
    int len = 0;
    char rets[102];

    for (int i = 0; i < strlen(arrs); i++) {
      if (arrs[i] == ' ') continue;

      if (arrs[i] == '(' || arrs[i] == '[') {
        push(rets, &len, arrs[i]);
      } else if (arrs[i] == ')' && pop(rets, &len) != '(') {
        flag = 1;
        break;
      } else if (arrs[i] == ']' && pop(rets, &len) != '[') {
        flag = 1;
        break;
      }
    }

    if (len > 0) flag = 1;
    printf(flag ? "no\n" : "yes\n");
  }

  fclose(fd);
  return 0;
}