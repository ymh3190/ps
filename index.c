#include <stdio.h>

int main() {
  FILE* fd;
  fd = fopen("input.txt", "r");

  int size = 1000001;
  char buf[size];
  fscanf(fd, "%s", buf);

  int arr[26] = {0};
  for (int i = 0; i < size; i++) {
    if (buf[i] == '\0') break;
    if (buf[i] >= 'a' && buf[i] <= 'z') {
      arr[buf[i] - 97]++;
      continue;
    }
    if (buf[i] >= 'A' && buf[i] <= 'Z') {
      arr[buf[i] - 65]++;
      continue;
    }
  }

  int m = arr[0];
  int idx = 0;
  for (int i = 1; i < 26; i++) {
    if (arr[i] > m) {
      m = arr[i];
      idx = i;
    }
  }

  int flag = 0;
  for (int i = 0; i < 26; i++) {
    if (arr[i] == m) flag++;
  }

  printf("%c", flag > 1 ? '?' : idx + 65);

  // 틀린 코드
  // int arr[26];
  // for (int i = 0; i < 26; i++) {
  //   arr[i] = 0;
  // }

  // for (int i = 0; i < size; i++) {
  //   if (buf[i] == '\0') break;
  //   if (buf[i] >= 'a' && buf[i] <= 'z') {
  //     buf[i] -= 97;
  //     continue;
  //   }
  //   if (buf[i] >= 'A' && buf[i] <= 'Z') {
  //     buf[i] -= 65;
  //     continue;
  //   }
  // }

  // for (int i = 0; i < size; i++) {
  //   if (buf[i] == '\0') break;
  //   arr[(int)buf[i]]++;  // 여기서 잘못됨
  // }

  // int m = arr[0];
  // int idx = 0;
  // for (int i = 1; i < 26; i++) {
  //   if (arr[i] > m) {
  //     m = arr[i];
  //     idx = i;
  //   }
  // }

  // int flag = 0;
  // for (int i = 0; i < 26; i++) {
  //   if (arr[i] == m) flag++;
  // }

  // printf("%c", flag > 1 ? '?' : idx + 65);

  fclose(fd);
  return 0;
}