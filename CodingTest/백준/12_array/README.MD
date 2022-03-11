## [1_2750.c]()
### [수 정렬하기](https://www.acmicpc.net/problem/2750)
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

## [2_2751.c]()
### [수 중럴하기2](https://www.acmicpc.net/problem/2751)
