# 단순 정렬(Sorting)

## 버블정렬(bubble Sort)

![bubble](https://user-images.githubusercontent.com/87407504/155281904-a3dc714f-0771-4002-a63e-bdfacdb2c92a.gif)<br>

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

-----

## 선택 정렬(Selection Sort)

![selection](https://user-images.githubusercontent.com/87407504/155281934-f7ad101c-b3cd-4000-a38d-247272a02ad9.gif)<br>

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

-----

## 삽입 정렬(InsertionSort)

![insertion](https://user-images.githubusercontent.com/87407504/155281959-4fec81fd-2278-469b-91c7-d752409bcc65.gif)<br>

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

-----

## 힙 정렬(Heap Sort)
![heap](https://user-images.githubusercontent.com/87407504/155310966-13104362-bcf9-4509-b10e-b0db6e927cab.gif)<br>

### 이해

루트 노드에 저장된 값이 가장 큰 max heap 특성을 활용
> 힙 그 자체
- heap 을 구현하면 된다
- 성능이 효율적이다

### 구현

[HeapSort.c]()<br>
```.c
#include <stdio.h>
#include "UsefulHeap.h"

int PriComp(int n1, int n2)
{
    return n2 - n1; // 오름차순일 때
//  return n1 - n2; // 내림차순일 때
}

void    HeapSort(int arr[], int n, PriorityComp pc)
{
    Heap heap;
    int i;

    HeapInit(&heap, pc);

    // 정렬대상을 가지고 힙을 구성
    for(i = 0; i < n; i++)
        HInsert(&heap, arr[i]);

    // 고대로 꺼내서 정렬 완성
    for(i = 0; i < n; i++)
        arr[i] = HDelete(&heap);
}

int main()
{

    ...

    HeapSort(arr, sizeof(arr)/sizeof(int), PriComp);

    ...

}

```

### 성능평가

- heap의 데이터 저장, 삭제 시간 복잡도와 동일
> O(logn)

- n개 정렬과정에 대한 시간 복잡도
> O(n*logn)

-----

## 병합 정렬(Merge Sort)
![merge](https://user-images.githubusercontent.com/87407504/155310957-eb3243ba-4e84-41bd-be5f-e405e13e4e5b.gif)<br>

### 이해

분할 정복 이라는 알고리즘 디자인 기법에 근거
> 복잡한 문제를 복잡하지 않은 문제로 분할(divide)하여 정복(conquer)하는 방법
- 분할 (해결이 용이한 단계까지 문제를 분할)
- 정복 (해결이 용이한 수준까지 분할된 문제를 해결)
- 결합 (분할해서 해결한 결과를 결합하여 마무리)

데이터가 1개가 남을때까지 분할한다
### 구현

[MergeSort.c]()<br>
```.c
#include <stdio.h>
#include <stdlib.h>

void    MergeTwoArea(int arr[], int left, int mid, int right)
{
    int fIdx = left;
    int rIdx = mid + 1;
    int i;

    // 병합한 결과를 담을 수  있게 사이즈에 맞는 arr 할당
    int * sortArr = (int *)malloc(sizeof(int)*(right+1));
    int sIdx = left;

    // 배열의 앞 뒤 영역이 비교대상이 남아 있을 때
    while (fIdx <= mid && rIdx <= right) // 병합할 두 영역 데이터 비교하고 하나씩 옮기기
    {
        if (arr[fIdx] <= arr[rIdx])
            sortArr[sIdx] = arr[fIdx++];
        else
            sortArr[sIdx] = arr[rIdx++];

        sIdx++;
    }

    if (fIdx > mid) // 배열의 앞부분이 모두 sortArr에 옮겨 졌다면
    {
        for (i = rIdx; i <= right; i++, sIdx++) // 뒷부분 남은 데이터 그대로 옮긴다
            sortArr[sIdx] = arr[i];
    }
    else            // 뒷부분이 모두 옮겨 졌다면 동일하게
    {
        for (i = fIdx; i <= mid; i++, sIdx++)
            sortArr[sIdx] = arr[i];
    }

    for (i = fIdx; i <= right; i++)
            arr[i] = sortArr[i];
    }

    free(sortArr);
}

void    MergeSort(int arr[], int left, int right)
{
    int mid;

    if (left < right) // left가 작다는 것은 더 나눌 수 있다는 것
    {
        // 중간지점 계산
        mid = (left+right) / 2;

        // 둘로 나눠서 각각을 정렬
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);

        // 정렬된 두 배열을 병함
        MergeTwoArea(arr, left, mid, right);
    }
}

mergeSort(arr, 0, sizeof(arr)/sizeof(int)-1);
```
정리하자면
1.  베열을 size 1이 될 때까지 분할(reculsive)
2.  size 1이 되었다면 merge to area 함수로 이동
3.  merge의 결과를 넣을 배열 arr을 동적 할당
>   배열의 크기는 right+1

4.  `left ~ mid` 와 `mid + 1 ~ right` 를 arr에 담을 것임
5.  fIdx <= mid && rIdx <= right 가 지켜진가운데 정렬 순서대로 input arr
6.  둘 중 하나라도 조건의 끝났다는 것은 해당 배열이 모두 arr에 들어갔다는 뜻이므로
7.  남은 배열 순차적으로 arr에 넣기

### 성능평가

- 비교 연산은 MergetoArea 에서 진행되므로 해당 함수를 기준으로 계산
> 하나(2) 하나(8)가 모여 둘(2 8))이 될 때 비교 연산은 while에서 1회, if/ else에서 1회 총 2회
> 둘(1 5) 둘(4 6)이 모여 넷이 될 떄 8회

> 정렬의 대상인 데이터의 수가 `n개`일 때 각 병합의 단계마다 `최대 n`번 비교연산 (이해 안되면 p399)

- 비교 연산
> O(n*logn)

- 이동 연산
> O(n*logn) (이해 안되면 p400)

-----

## 퀵 정렬(Quick Sort)
![quick](https://user-images.githubusercontent.com/87407504/155310936-5e043330-87e9-4886-9cbf-06cabcdb12c2.gif)<br>


### 이해

분할 정복 이라는 알고리즘 디자인 기법에 근거<br>

중심점, `pivot` 을 활용한다
> 가운데 값이 될 수도, 양 끝 값이 될 수도 본인 마음대로 (여기선 왼쪽 값)
- `left` 배열의 맨 왼쪽 값
- `right` 배열의 맨 오른쪽 값
- `low` pivot을 제외한 맨 왼쪽 값
- `high` pivot을 제외한 맨 오른쪽 값

간단한 원리
1.  pivot값 보다 높은 값을 만날 때까지 low >>
2.  pivot값 보다 낮은 값을 만날 때까지 high <<
> 둘다 일정하게 움질일 필요 없음. 개별적 이동 상관 무
3.  멈췄다면 서로 값 `swap`
4.  `high`의 값과 `pivot` 값 `swap`
> pivot 값은 제 자리에 위치한 것
5. 제자리를 찾은 값 기준으로 `왼쪽 영역`과 `오른쪽 영역`으로 나누어 반복

### 구현

[QuickSort.c]()<br>
```.c
#include <stdio.h>

void    swap(int arr[], int idx1, int idx2)
{
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

int Partition(int arr[], int left, int right)
{
	int pivot = arr[left];    // 피벗의 위치는 내가 정한다 왼 가운데 오
	int low = left+1;
	int high = right;

	while(low <= high)    // 교차되지 않을 때까지 반복
	{	

        // 해당 코드는 같은 값들이 구성된 배열에서 문제가 발생한다
		/*
        while(pivot > arr[low])
			low++;

		while(pivot < arr[high])    
			high--;
		*/
		
        // 피벗보다 큰 값을 찾는 과정
		while(pivot >= arr[low] && low <= right) // 우측의 조건은 경계검사를 위한 연산
			low++;

        // 피벗보다 작은 값을 찾는 과정
		while(pivot <= arr[high] && high >= (left+1))   // 가장 왼쪽의 피벗을 제외시키기 위해 + 1
			high--;
		

        // 교차되지 않은 상태라면 Swap 실행
		if(low <= high)    
			Swap(arr, low, high);    // low와 high가 가리키는 대상 교환
	}

	Swap(arr, left, high);    // 피벗과 high가 가리키는 대상 교환
	return high;    // 옮겨진 피벗의 위치 정보 반환
}
    
void QuickSort(int arr[], int left, int right)
{
	if(left <= right)
	{
		int pivot = Partition(arr, left, right);    // 둘로 나눠서 
		QuickSort(arr, left, pivot-1);    // 왼쪽 영역을 정렬
		QuickSort(arr, pivot+1, right);    // 오른쪽 영역을 정렬
	}
}
    
```

사실, 피벗이 중간에 해당하는 값일 경우 정렬대상이 균등하게 나뉜다
1.  `피벗`의 수는 partition 함수의 `호출 횟수`를 의미
2.  좋은 성능을 보이려면 최대한 중간 값에 가까운 피벗이 지속적으로 선택되어야 한다
3.  일반적으로 정렬 댓상에서 세 개의 데이터를 추출하고 그 중에 중간 값에 해당하는 것으로 피벗을 둔다

### 성능평가

- 피벗이 결정되면 low는 >> high는 << 이동. 서로 역전될때 까지
> 움직일 때마다 피벗과의 비교가 있으므로 비교연산의 횟수는 데이터 수 n

> ex) 31의 데이터 대상으로 항상 피벗이 중간 값으로 결정된다고 설정 해보자
>   31개 데이터는 15개씩 총 2조각 (1차 나뉨)
>   이어서 각 7개씩 총 4조각 (2차 나뉨)
>   이어서 각 3개씩 총 8조각 (3차 나뉨)
>   이어서 각 1개씩 총 16조각 (4차 나뉨)

>둘로 나뉘는 횟수를 k라 할 때 k = logN

- 비교 연산
> 최선의 경우 : O(n*logN)
> 최악의 경우 : O(n^2)

QuickSort는 최선의 경우에 가까운 성능을 평균적으로 보이므로 예외적으로 최악의 경우보다 최선의 경우가 우선된다
> 이동 횟수가 상대적으로 적고, 병합 정렬과 같이 별도의 메모리 공간을 요구하지 않아 동일한 시간 복잡도 알고리즘 대비 가장 빠른 정렬 속도 알고리즘

-----

## 기수 정렬(Radix Sort)

<img width="600" alt="스크린샷 2022-03-24 오후 10 26 54" src="https://user-images.githubusercontent.com/87407504/159930421-51007ad0-73ed-432e-b58f-02b4c8318058.png"><br>

<img width="459" alt="스크린샷 2022-03-24 오후 10 26 54" src="https://user-images.githubusercontent.com/87407504/159930772-9d10b958-7727-4c79-a74b-d41823e050e7.png">

### 이해

비교연산을 하지 않는다<br>

가장 빠른 정렬 알고리즘
> 그러나 적용할 수 있는 범위가 제한적
- 문장에서, `길이가 같은 데이터`들 대상으로만 정렬이 가능하다
- 정렬이 불가능하다 == 추가적인 별도의 알고리즘이 필요하다
- 10진수 정수의 정렬을 위해서는 총 열 개의 버킷이 필요하다
- 버킷은 0부터 9까지 순서대로 이름이 매겨져 있다
- 정렬 대상은 값에 해당하는 버킷으로 이동한다
- 버킷으로 이동이 끝났다면 버킷 0부터 9까지 차례대로 꺼낸다
> 10진수 정수의 정렬을 위해서는 총 열 개의 버킷이 필요하다
> 2진수 정수의 정렬을 위해서는 총 두 개의 버킷이 필요하다

간단한 원리

1. 10진수 정수의 정렬을 위해서는 총 열 개의 버킷이 필요하다
2. 버킷은 0부터 9까지 순서대로 이름이 매겨져 있다
3. 정렬 대상은 값에 해당하는 버킷으로 이동한다
4. 버킷으로 이동이 끝났다면 버킷 0부터 9까지 차례대로 꺼낸다

### `LSD` vs `MSD`

LSD(Least Significant Digit)
> 일의 자리 숫자부터 시작해서 정렬을 진행

- 작은 자릿수에서 가장 큰 자릿수까지 모두 비교해야 대소 판단이 가능하다
- 가장 큰 숫자의 길이만큼 모두 비교해야한다는 일관성이 있다

MSD(Most Significant Digit)
> 가장 큰 자릿수에서부터 정렬이 진행된다

- 반드시 끝까지 가지 않아도 된다
- 비일괄적인 과정이 되려 추가적인 알고리즘을 요구한다

결론 : LSD 방식을 통해 기수 정렬을 구현
> MSD가 중간에 먼저 대소 판단이 끝나지만, 추가적인 연산과 별도 메모리가 요구된다
> MSD라고 해서 더 성능이 뛰어난 것이 아니다

### 구현
[ListBaseQueue.c]()<br>
[ListBaseQueue.h]()<br>
[RadixSort.c]()<br>
```.c
#include <stdio.h>
#include "ListBaseQueue.h"

#define BUCKET_NUM		10

void RadixSort(int arr[], int num, int maxLen)   // maxLen은 가장 긴 데이터의 길이
{
	Queue buckets[BUCKET_NUM];
	int bi;
	int pos;
	int di;
	int divfac = 1;
	int radix;

	// 총 10개의 버킷 초기화
	for(bi=0; bi<BUCKET_NUM; bi++)
		QueueInit(&buckets[bi]);

	// 가장 긴 데이터의 길이만큼 반복
	for(pos=0; pos<maxLen; pos++)
	{ 
		// 정렬 대상의 수만큼 반복
		for(di=0; di<num; di++)
		{
			// N번째 자리의 숫자 추출
			radix = (arr[di] / divfac) % 10;

			// 추출한 숫자를 근거로 데이터 버킷에 저장
			Enqueue(&buckets[radix], arr[di]);
		}

		// 버킷 수만큼 반복
		for(bi=0, di=0; bi<BUCKET_NUM; bi++)
		{
			// 버킷에 저장된 것 순서대로 다 꺼내서 다시 arr에 저장
			while(!QIsEmpty(&buckets[bi]))
				arr[di++] = Dequeue(&buckets[bi]);
		}

		// N번째 자리의 숫자 추출을 위한 피제수의 증가
		divfac *= 10;
	}	
}

int main(void)
{
	int arr[7] = {13, 212, 14, 7141, 10987, 6, 15};

	int len = sizeof(arr) / sizeof(int);
	int i;

	RadixSort(arr, len, 5);

	for(i=0; i<len; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}    
```

### 성능평가

- 비교 연산이 아닌 버킷으로의 데이터 삽입, 추출이 핵심
```.c
    maxLen x num
```

- 비교 연산
> O(n)

O(n*logn) QuickSort 보다 뛰어난 기수 정렬이지만 적용 가능 대상이 제한적

-----
