# strstr
### 함수

```.c
#include <string.h>  // C++ 에서는 <cstring>

const char* strstr(const char* str1, const char* str2);
char* strstr(char* str1, const char* str2);
```

-  str1에서 str2를 검색하여 가장먼저 나타나는 곳의 위치를 리턴

### 인자

-  str1

```
검색이 수행되는 C형식 문자열
```

-  str2

```
찾을 C형식 문자열
```

-  리턴값

```
str1에서 str2를 찾았다면 가장 먼저 나오는 곳의 위치 리턴
존재하지 않는다면 널 포인터를 리턴
```
### 실행 예제
```.c
#include <stdio.h>
#include <string.h>

int main()
{
    char s1[30] = "A Garden Diary";     // 크기가 30인 char형 배열을 선언하고 문자열 할당

    char *ptr = strstr(s1, "den");      // den으로 시작하는 문자열 검색, 포인터 반환

    printf("%s\n", ptr);    // den Diary

    return 0;
}
```
<img width="97" alt="스크린샷 2021-11-24 오후 9 18 51" src="https://user-images.githubusercontent.com/87407504/143237177-428cc4ee-dcd7-4981-9d6d-e20e3c23bcd3.png"><br>

