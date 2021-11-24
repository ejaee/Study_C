# sscanf
### 함수

```.c
#include <stdio.h>  // C++ 에서는 <cstdio>

int sscanf(const char* str, const char* format, ...);
```

-  문자열에서 형식화 된 데이터를 읽어온다

### 인자

-  str

```
sscanf 함수가 데이터를 얻어올 문자열
```

-  format

```
int형 10진수일 경우 "%d"와 같이 원하는 타입
```

-  부수적 인자

```
인자가 가리키는 메모리 공간에 데이터를 집어 넣는다
부수적 인자들은 포인터의 형태(주소값)여야 한다
```
### sscanf 함수를 이용하여 문자열을 수로 바꾸기
```.c
#include <stdio.h>
int main() {
  char str[30] = "1234";
  int i;

  sscanf(str, "%d", &i);

  printf("Number from : '%s' \n", str);
  printf("number : %d \n", i);

  return 0;
}
```
<img width="315" alt="스크린샷 2021-11-24 오후 8 44 00" src="https://user-images.githubusercontent.com/87407504/143232419-f29951ea-619f-43b8-9340-c6796236057a.png"><br>
> str에서 sscanf함수로 %d 형식, 즉 정수 형식으로 수를 읽어오면 이 값을 i에 저장한다
> 리턴값으로 읽어들인 것의 개수를 리턴한다(지정 형식과 일치하는 데이터가 업는경우 0)
> atoi 함수를 통해 문자열을 수로 바꿀수도 있지만 형식에 따라 atoi, atof 등 세분화해야한다
```.c
#include <stdio.h>
int main() {
  char sentence[] = "Rudolph is 12 years old";
  char str[20];
  int i;
  sscanf(sentence, "%s %*s %d", str, &i);
  printf("%s -> %d\n", str, i);
  return 0;
}
```
<img width="140" alt="스크린샷 2021-11-24 오후 9 07 12" src="https://user-images.githubusercontent.com/87407504/143235530-e9efa91d-f9a3-4406-8221-46cac159fc37.png"><br>



