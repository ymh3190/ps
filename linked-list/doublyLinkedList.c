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

  node node[n];
  for (int i = 0; i < n; i++) {
    node[i].i = i;
    fscanf(fd, "%d", &node[i].v);
    if (i == 0) {
      node[i].prev = &node[n - 1];
      node[i].next = &node[i + 1];
    } else if (i < n - 1) {
      node[i].prev = &node[i - 1];
      node[i].next = &node[i + 1];
    } else {
      node[i].prev = &node[n - 2];
      node[i].next = &node[0];
    }
  }

  struct node* curNode = &node[0];
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
    } else {
      while (i++) {
        curNode = curNode->prev;
      }
    }
  }

  fclose(fd);
  return 0;
}