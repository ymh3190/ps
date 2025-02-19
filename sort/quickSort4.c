#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char t[1000 * 1001 / 2][1001];

int compare(const void* a, const void* b) { return strcmp((char*)a, (char*)b); }

// int main() {
//   FILE* fd;
//   fd = fopen("input.txt", "r");

//   char s[1001];
//   fscanf(fd, "%s", s);
//   int n = strlen(s);

//   int index = 0;
//   for (int i = 0; i < n; i++) {
//     for (int j = 1; j < n - i + 1; j++) {
//       strncpy(t[index], s + i, j);
//       t[index][j] = '\0';
//       index++;
//     }
//   }
//   qsort(t, index, sizeof(t[0]), compare);

//   int ret = 1;
//   for (int i = 1; i < index; i++) {
//     if (strcmp(t[i], t[i - 1])) ret++;
//   }
//   printf("%d", ret);

//   fclose(fd);

//   return 0;
// }