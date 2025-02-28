#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
  int* arrs;
  int front;
  int rear;
  int size;
} queue;

void initQueue(queue* q, int n) {
  q->front = 0;
  q->rear = -1;
  q->size = n;
  q->arrs = (int*)malloc(q->size * sizeof(int));
}

int isEmpty(queue* q) { return q->front == q->rear + 1; }
int isFull(queue* q) { return q->rear == q->size - 1; }

void enqueue(queue* q, int v) { q->arrs[++q->rear] = v; }
int dequeue(queue* q) { return q->arrs[q->front++]; }

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  int n, k;
  fscanf(fd, "%d %d", &n, &k);

  if (n == 1) {
    printf("<1>");
    return 0;
  }

  queue q;
  initQueue(&q, k * n);

  for (int i = 0; i < n; i++) {
    enqueue(&q, i + 1);
  }

  int i = 0;
  int rets[n];
  while (1) {
    if (q.front % k < k - 1) {
      enqueue(&q, dequeue(&q));
    } else if (q.front % k == k - 1) {
      rets[i++] = dequeue(&q);
      if (isEmpty(&q)) break;
    }
  }

  for (int i = 0; i < n; i++) {
    if (i == 0)
      printf("<%d, ", rets[i]);
    else if (i < n - 1) {
      printf("%d, ", rets[i]);
    } else {
      printf("%d>", rets[i]);
    }
  }

  free(q.arrs);
  fclose(fd);
  return 0;
}