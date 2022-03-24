# :grey_exclamation: 함수의 재귀적 호출의 이해
### 재귀
```
재귀함수를 연속적으로 호출하면 기존에 작동하던 재귀함수는 스택(stack)에 쌓이고 호출된 재귀함수가 먼저 작동
처음 불려진 함수에서(스택 맨 밑에있는 메소드) returm 되는 값이 최종 return 값
```

### Factorial 재귀함수
* 함수 구현
```
1. 정수 n 팩토리얼은 n * (n - 1)!
2. 0! = 1 (예외처리)
```
* 코드
```.c
#include <stdio.h>
int Factorial(int n)
{
  if(n == 0)
        return 1;
  else
        return n * factorial(n - 1);
}
```
* 동작 방식
```
fact(3)이 동작되는 방식

1. n !=0 이므로 fact(2)를 호출
fact(3)은 stack에 쌓인채로 fact(2)이 실행
```
|stack|
|:---:|
|fact(3)|

```
2. n !=0 이므로 fact(1)를 호출
fact(2)는 stack에 쌓인채로 fact(1)이 실행
```
|stack|
|:---:|
|fact(2)|
|fact(3)|
```
3. n !=0 이므로 fact(0)를 호출
fact(1)은 stack에 쌓인채로 fact(0)이 실행
```
|stack|
|:---:|
|fact(1)|
|fact(2)|
|fact(3)|
```
4. n == 0 이므로 return 0
끝가지 갔다면 역으로 올라오면서 return값 fact(1) 부터 차례로 받아오기
마지막 return은 첫 fact(3)에 해당되는 return
```
### Fibonacci 재귀함수
* 함수 구현
```
1. 정수 n 피보나치는 (n - 1) + (n - 2)
2. fibo(1) = 0 (예외처리)
3. fibo(2) = 1 (예외처리)
```
* 코드
```.c
#include <stdio.h>
int fibo(int n)
{
2.
    if(n <= 0)
        return 0;
3.
    else if(n == 1)
        return 1;
1.
    else
        return fibo(n-1) + fibo(n-2);
}
```
<img width="556" alt="스크린샷 2021-11-19 오후 8 58 30" src="https://user-images.githubusercontent.com/87407504/142619304-f1a69bf7-bad4-4943-afda-b064e1d1735f.png"><br>
> 매번 함수를 호출될 때마다 2개씩 호출이 증가<br>
> 트리의 높이만큼 반복<br>
> 트리의 높이 < n<br>
> 2개씩 n번 늘어나는 알고리즘 -> O(2^n)<br>
> 불필요한 작업이 발생<br>
> ![KakaoTalk_Photo_2021-11-20-12-26-49 002](https://user-images.githubusercontent.com/87407504/142712987-3267c716-26f5-4349-983e-cdb7d5ac31f8.jpeg)<br>
* 코드 최적화
```
#include <stdio.h>
int fibo(int n, int r[])
{
    if(n <= 0)
        return 0;
    else if(n == 1)
        return r[n] = 1;
```
```.c
    else if(r[n] > 0)
        return r[n];
```
```
    else
        return r[n] = fibo(n - 1, r) + fibo(n - 2, r);
}
```
> 결과로 반환하는 배열 방에 기존에 계산해온 결과가 있으면 그 값을 그냥 반환<br>
> 시간복잡도 = O(N)<br>
> ![KakaoTalk_Photo_2021-11-20-12-26-48 001](https://user-images.githubusercontent.com/87407504/142712993-e250ea22-1696-4646-91d6-cf926cc43abe.jpeg)<br>
### binary 재귀함수
* 함수 구현
```
1. 탐색 범위의 중앙에 목표값이 저장되었는지 확인
2. 저장되지 않았다면 탐색 범위를 반을 줄여서 다시 탐색시작(재귀)
```
* 코드
```.c
int Bsearch(int arr[], int first, int last, int target)
{
    int mid;
    if(first > last)              // 끝까지 못 찾았을 경우 종료조건, 탐색 실패 경우의 예외처리
        return -1;
        
    mid = (first + last) / 2;
    if(arr[mid] == target)        // 찾았을 경우
        return mid;
```
> 함수 구현에 기재된 재귀의 활용
```.c
    else if(target > arr[mid])
        Bsearch(arr, mid + 1, last, target);
         // 기존의 방식 first = mid + 1
    else
        Bsearch(arr, first, mid - 1, target);
        // 기존의 방식 last = mid - 1
}
```
### 하노이 타워
<img width="662" alt="스크린샷 2021-11-19 오후 9 14 57" src="https://user-images.githubusercontent.com/87407504/142621272-2a4414b6-6afa-4fab-90f2-09a0d7f34b25.png"><br>
* 함수구현
```
1단계. 작은 원반 n-1개(맨 아래를 제외한 원반)를 A에서 B로 이동
2단계. 큰 원반 1개(맨 아래의 원반)를 A에서 C로 이동
3단계. 작은 원반 n-1개(1에서 옮겨진 원반들)를 B에서 C로 이동
```
> 재귀함수의 연속
* 코드
```.c
// from에 있는 원반을 by를 거쳐 to로 이동
void Hanoi(int num, char from, char by, char to)
{
```
> 맨 마지막에 남는 원반은 그냥 이동하면 된다
```.c
    if(num == 1)                   // 이동할 원반의 수가 1개일 떼, 이는 탈출 조건이 된다
        printf("원반1을 %c에서 %c로 이동 \n", from ,to);
```
> 첫번째 이동하는 원반은 A에서 B로 이동한다
```.c
    else
        Hanoi(num - 1, from, to, by)
```
> 함수구현 1단계
```.c
        printf("원반 %d을 %c에서 %c로 이동 \n", num, from, to) 
```
> 함수구현 2단계
```.c
        Hanoi(num - 1, by, from, to)
```
> 함수구현 3단계
* 잘못 생각하고 있었던 점
```
위의 코드에서 세단계는 서로 영향을 미치지 않는다
1단계의 매개변수가 3단계의 매개변수에 영향을 미친다고 생각했다
재귀함수에서 흐름을 보고 싶다면 각 단계의 함수에는 전체 함수의 매개변수가 각각 영향을 미친다는 것을 꼭 인지하자
```
```
