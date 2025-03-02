#include <stdio.h>
#include <stdlib.h>

typedef struct deque {
  int* arrs;
  int front;
  int rear;
  int size;
} deque;

void initDeque(deque* d, int n) {
  d->front = -1;
  d->rear = -1;
  d->size = n;
  d->arrs = (int*)malloc(d->size * sizeof(int));
}

int isEmpty(deque* d) { return d->front == -1; }

int isFull(deque* d) {
  return (d->front == 0 && d->rear == d->size - 1) || (d->front == d->rear + 1);
}

void insertFront(deque* d, int v) {
  if (isFull(d)) return;

  if (d->front == -1) {
    d->front = 0;
    d->rear = 0;
  } else if (d->front == 0) {
    d->front = d->size - 1;
  } else {
    d->front--;
  }

  d->arrs[d->front] = v;
}

void insertRear(deque* d, int v) {
  if (isFull(d)) return;

  if (d->rear == -1) {
    d->front = 0;
    d->rear = 0;
  } else if (d->rear == d->size - 1) {
    d->rear = 0;
  } else {
    d->rear++;
  }

  d->arrs[d->rear] = v;
}

int deleteFront(deque* d) {
  if (isEmpty(d)) return -1;

  int v = d->arrs[d->front];

  if (d->front == d->rear) {
    d->front = -1;
    d->rear = -1;
  } else if (d->front == d->size - 1) {
    d->front = 0;
  } else {
    d->front++;
  }
  return v;
}

int deleteRear(deque* d) {
  if (isEmpty(d)) return -1;

  int v = d->arrs[d->rear];

  if (d->rear == d->front) {
    d->front = -1;
    d->rear = -1;
  } else if (d->rear == 0) {
    d->rear = d->size - 1;
  } else {
    d->rear--;
  }
  return v;
}

int getSize(deque* d) {
  if (isEmpty(d)) return 0;
  if (d->rear >= d->front) return d->rear - d->front + 1;
  return d->size - (d->front - d->rear - 1);
}

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  int n;
  fscanf(fd, "%d", &n);

  deque d;
  initDeque(&d, n);

  for (int i = 0; i < n; i++) {
    int cmd;
    fscanf(fd, "%d", &cmd);

    if (cmd == 1) {
      int num;
      fscanf(fd, "%d", &num);
      insertFront(&d, num);
      continue;
    }

    if (cmd == 2) {
      int num;
      fscanf(fd, "%d", &num);
      insertRear(&d, num);
      continue;
    }

    if (cmd == 3) {
      printf("%d\n", deleteFront(&d));
      continue;
    }

    if (cmd == 4) {
      printf("%d\n", deleteRear(&d));
      continue;
    }

    if (cmd == 5) {
      printf("%d\n", getSize(&d));
      continue;
    }

    if (cmd == 6) {
      printf("%d\n", isEmpty(&d));
      continue;
    }

    if (cmd == 7) {
      printf("%d\n", isEmpty(&d) ? -1 : d.arrs[d.front]);
      continue;
    }

    if (cmd == 8) {
      printf("%d\n", isEmpty(&d) ? -1 : d.arrs[d.rear]);
      continue;
    }
  }

  free(d.arrs);
  fclose(fd);
  return 0;
}