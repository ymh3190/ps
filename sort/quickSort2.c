void swap(int (*a)[2], int (*b)[2]) {
  int t = (*a)[0];
  (*a)[0] = (*b)[0];
  (*b)[0] = t;

  t = (*a)[1];
  (*a)[1] = (*b)[1];
  (*b)[1] = t;
}

struct pos {
  int x;
  int y;
};

int compare(const void* a, const void* b) {
  struct pos p1 = *(struct pos*)a;
  struct pos p2 = *(struct pos*)b;

  if (p1.x > p2.x)
    return 1;
  else if (p1.x == p2.x) {
    if (p1.y > p2.y)
      return 1;
    else
      return -1;
  }
  return -1;
}
