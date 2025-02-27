#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int* items;
  int front;
  int rear;
  int size;
} queue;

void initQueue(queue* q, int* len) {
  q->front = -1;
  q->rear = -1;
  q->size = *len;
  q->items = (int*)malloc(q->size * sizeof(int));
}

int isEmpty(queue* q) { return q->front == q->rear; }

int isFull(queue* q) { return q->rear == q->size - 1; }

void push(queue* q, int* v) {
  if (isFull(q)) return;
  q->items[++q->rear] = *v;
}

int pop(queue* q) {
  if (isEmpty(q)) return -1;
  return q->items[++q->front];
}
int size(queue* q) { return q->rear - q->front; }

int front(queue* q) {
  if (isEmpty(q)) return -1;
  return q->items[q->front + 1];
}

int back(queue* q) {
  if (isEmpty(q)) return -1;
  return q->items[q->rear];
}

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  int n;
  fscanf(fd, "%d", &n);

  queue q;
  initQueue(&q, &n);
  for (int i = 0; i < n; i++) {
    char cmd[6];
    fscanf(fd, "%s", cmd);

    if (!strcmp(cmd, "push")) {
      int num;
      fscanf(fd, "%d", &num);
      push(&q, &num);
      continue;
    }

    if (!strcmp(cmd, "pop")) {
      printf("%d\n", pop(&q));
      continue;
    }

    if (!strcmp(cmd, "size")) {
      printf("%d\n", size(&q));
      continue;
    }

    if (!strcmp(cmd, "empty")) {
      printf("%d\n", isEmpty(&q));
      continue;
    }

    if (!strcmp(cmd, "front")) {
      printf("%d\n", front(&q));
      continue;
    }

    if (!strcmp(cmd, "back")) {
      printf("%d\n", back(&q));
      continue;
    }
  }

  free(q.items);
  fclose(fd);
  return 0;
}