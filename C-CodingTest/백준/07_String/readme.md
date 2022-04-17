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
```.c
void    bubble() 
{
	for (int i = 0; arr[i] != '\0'; i++) 
    {                                       
		for (int j = 0;j < i;j++) 
        {
			if (arr[j] > arr[i]) 
            {
				int tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
			}
		}
	}
}
```
-----

# 📌 [하얀 칸](https://www.acmicpc.net/problem/1100) 

### [1100]()

- 핵심
```.c
1. 문자열 제대로 저장하기
2. 체스 칸 흰색만 방문체크하기
```

- 문제접근
```.c
2. col은 홀수 row의 경우 1부터 짝수 row의 경우 0부터 시작
>   col = row % 2;
```

- 코드 구현
```.c
    
    row = 0;
    while (row < 8)
    {
        col = row % 2;
        while (col < 8)
        {
            if (chess[row][col] == 'F')
                cnt++;
            col += 2;
        }
        row++;
    }

```

- 📌 새로 안 사실

1.  문자열 입력 시 scanf의 취약점을 고려해야한다

빈칸은 white space를 구분자로 인식한다
```.c
    scanf(" %c", &a );

    처음에 띄우지 않아도 가능하다
    예를들어 입력이

    .F.F...F
    F...F.F.
    ...F.F.F
    F.F...F.
    .F...F..
    F...F.F.
    .F.F.F.F
    ..FF..F.

    와 같아도 처음에 띄워질 것을 염려할 필요 없다
```

-----

# 📌 [8진수 2진수](hhttps://www.acmicpc.net/problem/1212)

### [1212]()

- 문제 설명

    8진수를 2진수로 변환

- 특징

    8진수 각 하나의 숫자를 2진수 3개로 나타낼 수 있다

- logic

    2진수로 8진법의 각 자리 숫자가 나타낼 수 있는 경우의 수를 2차원 배열에 저장
    ```.c
    char    first[9][4] = {"", "1", "10", "11", "100", "101", "110", "111"};
    char    two[9][4] = {"000", "001", "010", "011", "100", "101", "110", "111"};
    ```
    > 처음 출력되는 숫자는 0부터 출력이 되면 안되니까 이원화

    해당 숫자의 인덱스에 위치하는 값을 출력
    ```.c
    printf("%s", first[str[0] - '0']);
    printf("%s", two[str[idx] - '0']);
    ```

-   새로 안 사실

    1. 8진법의 각자리 숫자는 2진법 3개로 나타낼 수 있다

    2. from진법에서 to진법으로 변경 시 표준화
        -   to 진법의 base를 만든다
        -   from 진법 수의 각 자리에 해당되는 base와 매칭하여 출력

    - 참고로 일반적인 int 형 숫자는 `10진수`

[진법 관련 참고 블로그](https://www.crocus.co.kr/468)
-----