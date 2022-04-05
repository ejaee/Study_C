# 📌 Sorting

## 📌 [수 정렬하기](https://www.acmicpc.net/problem/2750) 

### [2750]()

* 핵심
```
선택정렬을 이용한 입력받은 숫자 오름차순 정리 출력
```
> [선택정렬](https://github.com/Ejaeda/42_study/tree/master/C/%5BSorting_Algorithms_in_C%5D)

* 선택정렬코드
```.c
void    check(int arr[], int N){
    int min, temp;

    for(int idx = 0; idx < N-1; idx++){
        min = idx;
        for(int idx2 = idx + 1; idx2 < N; idx2++){
            if(arr[min] > arr[idx2])
                min = idx2;
        }
        temp = arr[idx];
        arr[idx] = arr[min];
        arr[min] = temp;
    }
    for(int idx = 0; idx < N; idx++){
        printf("%d\n", arr[idx]);
    }
}
```
-----

## 📌 [수 정렬하기3](https://www.acmicpc.net/problem/10989) 

### [10989]()

* 핵심
```
counting sort
```
> [counting sort](https://bowbowbow.tistory.com/8)

1. 위 페이지대로 하나씩 구현하니 메모리 초과 및 시간 초과 발생

    누적 카운팅에 따른 결과를 배열에 저장하고 출력하였음

2. 배열은 카운팅 count[]만 남기고 나머지는ㄴ 간단한 변수로 대체

    - 숫자를 변수로 입력받아 해당 인덱스를 찾아 count[입력 값]을 증가

    - cnt 값이 0이 아닐 때, cnt 값 만큼 출력

- 📌 새로 안 사실

1.  counting sort

    원래 일반적인 코드
    > [amination](https://www.cs.miami.edu/home/burt/learning/Csc517.091/workbook/countingsort.html)
```c
#include <stdio.h>

#define max 10001

int main()
{
    int N;
    int num[1000001] = {0};
    int visit[1000001] = {0};
    int count[max] = {0};
    int count_sum[max] = {0};

    scanf("%d", &N);

    int idx = 0;
    while (++idx <= N)
    {
        scanf("%d", &num[idx]);
        count[num[idx]]++;
    }
    count_sum[0] = count[0];
    idx = 0;
    while (++idx < max)
        count_sum[idx] = count_sum[idx - 1] + count[idx];

    idx = N+1;
    while (--idx >= 1)
    {
        visit[count_sum[num[idx]]] = num[idx];
        count_sum[num[idx]]--;
    }

    idx = 0;
    while (++idx <= N)
        printf("%d\n", visit[idx]);
}
```
- 카운팅 소트는 수가 얼만큼 나왔는지를 세고 그만큼 순서대로 출력

    단순 10000개의 숫자를 출력하므로 메모리 크기가 8MB 만으로도 가능!
    
-----

## 📌 [좌표 정렬하기](https://www.acmicpc.net/problem/11650) 

### [11650]()

* 핵심
```
시간제한 1초는 mergesort 라고 생각하자
```
> [병합정렬](https://github.com/Ejaeda/C_lang/blob/master/C-DataStructure/Ch10.Sorting/File/MergeSort.c)

* 병합정렬( + 구조체)코드
```.c
    while(fIdx<=mid && rIdx<=right)
    {
        if(p[fIdx].x < p[rIdx].x)
            sortArr[sIdx] = p[fIdx++];
        else if(p[fIdx].x > p[rIdx].x)
            sortArr[sIdx] = p[rIdx++];
        else
        {
            if(p[fIdx].y < p[rIdx].y)
                sortArr[sIdx] = p[fIdx++];
            else if(p[fIdx].y > p[rIdx].y)
                sortArr[sIdx] = p[rIdx++];
        }
        sIdx++;
    }
```
- 📌 새로 안 사실

1.  구조체 병합정렬

> 구조체의 멤버가 2개일때 이를 비교하는 코드

-----

## 📌 [나이순 정렬](https://www.acmicpc.net/problem/10814) 

### [10814]()

- 핵심
```.c
1. 나이와 이름을 입력받기
2. 나이순, 나이같다면 입력받은 순으로 출력하기
```

- 문제접근
```.c
1. 나이와 이름을 함께 입력받아야 하므로 구조체
2. 나이 정렬을 위해 quick sort
```

- 코드 구현

구조체 선언
```.c
    typedef struct _member
    {
        int age;
        char name[101];
    } member

    
            ...
```

```.c

int compare(const void* a, const void* b)
{
    return (a->age > b->age ? 1 : a->age < b->age ? -1 : 0);
}

int main()
{
    ...

qsort(list, N, sizeof(list[0]), compare);

    ...
}
```
        

- 📌 새로 안 사실

1.  구조체 접근

> list.a == (&list)->a

```.c
    member *list;

    list = malloc( ... );
    // 구조체 자료형 list를 2차원 배열처럼 많이 만들었다

    scanf(" %d %s", &list[idx].age, list[idx].name)
    // list 는 member * 형으로 주소지만, 개개인의 
    // list[idx]로 접근하고 있어 list[idx].name 로 접근해야함

    // &list[p]idx].age << & 붙이는 위치도 잘 보자
```

2. 퀵소트 내부 함수 쓰기

```.c
void qsort
(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*))
```
Parameters

1. base

    정렬할 배열의 첫 번째 요소에 대한 포인터

2. nitems

    베이스로 가리킨 배열의 요소 수

3. size

    배열에 포함된 각 요소의 크기(바이트)

4. compar

    두 요소를 비교하는 함수


-   compare 함수 구현할 때

    오름차순으로 구현하고 싶을 때 큰 수 부터 1, 0, -1 값을 반환
    
    내림차순으로 구현하고 싶을 때 큰 수 부터 -1, 0, 1 값을 반환

3. 삼항연산자 응용

```.c
return (a->age > b->age ? 1 : a->age < b->age ? -1 : 0);
```
-----


