# 📌 Backtracking

## 📌 [N과M 1](https://www.acmicpc.net/problem/15649) 

### [15649](https://github.com/Ejaeda/Data_Structure/blob/master/CodingTest/%EB%B0%B1%EC%A4%80/14_Backtracking/01_15649.c)

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

## 📌 [N과M 2](https://www.acmicpc.net/problem/15650) 

### [15650](https://github.com/Ejaeda/Data_Structure/blob/master/CodingTest/%EB%B0%B1%EC%A4%80/14_Backtracking/02_15650.c)

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

## 📌 [N과M 3](https://www.acmicpc.net/problem/15651) 

### [15651](https://github.com/Ejaeda/Data_Structure/blob/master/CodingTest/%EB%B0%B1%EC%A4%80/14_Backtracking/03_15651.c)

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

## 📌 [N과M 4](https://www.acmicpc.net/problem/15652) 

### [15652](https://github.com/Ejaeda/Data_Structure/blob/master/CodingTest/%EB%B0%B1%EC%A4%80/14_Backtracking/02_15652.c)

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

## 📌 [N과M 3](https://www.acmicpc.net/problem/15651) 

### [15651](https://github.com/Ejaeda/Data_Structure/blob/master/CodingTest/%EB%B0%B1%EC%A4%80/14_Backtracking/03_15651.c)

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

# 📌 [N-Queen](https://www.acmicpc.net/problem/9663) 

### [9663](https://github.com/Ejaeda/Data_Structure/blob/master/CodingTest/%EB%B0%B1%EC%A4%80/14_Backtracking/05_9663.c)

- 핵심
```.c
N-Queen 문제
```

- 문제접근
```.c

N-queen 조건

1.  row != chess[idx]
2.  row - idx != abs(col - chess[idx])
```

- 코드 구현
```.c
// row로 크게 가지를 치고 col로 세부 컨트롤
// row는 depth, col은 input number
    void DFS(int N, int row, int *rst)
    {
        int col;
        int idx;

        if (row == N)
            (*rst)++;
        else
        {
            col = -1;
            while (++col < N)
            {
                if(is_pos(row, col))
                {
                    chess[row] = col;
                    DFS(N, row, rst);
                }
            }
        }

    }
```

-  새로 안 사실 🚨
main함수에서 정의한 int rst를 DFS에서 더해주고 연결 지으려면

1. def int rst in main func
> 결과를 받아 출력할 것이므로

2. connect DFS( ... , &rst) and void DFS( ... , int *rst)
> 포인터로 연결되어야 연동이 가능

3. recur DFS( ... , rst) in DFS func 🚨
> int *rst를 재귀함수로 전달할 때 그대로 rst
> int *rst = rst

4. plus (*rst)++ in DFS func
> 값을 더해주어야 하므로

-----

## 📌 [스도쿠](https://www.acmicpc.net/problem/2580) 

### [2580](https://github.com/Ejaeda/Data_Structure/blob/master/CodingTest/%EB%B0%B1%EC%A4%80/14_Backtracking/06_2580.c)

- 핵심
```.c
스도쿠 결과를 1개 출력하기
```

- 문제접근
```.c

스도쿠 조건

1.  row, col, square 모두 하나의 숫자를 사용하여 채우기
2.  DFS 사용
```

- 🚨🚨🚨🚨🚨🚨 코드 구현 + 새로 안 사실 🚨🚨🚨🚨🚨🚨

자리와 숫자 사용 현황을 2차원 배열로 한번에 체크할 수 있다
> check_row[row][map[idx][jdx]];<br>
> check_col[col][map[idx][jdx]];<br>
> check_sq[(col/3)*3 + (row/3)][map[idx][jdx]];

1. 스도쿠의 작은 네모 9칸을 0~9라고 했을 떄
> `(col/3)*3 + (row/3)` 로 접근할 수 있다

2. 스도쿠에서 DFS가 넘어가는 조건은 해당 칸이 숫자로 채워졌고 다음 숫자를 적을 칸으로 이동한다는 뜻
> col이 8이면 row를 +1해야 하므로<br>

`col == 8 ? DFS(row + 1, 0) : DFS(row, col + 1);`<br>
> 🚨 삼항연산자를 사용하면 단순해진다!

3. 숫자를 부여한 후 해당칸에 다른 숫자도 넣기 위해 초기화 필요
```.c
    map[y][x] = num;
    row[y][num] = 1;
    col[x][num] = 1;
    square[((y/3)*3) + (x/3)][num] = 1;

    x == 8 ? DFS(y + 1, 0) : DFS(y, x + 1);

    map[y][x] = 0;
    row[y][num] = 0;
    col[x][num] = 0;
    square[((y/3)*3) + (x/3)][num] = 0;
```

-----

# 추가문제

## 📌 [로또](https://www.acmicpc.net/problem/6603) 

### [6603](https://github.com/Ejaeda/Data_Structure/blob/master/CodingTest/%EB%B0%B1%EC%A4%80/14_Backtracking/6603.c)

- 핵심
```.c
DFS 문제
```

- 문제접근
```.c

1.  49개 숫자 중 6개를 출력하는데
2.  임의의 k개를 뽑아 집합 s를 만들고
3.  k개 중 6개를 뽑아 출력한다 
4.  이때 숫자 반복 불가, 숫자 오름차순 출력
```

- 코드 구현
 
```.c
void    DFS(int input, int idx)
{
    // 출력 조건 == 총 6개가 선택되어야 한다
    if (input == 6)
    {
        ...
    }

    // 6개를 뽑는 과정
    // 이전 DFS 과정에서 사용한 숫자보다 높은 숫자를 선택하기위해
    // 인자(idx)로 이어준다
    idx--;
    while (++idx < k)
    {
        // 중복이 불가하므로
        if (!visit[idx])
        {
            // 사용 표시
            visit[idx] = 1;
            // index번째 출력 칸에 idx번째 숫자를 넣는다
            res[index] = num[idx];
            DFS(index+1, idx+1);
            // 다음에 다시 숫자를 사용할 수 있도록 사용 표시 제거
            // 1 2 ... 이후 2 3 에 2를 사용하기 위해
            visit[idx] = 0;
        }
}
```

-  새로 안 사실 🚨
DFS를 더 정형화시켜 공부할 필요가 있다

1. 숫자를 반복시키고 싶지 않다면
> visit[]를 활용한다

2. 오름차순으로 값을 쌓고 싶다면
> 매개변수로 값을 주고 받기

-----

## 📌 [부분수열의 합](https://www.acmicpc.net/problem/1182) 

### [1182](https://github.com/Ejaeda/Data_Structure/blob/master/CodingTest/%EB%B0%B1%EC%A4%80/14_Backtracking/1182.c)

- 핵심
```.c
DFS 문제
```

- 문제접근
```.c

1.  N개 수의 부분 합이 S가 되는 경우의 수 구하기
2.  숫자 반복 불가
3.  반복 제거 => 오름차순
```

- 코드 구현
 
```.c
// 오름차순 선택을 위한 input
// 결과 초기화를 위한 res
void    DFS(int input, res)
{
    // 출력 조건 == 합이 S
    if (res = S)
    {
        cnt
    }

    // N개 이하로 뽑아야 함
    idx = input-1;
    while (++idx < N)
    {
        // 중복이 불가하므로
        if (!visit[idx])
        {
            // 사용 표시
            visit[idx] = 1;
            // res 원본을 살려놔야 다음 반복문에서 돌릴 수 있다
            DFS(idx+1, res + num[idx]);
            // 다음에 다시 숫자를 사용할 수 있도록 사용 표시 제거
            visit[idx] = 0;
        }
    }
}
```
예외처리 -> cnt를 0으로 셋팅하므로 S가 0일경우 -1 해준다

-  새로 안 사실 🚨
게속 더해지는 res는 원본이 보존되어야 다양하게 depth를 내릴 수 있다

1. 매개변수를 선언하는 조건
> 반복이 되지 않게끔 순서상 오름차순으로 숫자를 뽑고싶을 경우
> 원본을 보존하면서 결과값에 변화를 주는 경우

-----

## 📌 [차이를 최대로](https://www.acmicpc.net/problem/10819) 

### [10819](https://github.com/Ejaeda/Data_Structure/blob/master/CodingTest/%EB%B0%B1%EC%A4%80/14_Backtracking/10819.c)

- 핵심
```.c
DFS 문제
```

- 문제접근
```.c
1.  |A[0] - A[1]| + |A[1] - A[2]| + ... + |A[N-2] - A[N-1]| 의 최대값 구하기
```

- 실수
문제에서 식을 제시하는 경우
1. 임의의 배열에 숫자를 배치
2. 완성된 배열을 계산하는 함수를 따로 만들기
3. 문제에서 주어지는 함수를 반복문 내의 식으로 사용하기
> 이 모든것을 DFS에서 다 해결하려고 하니 문제가 발생했다


- 코드 구현
 
```.c
void    cal()
{
    int idx;

    res = 0;
    idx = -1;
    while (++idx < N-1)
        res += abs(temp[idx] - temp[idx+1]);
    if (max < res)
        max = res;
}
```
예외처리 -> cnt를 0으로 셋팅하므로 S가 0일경우 -1 해준다

-  새로 안 사실 🚨
처음보는 식이 주어질 경우 배열 배치 + 계산 이분화 하는게 더 단순하다

-----
