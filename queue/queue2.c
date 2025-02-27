#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
  int* arrs;
  int front;
  int rear;
  int size;
} queue;

void initQueue(queue* q, int* n) {
  q->front = -1;
  q->rear = -1;
  q->size = *n + (*n - 1);
  q->arrs = (int*)malloc(q->size * sizeof(int));
}

int isEmpty(queue* q) { return q->front == q->rear; }

int isFull(queue* q) { return q->rear == q->size - 1; }

void enqueue(queue* q, int v) { q->arrs[++q->rear] = v; }

int dequeue(queue* q) { return q->arrs[++q->front]; }

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  int n;
  fscanf(fd, "%d", &n);

  queue q;
  initQueue(&q, &n);

  for (int i = 0; i < n; i++) {
    enqueue(&q, i + 1);
  }

  int ret;
  while (1) {
    ret = dequeue(&q);
    if (isEmpty(&q)) break;
    ret = dequeue(&q);
    enqueue(&q, ret);
  }

  printf("%d", ret);

  free(q.arrs);
  fclose(fd);
  return 0;
}