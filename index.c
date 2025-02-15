#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  char* key;
  char* value;
  struct node* next;
};

struct hashMap {
  int capacity;
  int numOfElements;
  struct node** arrs;
};

void setNode(struct node* node, char* key, char* value) {
  node->key = key;
  node->value = value;
  node->next = NULL;
}

void initializeHashMap(struct hashMap* mp) {
  mp->capacity = 100;
  mp->numOfElements = 0;
  mp->arrs = (struct node**)malloc(mp->capacity * sizeof(struct node*));
}

int hashFunction(struct hashMap* mp, char* key) {
  int bucketIndex;
  int sum = 0;
  int factor = 31;
  for (int i = 0; i < strlen(key); i++) {
    sum = ((sum % mp->capacity) + (((int)key[i] * factor) % mp->capacity)) %
          mp->capacity;
    factor = ((factor % __INT16_MAX__) + (31 % __INT16_MAX__)) % __INT16_MAX__;
  }
  bucketIndex = sum;
  return bucketIndex;
}

void insert(struct hashMap* mp, char* key, char* value) {
  int bucketIndex = hashFunction(mp, key);
  struct node* newNode = (struct node*)malloc(sizeof(struct node));
  setNode(newNode, key, value);
  if (!mp->arrs[bucketIndex]) {
    mp->arrs[bucketIndex] = newNode;
    return;
  }
  newNode->next = mp->arrs[bucketIndex];
  mp->arrs[bucketIndex] = newNode;
}

void delete(struct hashMap* mp, char* key) {
  int bucketIndex = hashFunction(mp, key);
  struct node* preNode = NULL;
  struct node* curNode = mp->arrs[bucketIndex];
  while (curNode) {
    if (!strcmp(key, curNode->key)) {
      if (curNode == mp->arrs[bucketIndex]) {
        mp->arrs[bucketIndex] = curNode->next;
      } else {
        preNode = curNode->next;
      }
      free(curNode);
      break;
    }
    preNode = curNode;
    curNode = curNode->next;
  }
}

char* search(struct hashMap* mp, char* key) {
  int bucketIndex = hashFunction(mp, key);
  struct node* bucketHead = mp->arrs[bucketIndex];
  while (bucketHead) {
    if (!strcmp(key, bucketHead->key)) return bucketHead->value;
    bucketHead = bucketHead->next;
  }
  char* errMsg = (char*)malloc(sizeof(char) * 25);
  errMsg = "Key not found\n";
  return errMsg;
}

int main() {
  struct hashMap* mp = (struct hashMap*)malloc(sizeof(struct hashMap));
  initializeHashMap(mp);

  insert(mp, "Yogaholic", "Anjali");
  insert(mp, "pluto14", "Vartika");
  insert(mp, "elite_Programmer", "Manish");
  insert(mp, "GFG", "GeeksforGeeks");
  insert(mp, "decentBoy", "Mayank");

  printf("%s\n", search(mp, "elite_Programmer"));
  printf("%s\n", search(mp, "Yogaholic"));
  printf("%s\n", search(mp, "pluto14"));
  printf("%s\n", search(mp, "decentBoy"));
  printf("%s\n", search(mp, "GFG"));

  printf("%s\n", search(mp, "randomKey"));

  printf("\nAfter deletion : \n");

  delete (mp, "decentBoy");
  printf("%s\n", search(mp, "decentBoy"));
  return 0;
}