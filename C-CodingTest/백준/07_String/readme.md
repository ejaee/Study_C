# 📌 String

## 유독 문자열이 약하다 
> 게속 복습하기

# 📌 [소트인사이드](https://www.acmicpc.net/problem/1427) 

### [15649]()

- 핵심
```.c
1. 10억 이하의 수 N을 입력받아 내림차순으로 정렬
2. 내림차순을 하기 위해서는 자릿수로 접근해야하고 이는 곧 문자열로 접근
```

- 문제접근
```.c
1. 숫자를 문자열에 저장하여 정렬하기
```

- 코드 구현
```.c
    //  정렬 헷갈리지 말자!!!

    idx = -1;
    while (++idx < strlen(arr)-1)
    {
        jdx = idx;
        while (++jdx < strlen(arr))
        {
            if (arr[idx] < arr[jdx]>)
            ...
        }
    }

```

- 📌 새로 안 사실

1.  strlen(char *str) `in #include <string.h>`

2.  정렬 확실하게 사용하기

-----


