typedef struct {
  int len;
  char s[51];
} str;

int compare(const void* a, const void* b) {
  str x = *(str*)a;
  str y = *(str*)b;

  if (x.len < y.len)
    return -1;
  else if (x.len > y.len)
    return 1;
  return strcmp(x.s, y.s);
}