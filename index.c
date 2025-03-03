#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int i;
  int v;
  struct node* prev;
  struct node* next;
} node;

typedef struct deque {
  node* front;
  node* rear;
  int size;
} deque;

void initDeque(deque* d, int n) {
  d->front = NULL;
  d->rear = NULL;
  d->size = n;
}

int isEmpty(deque* d) { return d->size = 0; }

void insertRear(deque* d, int i, int v) {
  node* newNode = (node*)malloc(sizeof(node));
  newNode->i = i;
  newNode->v = v;
  newNode->next = NULL;

  if (isEmpty(d)) {
    newNode->prev = NULL;
    d->front = newNode;
    d->rear = newNode;
    return;
  }

  newNode->prev = d->rear;
  d->rear->next = newNode;
  d->rear = newNode;
}

node* deleteFront(deque* d) {
  if (isEmpty(d)) return NULL;
  node* tmpNode = d->front;
  d->front = d->front->next;
  if (d->front) {
    d->front->prev = NULL;
  } else {
    d->rear = NULL;
  }
  return tmpNode;
}

void removeNode(deque* d, node* node) {
  if (!node) return;
  if (node->prev) node->prev->next = node->next;
  if (node->next) node->next->prev = node->prev;
  if (d->front == node) d->front = node->next;
  if (d->rear == node) d->rear = node->prev;
  free(node);
  d->size--;
}

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  int n;
  fscanf(fd, "%d", &n);

  deque d;
  initDeque(&d, n);

  for (int i = 0; i < n; i++) {
    int v;
    fscanf(fd, "%d", &v);
    insertRear(&d, i + 1, v);
  }

  node* curNode = d.front;
  for (int i = 0; i < n; i++) {
    printf("%d ", curNode->i);
    int m = curNode->v;
    node* tmpNode = curNode;

    removeNode(&d, curNode);
    if (isEmpty(&d)) break;

    if (m > 0) {
      for (int j = 0; j < m; j++) {
        curNode = curNode->next ? curNode->next : d.front;
      }
    } else {
      for (int j = -m; j < 0; j++) {
        curNode = curNode->prev ? curNode->prev : d.rear;
      }
    }
  }

  fclose(fd);
  return 0;
}