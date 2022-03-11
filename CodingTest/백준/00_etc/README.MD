## 목차<br>
### [01. 2609](#2609)
### [02. 1920](#1920) 
### [03. 1974](#1874)

# [최대공약수 최소공배수 구하기](https://www.acmicpc.net/problem/2609)
### 2609
-  핵심
```.c
최대공약수는 나누었을때 나머지가 둘다 0이되는 가장 큰 수
최소공배수는 두 자연수 곱에 최대 공약수를 나눈 것
```

-  문제접근
```.c
1.
외우자
2.
최대공약수 gcd(a,b)
3.
최소공배수 (a*b) / gcd(a,b)
```
-  아이디어
```.c
최대공약수를 구할때 두 수중 작은 값(min)을 구하고
1부터 min까지 순차적으로 커지는 num을 나누는 수로하여 둘다 나머지가 0일때
이를 최대공약수의 값으로 부여하는 반복문을 돌리면 최대공약수가 나온다

이때 min값을 줄 때 삼항연산자를 사용하자
```

-  코드구현
```.c
1.
#include <stdio.h>
int gcd(int a, int b){
    int min, gcd, num = 1;
    min = a < b ? a: b;

    while(num <= min){
        if(a % num == 0 && b % num ==0)
            gcd = num;
        num++;
    }
    return gcd;
}
2.

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n%d\n", gcd(a, b), (a*b) / gcd(a, b));

    return 0;
```

-  정리
```
알면 바로푸는 문제다 데이터를 쌓아가자
```
-  심화학습 <유클리드 호제법>

2개의 자연수의 최대 공약수를 구하는 알고리즘

ex) 1071과 1029의 최대공약수

    -  1071은 1029로 나누어 떨어지지 않기 때문에 1071을 1029로 나눈 나머지를 구한다 >> 42
    -  1029는 42로 나누어 떨어지지 않기 때문에 1029를 42로 나눈 나머지를 구한다 >> 21
    -  42는 21로 나누어 떨어진다.
    -  따라서 최대공약수는 21

ex) 78696과 19332의 최대공약수
```.c
78696 = 19332*4 + 1368
19332 = 1368*14 + 180
 1368 = 180*7 + 108
  180 = 108*1 + 72
  108 = 2*1 + 36
   72 = 36*2 + '0'

최대공약수는 36
```

-  알고리즘을 활용한 코드구현
```.c
#include <stdio.h>
int gcd(int a, int b){
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main(){
    int a, b, tmp;

    scanf("%d %d", &a, &b);

    if(a < b){
        tmp = b;
        b = a;
        a = tmp;
    }

    printf("%d\n%d\n", gcd(a,b), (a*b) / gcd(a,b));

    return 0;
}
```
# [수 찾기](https://www.acmicpc.net/problem/1920)
### 1920
-  핵심
```.c
첫번째 배열에 데이터를 저장하고 두번째 배열에 데이터를 받아 첫번째에 해당 데이터가 있는지 확인하고 있으면 1을 출력
시간제한 1초이므로 이중 for문의 경우 O(n^2)발생
데이터의 수가 10^5이므로 엄청난 시간이 소요되므로 시간 절약해야할 필요가 있음
```

- 문제접근
```.c
1. 비교탐색에 시간을 줄이는 대표적인 예로 이진탐색이 있으며 해당 탐색의 시간 복잡도는 O(logn)
2.
이진탐색을 사용하기 위해서는 정렬되어야 한다
정렬을 위해 퀵소트 사용 #include <stdlib.h>의 qsort 사용
cf) 스트링이라면 <string.h>의 비교함수가 있다
qsort(정렬할 메모리주소, 정렬할 요소의 개수, 요소 크기, 비교함수)
3. 비교함수 구현
```
- 아이디어
```.c
비교함수를 구현할 때 삼항연산자를 사용하면 수월하게 만들 수 있다
int     compare(const void *a, const void *b)
{
        return *(int*)a > *(int*)b ? 1 : *(int*)a < *(int*)b ? -1 : 0;
}

삼항 연산자를 위와 같이도 사용할 수 있다
```

- 함수구현

```.c
1.
int binary_search(int arr[], int num, int size)
{
    int front, rear, pivot;
    front = 0;
    rear = size - 1;
    while (1) {
        pivot = (front + rear) / 2;
        if (arr[pivot] == num) return 1;
        if (arr[front] == num) return 1;
        if (arr[rear] == num) return 1;

        if (arr[pivot] < num)
            front = pivot + 1;
        else
            rear = pivot - 1;
        if (front >= rear)
            return 0;
    }
}

for(int j = 0; j < m; j++){
        printf("%d\n", binary_search(arr, arr2[j], n));
    }

2.
qsort(arr, n, sizeof(int), compare);

3.
#include <stdlib.h>
int compare(const void *a, const void *b){
    return *(int*)a > *(int*)b ? 1 : *(int*)a < *(int*)b ? -1 : 0;
}
```

- 정리
```.c
이진 탐색 시간 복잡도 : O(logn)
이진 탐색의 필수 조건은 정렬이다 

퀵 소트는 C에서 <stdlib.h> qsort()라는 함수로 구현되어있다
평균 시간 복잡도는 O(nlogn)이지만 최악은 O(n^2)이다

compare 함수에서 const void* 는 void형 상수를 가리키는 포인터이다 (해당 함수 내에서 포인터 값을 바꾸면 안됨)
```
