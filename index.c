#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  char* key;
  struct node* next;
} node;

typedef struct hashMap {
  int capacity;
  node** arrs;
} hashMap;

void setNode(node* node, char* key) {
  node->key = key;
  node->next = NULL;
}

void initializeHashMap(hashMap* mp, int n) {
  mp->capacity = n * (n + 1) / 2;
  mp->arrs = (node**)malloc(mp->capacity * sizeof(node*));
}

int hashFunction(hashMap* mp, char* key) {
  int bucketIndex;
  int sum = 0;
  int factor = 31;
  for (int i = 0; i < strlen(key); i++) {
    sum = ((sum % mp->capacity) + (((int)key[i]) * factor) % mp->capacity) %
          mp->capacity;
    factor = ((factor % __INT16_MAX__) * (31 % __INT16_MAX__)) % __INT16_MAX__;
  }
  bucketIndex = sum;
  return bucketIndex;
}

int insert(hashMap* mp, char* key) {
  char* s = strdup(key);
  int bucketIndex = hashFunction(mp, s);

  node* curNode = mp->arrs[bucketIndex];
  while (curNode) {
    if (!strcmp(curNode->key, s)) return 0;
    curNode = curNode->next;
  }

  node* newNode = (node*)malloc(sizeof(node));
  setNode(newNode, s);
  newNode->next = mp->arrs[bucketIndex];
  mp->arrs[bucketIndex] = newNode;
  return 1;
}

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  char s[1001];
  fscanf(fd, "%s", s);
  int n = strlen(s);

  hashMap* mp = (hashMap*)malloc(sizeof(hashMap));
  initializeHashMap(mp, n);

  int ret = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < n - i + 1; j++) {
      char t[1001];
      strncpy(t, s + i, j);
      t[j] = '\0';
      ret += insert(mp, t);
    }
  }
  printf("%d\n", ret);

  ret = 0;
  for (int i = 0; i < mp->capacity; i++) {
    if (mp->arrs[i]) {
      printf("%p ", mp->arrs[i]);
      ret++;
      if (mp->arrs[i]->next) {
        printf("\n%p ", mp->arrs[i]->next);
        ret++;
        if (mp->arrs[i]->next->next) {
          printf("\n%p ", mp->arrs[i]->next->next);
          ret++;
          if (mp->arrs[i]->next->next->next) {
            printf("\n%p ", mp->arrs[i]->next->next->next);
            ret++;
          }
        }
      }
    }
  }
  printf("\n%d", ret);

  free(mp);
  fclose(fd);

  return 0;
}