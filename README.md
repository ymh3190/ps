# PS

File\* fd;
fd = fopen("input.txt", "r");
int a;
fscanf(fd, "%d", &a);
fclose(fd);

scanf
short - %hd: half decimal

printf
%f, %lf, %.9lf

char[]
\0: 문자열의 끝을 나타냄

삼중자
??!: ?\?!

char
scanf("%hhd", ...);

윈도우의 기본 스택 크기는 1MB
char buf[1000000][6] => 6MB
따라서 static 변수, 전역 변수, 힙 할당 중에서 선택해서 해결

char (\*buf)[6] = (char (\*)[6])malloc(sizeof(char) \* 1000000 \* 6);

<string.h>
memset

char buf[101] = {' '};
buf[0]만 공백으로 초기화되고 나머지는 0으로 초기화됨

EOF: end of file, -1
