# 단순 정렬(Sorting)

## 버블정렬(bubble Sort)

### 이해

인접한 두 개의 데이터를 비교해가면서 오름차순으로 정렬
> 정렬의 우선순위가 가장 낮은, 제일 큰 값을 맨 뒤로 보내기
- 구현이 쉽다
- 성능이 아쉽다

### 구현

[BubbleSort.c]()<br>
```.c
void    BubbleSort(int arr[], int n)
{
    int idx;
    int jdx;
    int temp;

    for (idx = 0; idx < n - 1; idx++)
    {
        for (jdx = 0; jdx < (n - idx) - 1; jdx++)
        {
            if (arr[jdx] > arr[jdx + 1])
            {
                temp = arr[jdx];
                arr[jdx] = arr[jdx + 1];
                arr[jdx + 1] = temp;
            }
        }
    }
}
```

### 성능평가

by 비교 횟수

- 4개를 비교할 때 3 + 2 + 1
> n개를 비교할 때 (n-1) + (n-2) + ... + 2 + 1

- 등차수열에 따라 n(n-1)/2
> O(n^2)

by 이동 횟수
> temp이 for문 안에 있다

- 최선의 경우
> O(1)

- 최악의 경우
> O(n^2) 

## 선택 정렬(Selection Sort)

### 이해

가장 작은 값을 찾아 낮은 값부터 순차적으로 정렬
> 순서상 가장 앞서는 것을 선택해서 빈 그릇에 왼쪽부터 채운다고 생각
- 버블 정렬보다도 쉽고 간단

### 구현

[SelectionSort.c]()<br>
```.c
void    SelectionSort(int arr[], int n)
{
    int idx;
    int jdx;
    int min;
    int temp;

    for (idx = 0; idx < n; idx++)
    {
        min = idx;

        for (jdx = idx + 1; jdx < n; jdx++) // 최솟값 탐색
        {
            if (arr[jdx] < arr[min])
                min = jdx;
        }
            temp = arr[idx];
            arr[idx] = arr[min];
            arr[min] = temp;
    }
}
```

### 성능평가

by 비교 횟수

- 버블 정렬과 같다
> O(n^2)

by 이동 횟수
> temp이 for문 밖에 있다

- 최선의 경우
> O(n)

- 최악의 경우
> O(n) 

버블이나 선택이나 별차이 없음

## 삽입 정렬(InsertionSort)

### 이해

인접한 두 개의 데이터를 비교해가면서 오름차순으로 정렬
> 정렬의 우선순위가 가장 낮은, 제일 큰 값을 맨 뒤로 보내기
- 구현이 쉽다
- 성능이 아쉽다

### 구현

[InsertionSort.c]()<br>
```.c
void    InsertionSort(int arr[], int n)
{
    int idx;
    int jdx;
    int target;

    for (idx = 1; idx < n; idx++)
    {
        target = arr[idx];

        for (jdx = idx - 1; jdx >= 0; jdx--)
        {
            if (arr[jdx] > target)
                arr[jdx + 1] = arr[jdx];    // 비교대상 한 칸 뒤로 밀기
            else
                break;  // 삽입위치 찾았으니 종료
        }
            arr[jdx + 1] = target;
    }
}
```

### 성능평가

- 완전히 정렬된 상태라면 break문 실행으로 데이터 이동 x

- 최악의 경우
> O(n^2) 앞의 두 정렬과 같다

## 힙 정렬(Heap Sort)
## 병합 정렬(Merge Sort)
## 퀵 정렬(Quick Sort)
## 기수 정렬(Radix Sort)
