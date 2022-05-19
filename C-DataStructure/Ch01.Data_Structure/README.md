# :grey_exclamation: 자료구조와 알고리즘의 이해
### 자료구조
```
프로그램 
1. 데이터를 저장하고(자료구조) 2. 저장된 데이터를 처리하는 것(알고리즘)

데이터에 편리하게 접근하고, 변경하기 위해서 데이터를 저장하는 방법
ex) int형 변수를 선언, 개인정보 저장을 위한 구조체 정의
```

### 자료구조의 분류
<img width="710" alt="스크린샷 2021-11-17 오후 3 14 18" src="https://user-images.githubusercontent.com/87407504/142144988-b5c163a3-acef-400b-8b76-12ac66717fdc.png"><br>
* 선형 자료구조<br>
 <img width="250" alt="스크린샷 2021-11-17 오전 11 35 32" src="https://user-images.githubusercontent.com/87407504/142110369-a4da5550-2805-4ff4-a18d-77bf8498b06d.png"><br>
```
자료를 선형(linear)으로 저장하는 방식
하나의 자료 뒤에 하나의 자료가 존재하는 것
ex) 배열, 리스트, 스택, 큐
```
* 비선형 자료구조<br>
 <img width="150" alt="스크린샷 2021-11-17 오전 11 35 48" src="https://user-images.githubusercontent.com/87407504/142110576-fda69293-ebb5-49ed-b025-387d9deb74c2.png"><br>
```
하나의 자료뒤에 여러개의 자료가 존재할 수 있는 것
ex) 트리, 그래프
```
### 자료구조와 알고리즘
* 자료구조
```c
int idx, sum;
int arr[10] = {1, 2, ,3, 4, 5, 6, 7, 8, 9, 10}

데이터의 표현 및 저장방법
```
* 알고리즘
```c
for(idx = 0; idx < 10; idx++)
    sum += arr[idx];
    
문제의 해결 방법
```
:heavy_check_mark: 자료구조에 따라 알고리즘이 달라진다

# :grey_exclamation:알고리즘의 성능분석 방법
### 알고리즘을 평가하는 요소
* 시간 복잡도 : 입력의 크기와 문제 해결 시간의 상관관계
* 공간 복잡도 : 입력의 크기와 메모리 사용량과의 상관관계
> 일반적으로 알고리즘을 평가할 때 메모리의 사용량보다 실행 속도에 초점을 둔다
* 시간 복잡도<br>
```
수행 속도를 평가하는 방법
1. 연산의 횟수를 센다
2. 처리해야할 데이터의 수 n에 대한 연산횟수의 함수 T(n)을 구성한다
```
* 시간 복잡도 성능 분석<br>
<img width="304" alt="스크린샷 2021-11-17 오후 1 46 35" src="https://user-images.githubusercontent.com/87407504/142136486-0baaeec7-0b6f-4e33-8cea-e9e91a391b5f.png"><br>
```
데이터의 수가 적으면 알고리즘 B가 빠르다
데이터의 수가 보다 많으면 알고리즘 A가 더 빠르다

<결론>
데이터가 충분히 많은 것을 고려했을 때 알고리즘 A가 더 좋은 알고리즘이다
그러나, 데이터의 수가 많지 않고 성능에 덜 민감한 경우 구현의 편의를 위해 B를 선택하기도 한다
```
> 상황에 맞게 판단해야한다


###  순차 탐색(Linear Search) 알고리즘
> 순차 탐색을 예로 시간 복잡도 계산 해보기
* 코드
```c
#include <stdio.h>

// 배열의 내용을 왼쪽에서 오른쪽으로 이동시키며 순차적으로 target을 탐색
int    LS(int ar[], int len, int target)
{
    for(int idx = 0; idx < len, idx++)
    {
        if(ar[idx] == target)
            return idx;    // 찾은 대상의 인덱스를 반환
    }
    return -1;             // 찾지 못했다면 -1을 반환
}

int    main()
{
    int    arr[] = {3, 5, 7, 9};
    int    idx;

    // int형 배열이므로 배열의 크기를 string으로 구할 수 없다
    // sizeof를 이용하여 int형 배열의 크기를 구한다
    idx = LS(arr, sizeof(arr)/sizeof(int), 7);
    if (idx == -1)
        printf("탐색 실패\n");
    else
        printf("타겟 저장 인덱스: %d\n", idx);

    return 0;
}
```
1. 연산 횟수를 센다
```.c
사용 연산자 : '<', '++', '=='
핵심 연산자 : 동등 비교 연산자 '==' //'<', '++'는 '=='에 의존
핵심이 되는 연산자를 판단했다면 이를 중심으로 시간 복잡도를 계산
```

2. 핵심 연산자를 중심으로 데이터 수 n에 대한 연산횟수 함수 T(n)을 구성한다
```.c
시간 복잡도의 계산은 최악의 경우를 기준으로 계산
결론 -> T(n) = n
```

### 이진 탐색(Binary Search) 알고리즘
> 이진 탐색을 예로 시간 복잡도 계산 해보기
> 조건 : 배열에 저장된 데이터는 정렬되어 있어야 한다.

* 방식
```.vim
배열의 시작(first)과 끝(last)을 기준으로 mid를 비교대상(target)으로 선택한다

case1 : arr[mid idx] > target 경우 last = mid - 1
case2 : arr[mid idx] < target 경우 first = mid + 1
같을 때 까지 반복한다

first > end가 되면 탐색을 실패하고 종료한다
```
> 모든 값이 정렬되었다는 조건 필요
* 코드
```c
#include <stdio.h>
int     BS(int ar[], int len, int target)
{
    int     first = 0;
    int     last = len - 1;
    int     mid;

    while(first <= last)
    {
        mid = (first + last) / 2;

        if(target == ar[mid])
            return(mid);
        else
        {
            if(target > ar[mid])
                first = mid + 1;
            else
                last = mid - 1;
        }
    }
    return -1;
}

int     main()
{
    int     arr[] = {1, 3, 5, 7, 9};
    int     idx;

    // int형 배열이므로 배열의 크기를 string으로 구할 수 없다
    // sizeof를 이용하여 int형 배열의 크기를 구한다
    idx = BS(arr, sizeof(arr)/sizeof(int), 7);
    if(idx == -1)
        printf("탐색 실패\n");
    else
        printf("타겟 저장 인덱스: %d\n", idx);

    return 0;
}

```

1. 연산 횟수를 센다
```.c
핵심 연산자 : 동등 비교 연산자'=='
```
2. 처리해야할 데이터의 수 n에 대한 연산횟수의 함수 T(n)을 구성한다
```.vim
최악의 경우: n이 1이 될 때까지 2로 나누고 남은 1을 비교하기 위해 추가 1회 연산이 필요
```
* n을 1이될때 까지 나누고 추가로 1회 연산
  <br><img width="100" alt="스크린샷 2021-11-17 오후 2 29 47" src="https://user-images.githubusercontent.com/87407504/142140586-64ec34b4-031a-4b7b-b8cd-e7c8739c8d23.png"><br>
* 횟수 k를 기준 
  <br><img width="400" alt="스크린샷 2021-11-17 오후 2 29 53" src="https://user-images.githubusercontent.com/87407504/142140698-0ecb5197-d95f-4aba-a817-64cac012874e.png">
* 시간복잡도 T(n) 
  <br><img width="178" alt="스크린샷 2021-11-17 오후 4 38 23" src="https://user-images.githubusercontent.com/87407504/142156558-016dc91e-b217-41fa-a524-ae2f887085b8.png">
> T(n)는 수의 증가에 따른 연산횟수의 변화 정도에 주목하므로 추가 1회 연산 + 1은 의미가 없다
> 빅-오 표기법을 살펴보자
 
 ### 빅-오 표기법
 ```
 시간 복잡도 계산은 정확한 값이 아닌 연산횟수에 따른 변화 정도가 중요하다
 변화에 가장 큰 영향을 미치는 최고차항의 차수만 고려한다
 ```
 * 빅-오 그래프
 <br><img width="402" alt="스크린샷 2021-11-17 오후 2 40 56" src="https://user-images.githubusercontent.com/87407504/142141526-d59dc73e-463a-4bd3-93f0-9148a1281593.png">
 * 빅-오의 크기순서
 <br><img width="507" alt="스크린샷 2021-11-17 오후 2 44 06" src="https://user-images.githubusercontent.com/87407504/142141814-e94f1996-b7a8-49e1-9c32-adb38992fcf9.png">
 > n^n에 가까울수록(그래프가 위로 올라갈수록) 성능은 떨어진다<br>
 > 1에 가까울수록(그래프가 내려갈수록)성능은 올라간다
### :pencil2: 빅-오에 대한 수학적 접근<br>
![KakaoTalk_Photo_2021-11-17-17-57-26](https://user-images.githubusercontent.com/87407504/142169066-777572b1-160a-484a-87c3-95fcd27e2a32.jpeg)

# :grey_exclamation: 응용학습
* 코딩 테스트 시간제한 1초일 경우
```
컴퓨터는 1초에 대략 3~5억개 정도의 연산을 처리한다
대부분의 환경에서 1억번 연산이 1초정도 걸린다
```
> 연산자마다 차이는 발생할 수 있음
> 1억을 기준으로 연산시간을 고려해보자

|시간복잡도|데이터 수|
|:---:|:---:|
|n|10^8|
|logn|10^8|
|nlogn|10^6|
|n^2|10^4|
|n^3|500|
|n!|20|
|2^n|20|
* 메모리 제한이 512MB일 경우
```
512MB = 524,288KB = 536,870,912B
int 변수를 대략 1.2억개 선언할 수 있다
```
