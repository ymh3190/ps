#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int i;
  int v;
  struct node *prev, *next;
} node;

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  int n;
  fscanf(fd, "%d", &n);

  node arrs[n];
  for (int i = 0; i < n; i++) {
    arrs[i].i = i;
    fscanf(fd, "%d", &arrs[i].v);
    if (i == 0) {
      arrs[i].prev = &arrs[n - 1];
      arrs[i].next = &arrs[i + 1];
      continue;
    }
    if (i < n - 1) {
      arrs[i].prev = &arrs[i - 1];
      arrs[i].next = &arrs[i + 1];
      continue;
    }
    arrs[i].prev = &arrs[i - 1];
    arrs[i].next = &arrs[0];
  }

  node* curNode = &arrs[0];
  while (1) {
    printf("%d ", curNode->i + 1);
    if (curNode->next == curNode) break;

    curNode->prev->next = curNode->next;
    curNode->next->prev = curNode->prev;

    int i = curNode->v;
    if (i > 0) {
      while (i--) {
        curNode = curNode->next;
      }
      continue;
    }
    while (i++) {
      curNode = curNode->prev;
    }
  }

  fclose(fd);
  return 0;
}