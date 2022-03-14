# [N과M 1](https://www.acmicpc.net/problem/15649) 

### :point_right: [15649](https://github.com/Ejaeda/Data_Structure/blob/master/CodingTest/%EB%B0%B1%EC%A4%80/14_Backtracking/01_15649.c)

- 핵심
```.c
1. 백트래킹 기본문제
2. DFS 파라미터로 변수 선언하여 재귀 돌리기
3. 그 속에서 입력 숫자를 나타내는 변수 돌리기
```

- 문제접근
```.c
백트래킹 연습
```

- 코드 구현
```.c
#include <stdio.h>

int N, M;                   // 입력받을 두 변수
int rst[1000] = {0, };      // 출력할 내용들을 담을 배열
int check[1000] = {0, };    // 사용한 숫자인지 내용 0과 1로 판단하는 배열

void    DFS(int count)      // 파라미터에 변수를 선언하고 main에서 값을 부여
{                           // 얼마나 뿌리를 내릴건지 depth를 의미
    int input;
    int idx;
    
    if (count == M)         // depth 도달
    {
        idx = -1;
        while (++idx < M)
            printf("%d ", rst[idx]);
        printf("\n");
    }
    else
    {
        input = 0;
        while (++input <= N)
        {
            if (check[input] == 0)  // 0은 해당 input 숫자 사용 가능하다는 뜻
            {    
                check[input] = 1;   // 1을 넣어 다음에는 사용 못하도록
                rst[count] = input; // 입력
                DFS(count+1);       // 재귀를 통한 백트래킹
                check[input] = 0;   // rst[0]에 1을 입력하고 아래 12 13 14 ... 뿌리를 내릴텐데
			}                       // 3을 사용해 123을 적고 check를 초기화하지 않으면 143을 적을 수 없다
		}
	}
}

int main()
{
    scanf("%d %d", &N, &M);
    DFS(0);
    return 0;
}
```

-  새로 안 사실

1.
백트래킹 재귀 특성상 파라미터로 변수 선언, main으로 값을 전달

2.
백트래킹은 잘못된 값을 확인한 경우 뿌리를 거슬로 올라가는 것이 아니다
-   뿌리를 경우의 수만큼 다 치는게 맞다
```.c
  1 - 1-1 - 1-1-1
    |     | 1-1-2
    |     - 1-1-3
    |
    | 1-2 - 1-2-1
    |     | 1-2-2
    |     - 1-2-3
    |
    | 1-3 - 1-3-1
    |     | 1-3-2
    |     - 1-3-3
    |        
  2 - 2-1 - ...


```

3.
check를 통해 input 값을 컨트롤 할 수 있다

-----

# [N과M 2](https://www.acmicpc.net/problem/15650) 

### :point_right: [15650](https://github.com/Ejaeda/Data_Structure/blob/master/CodingTest/%EB%B0%B1%EC%A4%80/14_Backtracking/02_15650.c)

- 핵심
```.c
15649 문제 + 오름차순 조건
재귀 시 사용한 숫자를 max로 설정해 max보다 크게 적히도록 추가
```

- 문제접근
```.c
백트래킹 연습
```

- 코드 구현
```.c
#include <stdio.h>

int N, M;                   // 입력받을 두 변수
int rst[1000] = {0, };      // 출력할 내용들을 담을 배열
int check[1000] = {0, };    // 사용한 숫자인지 내용 0과 1로 판단하는 배열

void    DFS(int count, int max)      // input값을 rst배열에 적고 해당 수를 max로 설정하기
{                           
    int input;
    int idx;
    
    if (count == M)         // depth 도달
    {
        idx = -1;
        while (++idx < M)
            printf("%d ", rst[idx]);
        printf("\n");
    }
    else
    {
        input = 0;
        while (++input <= N)
        {
            if (check[input] == 0 && max < input)   // 오름차순 조건
            {    
                check[input] = 1;
                rst[count] = input;
                DFS(count+1, input);      
                check[input] = 0;  
			}                      
		}
	}
}

int main()
{
    scanf("%d %d", &N, &M);
    DFS(0, 0);
    return 0;
}
```

-  새로 안 사실

1.
백트래킹에 추가적인 조건이 생길 경우 파라미터를 추가한다

-----

# [N과M 3](https://www.acmicpc.net/problem/15651) 

### :point_right: [15651](https://github.com/Ejaeda/Data_Structure/blob/master/CodingTest/%EB%B0%B1%EC%A4%80/14_Backtracking/03_15651.c)

- 핵심
```.c
1. 15649와 달리 중복 조건을 해제
```

- 문제접근
```.c
백트래킹 연습
```

- 코드 구현
```.c
        //    if (check[input] == 0)
        //    {    
        //        check[input] = 1;
                rst[count] = input;
                DFS(count+1);
        //        check[input] = 0;
		//	}                    
		
/*  15649 조건 중 중복 확인 조건을 없애준다  */
```

-----

# [N과M 4](https://www.acmicpc.net/problem/15652) 

### :point_right: [15652](https://github.com/Ejaeda/Data_Structure/blob/master/CodingTest/%EB%B0%B1%EC%A4%80/14_Backtracking/02_15652.c)

- 핵심
```.c
15649 문제 + 오름차순 조건 + 중복 가능
15650 문제 + 15661문제
```

- 문제접근
```.c
백트래킹 연습
```

- 코드 구현
```.c
    else
    {
        input = 0;
        while (++input <= N)
        {
        //    if (check[input] == 0 && max < input)
            if (max <= input) // 비내림차순 조건
            {    
        //      check[input] = 1;
                rst[count] = input;
                DFS(count+1, input);      
        //      check[input] = 0;  
			}                      
		}
	}
}
```

-  새로 안 사실

-----