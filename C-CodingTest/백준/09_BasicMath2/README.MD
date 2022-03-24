## :pencil: [4_1929.c](https://www.acmicpc.net/problem/1929)
### [소수 구하기](https://github.com/Ejaeda/Coding_Test/blob/master/백준/Step09_기본수학2/4_1929.c)<br>
<img width="641" alt="스크린샷 2021-11-21 오후 6 47 55" src="https://user-images.githubusercontent.com/87407504/142757243-eb44f206-dcd4-41ed-a9c2-c42d6650f731.png"><br>
* 핵심
```
숫자의 범위를 입력받고 범위 내의 소수들을 출력
```
* 문제접근
```
1. 범위가 1000000이므로 시간초과를 해결하기 위해 에라스토테네스의 체를 활용
2를 제외한 2의 배수는 모두 소수가 아니므로 배수의 값은 1을 부여
2. 0을 값을 가진 배열만 출력
3. 1은 소수가 아니므로 1을 부여
```
> [에라스토테네스 체](#에라스토테네스의-체)
* 코드구현
```.c
1.
#include <stdio.h>
int main(){
    int M, N, idx;
    int arr[1000001] = {0, };
    arr[1] = 1;
    
    scanf("%d %d", &M, &N);
    
    for(idx = 2; idx < N; idx++){
        for(int idx2 = 2; idx * idx2 <= N; idx2++)
            arr[idx * idx2] = 1;
    }
2.
    for(idx = M; idx <= N; idx++)
        if(arr[idx] == 0) printf("%d\n", idx);

    return 0;
}
```
* 특이사항
```
에라스토테네스를 활용시 2부터 N의 배수까지 빼줄 필요없고 N의 제곱근까지만 빼줘도 되는 것으로 알고 있는데
틀렸음
이유 :
```
* 틀린풀이<br>
<img width="590" alt="스크린샷 2021-11-21 오후 6 32 40" src="https://user-images.githubusercontent.com/87407504/142757682-2072d857-9290-4000-b49a-2667f36891ed.png"><br>
```
13의 idx*idx가 문제가 되어 틀렸음
배열의 값이 이미 0이라면 continue를 통해 아래 코드를 무시하는 건 좋았다
위와같이 배열의 값을 출력하기보다 정답풀이와 같이 인덱스의 값을 가져오는 것이 더 좋다!
```
### 에라스토테네스의 체<br>
![img](https://user-images.githubusercontent.com/87407504/142757925-aa04ae0b-9c2e-4ea3-812b-bc4693d48b6b.gif)<br>
```
1. 2부터 소수를 구하고자 하는 구간의 모든 수를 나열한다. 그림에서 회색 사각형으로 두른 수들이 여기에 해당한다.
2. 2는 소수이므로 오른쪽에 2를 쓴다. (빨간색)
3. 자기 자신을 제외한 2의 배수를 모두 지운다.
4. 남아있는 수 가운데 3은 소수이므로 오른쪽에 3을 쓴다. (초록색)
5. 자기 자신을 제외한 3의 배수를 모두 지운다.
위의 과정을 반복하면 구하는 구간의 모든 소수가 남는다.
```
> 1~n까지의 소수를 알고 싶다면, n까지 모든 수의 배수를 다 나눠 볼 필요 없다
```
만약 어떤 수가 m=ab 이라면 a와 b 중 적어도 하나는 루트(n) 이하 
즉 n보다 작은 합성수 m은 루트(n)보다 작은 수의 배수만 체크해도 전부 지워진다는 의미이므로, 
이하의 수의 배수만 지우면 됩니다.
```
> <기존>
```.c
for (int i = 2; i < num; i++)
```
> <개선>
```.c
for (int i = 2; i < sqrt(num); i++)
```
## :pencil: [5_4948.c](https://github.com/Ejaeda/Coding_Test/blob/master/백준/Step09_기본수학2/5_4948.c)
### [베르트랑 공준](https://www.acmicpc.net/problem/4948)<br>
<img width="639" alt="스크린샷 2021-11-21 오후 8 07 51" src="https://user-images.githubusercontent.com/87407504/142759369-09347903-043a-49e8-9c20-fc8fd5f4c4d6.png"><br>
* 핵심
```
n이 주어졌을 때 n보다 크고 2n보다 작거나 같은 소수의 개수
```
* 문제접근
```
1. 에라스토테네스의 체를 이용하여 소수 구분
2. 소수는 0 아니면 1의 값을 저장
3. 배열의 값이 0이면 카운트
4. 입력값이 0이 나오면 종료
```
* 코드구현
```.c
1. 2.
#include <stdio.h>
int era(int nb){
    int cnt = 0, arr[250000] = {0, };
    arr[1] = 1;
    for(int idx = 2; idx <= 2*nb; idx++){
        for(int idx2 = 2; idx*idx2 <= 2*nb; idx2++)
            arr[idx*idx2] = 1;
    }
3.
    for(int idx = nb + 1; idx <= 2*nb; idx++)
        if(arr[idx] == 0 )cnt++;
    return (cnt);
}
4.
int main(){
    int try, cnt;

    while(1){
        scanf("%d", &try);
        if (try == 0)
            return 0;
        else
            cnt = era(try);
        printf("%d\n", cnt);
    }
}
```
* 정리
```
에라스토테네스는 확실히 소수의 범위와 관련된 문제에 특화
소수이면 0 아니면 1을 저장하는 방식으로 적용하자
예외처리 1
```
## :pencil: [6_9020.c](https://github.com/Ejaeda/Coding_Test/blob/master/백준/Step09_기본수학2/6_9020.c)
### [골드바흐의 추측](https://www.acmicpc.net/problem/9020)<br>
<img width="663" alt="스크린샷 2021-11-22 오전 12 40 52" src="https://user-images.githubusercontent.com/87407504/142768669-515ff21e-1b1d-480f-bfc8-eb2cfab74446.png"><br>
* 핵심
```
짝수를 두 소수의 합으로 나타낸다
(4 = 2 + 2, 6 = 3 + 3)
n의 골드바흐 파티션이 여러 가지인 경우에는 두 소수의 차이가 가장 작은 것을 출력한다
```
* 문제접근
```
1. 두 소수의 합이 n이되는 소수를 알기 위해서는 우선 n까지의 소수를 구해야한다
-> 에라스토테네스의 체를 활용하여 배열에 저장
2. 두 소수의 차이가 가장 적은 소수들을 어떻게 구할 것인가?
```
* 아이디어
```
2.
n은 짝수이므로 두 수의 차이가 가장 적은 것은 0인 n/2
n = 8이면 4+4부터 3+5 2+6 방식으로 -- ++ 하는 방식을 사용하자
배열상에서 소수는 0의 값을 가지고 있을 것이니 if(arr[idx] != 1&& arr[n - idx] != 1)
```
* 코드구현
```.c
1.
void    erasto(int nb){
    int arr[10001] = {0, 1};

    for(int idx = 2; idx <= nb; idx++)
        for(int idx2 = 2; idx*idx2 < nb; idx2++)
            arr[idx*idx2] = 1;
2.
    for(int idx = nb/2; idx >0; idx--){
        if(arr[idx] != 1&& arr[nb - idx] != 1){
            printf("%d %d\n", idx, nb - idx);
            break;
        }
    }
}
```
## :pencil: [8.3009.c]()
### [네번째 점](https://www.acmicpc.net/problem/3009)
<img width="644" alt="스크린샷 2021-11-22 오전 11 18 55" src="https://user-images.githubusercontent.com/87407504/142791459-123a4d63-0ea7-402f-87d1-0e63ed90cb08.png"><br>
* 핵심
```
두개의 입력값을 세번 받는데 가로 세로의 길이가 다른 하나씩 골라서 출력
```
* 문제접근
```
너무 부끄러운 풀이
반성해야한다
```
* 코드구현
```.c
#include <stdio.h>
int main(){
    int try = 6, arr[6] = {0};
    scanf("%d %d", &arr[0], &arr[3]);
    scanf("%d %d", &arr[1], &arr[4]);
    scanf("%d %d", &arr[2], &arr[5]);
    for(int idx = 0; idx < 2; idx++){
        for(int idx2 = idx+1; idx2 <= 2; idx2++)
            if(arr[idx] == arr[idx2]){
                arr[idx] = 0;
                arr[idx2] = 0;
            }
    }
    for(int idx = 3; idx < 5; idx++){
        for(int idx2 = idx+1; idx2 <= 5; idx2++)
            if(arr[idx] == arr[idx2]){
                arr[idx] = 0;
                arr[idx2] = 0;
            }
    }

    int idx = 0;
    while(try--){
        if(arr[idx] != 0){
            printf("%d", arr[idx]);
            printf(" ");
        }
        idx++;
    }
}
```
* 아이디어
```
발전을 위해 좋은 아이디어를 가져왔다
비트단위 연산자를 활용한 코드
```
> 비트단위 연산자 ^(XOR)
* 발전방향
```.c
#include <stdio.h>

int        main(void)
{
    int        x1, y1;
    int        x2, y2;
    int        x3, y3;

    scanf("%d %d", &x1, &y1);
    scanf("%d %d", &x2, &y2);
    scanf("%d %d", &x3, &y3);
    printf("%d %d", x1 ^ x2 ^ x3, y1 ^ y2 ^ y3);
    return (0);
}
```
* 코드분석
```.c
printf("%d %d", x1 ^ x2 ^ x3, y1 ^ y2 ^ y3);
```
<img width="450" alt="스크린샷 2021-11-22 오전 2 13 23" src="https://user-images.githubusercontent.com/87407504/142772074-1f0c0f64-99a6-433c-baec-f43578d80764.png"><br>

[비트연산자 공부하기](https://dojang.io/mod/page/view.php?id=173)

## :pencil: [9.4153.c]()
### [직각삼각형](https://www.acmicpc.net/problem/4153)
<img width="637" alt="스크린샷 2021-11-22 오전 11 18 22" src="https://user-images.githubusercontent.com/87407504/142791412-b0510bf4-b55d-4b17-9915-9a165af894a4.png"><br>
* 핵심
```
직각삼각형의 유무 출력 right : wrong
```
* 문제접근
```.c
1. 직각삼각형의 특성 이용
A^2 = B^2 + C^2
```
* 코드구현
```.c
include <stdio.h>
int main(){
    int A, B, C, max;
    while(1){
    scanf("%d %d %d", &A, &B, &C);
    if(A == 0 && B == 0 && C == 0) return 0;
    if(A > B && A > C){
        if(A*A == B*B + C*C)    printf("right\n");
        else                    printf("wrong\n");
    }
    else if(B > A && B > C){
        if(B*B == A*A + C*C)    printf("right\n");
        else                    printf("wrong\n");
    }
    else{
        if(C*C == B*B + A*A)    printf("right\n");
        else                    printf("wrong\n");
    }
    }
    return 0;
}
```
## 📝 [10_3053]()
### [택시 기하학](https://www.acmicpc.net/problem/3053)<br>
<img width="682" alt="스크린샷 2021-11-22 오전 11 17 30" src="https://user-images.githubusercontent.com/87407504/142791356-96228140-5c08-4139-b6fd-f56105322b08.png"><br>
* 핵심
```
유클리드 기하학과 택시기하학이 무엇인가
```
* 유클리드 기하학<br>
<img width="194" alt="스크린샷 2021-11-22 오전 10 56 16" src="https://user-images.githubusercontent.com/87407504/142789872-159f97e6-c323-488b-8bdb-e983de7554e7.png"><br>
`원 넓이 = pow(R,2) * PI`
* 택시 기하학<br>
<img width="194" alt="스크린샷 2021-11-22 오전 10 56 33" src="https://user-images.githubusercontent.com/87407504/142789847-78f8ed14-6408-45ed-8f68-1b45847e157f.png"><br>
`원 넓이 = pow(R,2) * 2`
* 특이사항
```
PI를 6자리만 주면 틀린다
MAX(R)의 값은 10000이므로 10000*10000*R를 했을 때 
소수점 6자리까지 나오게 하려면 최소 소수점 14자리수까지 보여야 한다

다른방법 -> M_PI 사용하기
#include <math.h> 안의 PI값 사용하기
방법
: M_PI는 C표준이 아니므로 특정 메크로를 정의해주어야한다
#define _USE_MATH_DEFINES

그렇지만 C표준이 아니므로 컴파일러에 따라 값이 상이하므로 지양하자
```
* 코드구현
```.c
#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979

int main(){
    int R;
    scanf("%d", &R);
    printf("%.6f\n", pow(R,2) * PI);
    printf("%.6f\n", pow(R,2) * 2);
    return 0;
}
```
* 정리
```.c
중요하지는 않지만 알아둬서 나쁠건 없지 않을까
#define 매크로
1. 가독성이 매우 높아짐
2. 상수 변경이 용이, 변경시 define의 값만 바꿔주면 해결
3. 문자상수 정의가 가능
    ex) #define DIGITS "0123456789"
    ex) #define BRACKET "(){}[]"
4. 함수매크로
마치 함수인것처럼 흉내낼 수 있는 기능
#define 매크로(매개변수, 매개변수 ...) 치환텍스트
```
<img width="389" alt="스크린샷 2021-11-22 오전 11 03 52" src="https://user-images.githubusercontent.com/87407504/142790304-b5f538b0-1f8e-4c9e-8fec-98e4362a65e5.png"><br>
<img width="312" alt="스크린샷 2021-11-22 오전 11 04 32" src="https://user-images.githubusercontent.com/87407504/142790361-d8efc992-f9ff-4ce9-ad88-f849b6b4cf90.png"><br>

## 📝 [11_1002.c]()
### [터렛](https://www.acmicpc.net/problem/1002)
<img width="671" alt="스크린샷 2021-11-22 오후 12 23 25" src="https://user-images.githubusercontent.com/87407504/142796361-52745f47-e3f4-495a-8e94-095597c130b8.png"><br>
* 핵심
```
두 고정점에서 각각의 사거리를 만족하는 한 점의 위치 갯수는 두 원의 점점의 갯수와 동일하다
```
* 문제접근
```
두 원의 접점이 발생할 수 있는 모든 경우의 수를 모두 고려 해야한다
1.
두 원의 반지름 길이 합이 두 고정점의 거리(d)보다 크고 d가 0이 아닌 경우
1-1) && 두 반지름의 차가 d보다 작을 경우 2
1-2) && 두 바지름의 차가 d와 같을 경우 1
1_3) 이외 0
2.
두 원의 반지름 길이 합이 두 고정점의 거리(d)가 같고 d가 0이 아닌 경우 1
3.
두 원의 반지름 길이 합이 두 고정점의 거리(d)보다 작고 d가 0이 아닌 경우 0
4.
d = 0 이면서 두 원의 반지름이 서로 다를때 0
5.
d = 0 이면서 두 원의 반지름이 서로 같을때 -1
```
* 함수구현
```.c
#include <stdio.h>
#include <math.h>

int main(){
    int x1, y1, r1, x2, y2, r2, d;
    int test;
    scanf("%d\n", &test);
    while(test--){
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        d = pow(x1 - x2, 2) + pow(y1 - y2, 2);
1.
        if(pow(r1 + r2, 2) > d && d !=0){
1-1)
            if(pow(r1 - r2, 2) < d) printf("2\n");
1-2)
            else if(pow(r1 -r2, 2) == d) printf("1\n");
1-3)
            else printf("0\n");
        }
2.
        else if(pow(r1 + r2, 2) == d && d != 0) printf("1\n");
3.
        else if(pow(r1 + r2, 2) < d && d!= 0) printf("0\n");
4.
        else if(d == 0 && r1 != r2) printf("0\n");
5.
        else if(d == 0 && r1 == r2) printf("-1\n");
    }
    return 0;
}
```
* 정리
```.c
길이를 구하기 위해 pow(x1-x2, 2) + pow(y1-y2,2)를 하고 sqrt를 해주면 문제발생
왜?
```
