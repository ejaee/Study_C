# step_1 입출력과 사칙연산

#### 1. printf 출력 함수
```
  printf("");
```
#### 2. 줄바꿈
```
  \n 으로 줄바꿈이 가능
```
#### 3. printf 함수 안에서 \ 출력
```
  \를 두번 적으면 출력 가능
  //TXT파일로 push하면 코드가 적용되지 않는구나...!
```
#### 4. print 함수 안에서 " 출력
```
  \뿐만 아니라 "도 출력하고 싶다면 \를 함께 적어주면 출력 가능
  ex) printf("\\ \"\n"); -> \ "
```
#### 5. scanf 입력 함수
```
  scanf("%d %d", &A, &B)
```
#### 6. 5와 동일
#### 7. 5와 동일
#### 8. 실수 출력
```
  <소수점을 나타내는 실수형 float, double 메모리 크기>
  printf("float = %lu\n",sizeof(f)); -->  4byte(32)
  printf("double = %lu\n",sizeof(d)); -->  8byte(64)
  printf("sizeof(0.1) = %lu byte\n",sizeof(0.1)); --> Default 값은 double 이다
  
  float는 소수점 이하 6자리까지 표시
  double은 소수점 이하 15자리까지 표시
  
  출력하고 싶은 소숫점 이하 자리수를 지정하는 법 = %와 f 사이에 .n(자릿수)을 표시
  printf("%.2f\n", 12.3456) --> 12.35 (3번째 자리에서 반올림)
```
  * 형 변환을 통한 실수값 출력
```
  #include <stdio.h>
  int main() {
  int a, b;
  float c, d;

  printf("두 숫자 입력 : ");
  scanf("%d %d", &a, &b);

  c = a / b;  // 둘다 정수형 변수라면 몫을 계산한다
  d = (float)a / b;  // 어느 하나가 실수형 변수가 되면 실수값을 가진다

  printf("두 수의 비율 : %f %f", c, d);
  return 0;
}
--> 두 숫자 입력 : 5 3
    두 수의 비율 : 1.000000 1.666667
```
#### 10. 나머지값 출력 (모듈러 연산)
```
  %를 활용하여 나머지값 출력
```
  * 모듈러 연산(Modular Arithmetic) 속성과 증명
```
  17 % 3 = 2
  17 mod 3 = 2
  
  문제의 case 4
  1. (A+B) %C
  2. (A%C + B%C)%C 
  3. (A*B)%C 
  4. (A%C * B%C)%C  
  
  속성 1 --> (A+B) %C = (A%C + B%C)%C
  속성 2 --> (A*B) %C = (A%C * B%C)%C
```
  * [증명 1] : (A+B) %C = (A%C + B%C)%C
<img src="https://user-images.githubusercontent.com/87407504/134110673-cd9f3180-6876-4982-8612-0c16b4f5d704.png" width="400" height="210">

  * [증명 2] : (A*B) %C = (A%C * B%C)%C
<img src="https://user-images.githubusercontent.com/87407504/134111277-c61ab533-68e3-4286-a576-329e90dbb8e2.png" width="400" height="210">

#### 11. 하나로 입력된 문자를 분리하여 연산하기
```
나머지와 나눗셈 연산을 통해 각 자릿수를 사용

[심화]
문자열로 입력받아 문자열의 인덱스 위치상의 문자값으로 반환하여 하나씩 분리하는 방법

1. char[]로 문자열을 다뤄 string[index]로 하나씩 꺼낸다
2. 문자열을 이용하여 string.at() 또는 string[index]로 하나씩 꺼낸다
두가지 방법 모두 문자열로 입력받는데 마지막 출력에서 연산을 해야하기 때문에 int형으로 변환해주어야 한다

[풀이 1]
int a; --> scanf("%d", &a);
char b[4]; --> scanf("%s", b);
문자열 b의 인덱스 위치에 있는 문자 값을 반환한다
이때 반환되는 값은 아스키 코드값인 문자(char)이다
즉, char b[4] = "385"; 에서 int result = b[0] 이라면 
result는 3이 아니라 문자 '3' 이며 아스키 코드 값으로 51이다
아스키 코드 값을 숫자값으로 바꾸기 위한 skill은 '0'(48)을 빼주는 것이다
'3'(51) - '0'(48) = 3 을 이용하여 아래와 같이 해결한다
printf("%d/n", a*(b[2]-'0'));
printf("%d/n", a*(b[1]-'0'));
printf("%d/n", a*(b[0]-'0'));

결과값을 출력하기 위해 문자열을 숫자로 바꾸는 함수를 사용한다 --> atoi() by <stdlib.h>
printf("%d/n", a*atoi(b));
```

#### etc.

