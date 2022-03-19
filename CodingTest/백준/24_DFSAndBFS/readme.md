# [DFS와 BFS](https://www.acmicpc.net/problem/1260) 

### :point_right: [1260](https://github.com/Ejaeda/Data_Structure/blob/master/CodingTest/%EB%B0%B1%EC%A4%80/24_DFSAndBFS/01_1260.c)

- 핵심
```.c
1. DFS와 BFS 기본
```

- 문제접근
```.c
1. graph를 배열로 표현
2. DFS 함수
3. BFS 함수
```

- 코드 구현
1. graph를 배열로 표현
```.c
#include <stdio.h>
#define MAX_N 1001
int gragh[MAX_N][MAX_N] = {0};

int main()
{
    int N, M, V;
    int i, j;

    i = 0;
    scanf("%d %d %d", &N, &M, &V);
    while (M--)
    {
        scanf("%d %d", &i, &j);
        graph[i][j] = 1;
        graph[j][i] = 1;
    }
}
```

2. DFS
```.c
int use_DFS[MAX_N] = {0};

void    DFS(int N, int V)
{
    int idx;

    use_DFS[V] = 1;
    printf("%d", V);

    idx = 0;
    while (++idx <= N)
    {
        if (graph[V][idx] && !use_DFS[V])
            DFS(N, idx);
    }
}
```

3. BFS
```.c
int use_BFS[MAX_N] = {0};
int queue[MAX_N] = {0};

void    BFS(int N, int V)
{
    int front, rear, pop, idx;
    front = rear = 0;

    use_BFS[V] = 1;
    printf("%d", V);
    queue[rear] = V;
    rear++;
    while (front < rear)
    {
        pop = queue[front]
        front++;
        idx = 0;
        while (++idx <= N)
        {
            if (graph[pop][idx] && !use_BFS[idx])
            {
                printf("%d", idx);
                queue[rear] = idx;
                rear++;
                use_BFS = 1;
            }
        }
    }
}
```
-  새로 안 사실

💡 BFS

    -   front = 0, rear = 0, pop 사용
    -   출력한 숫자 1로 썻다 표시
    -   queue[rear] = V 넣고 rear++
    -   rear++  하더라도 front가 해당 숫자 책임
    -   gragh[방금쓴 숫자][idx++] 확인
    -   idx 출력하고 쓴 숫자 queue[rear]에 담고 rear++ 
    -   쓴 숫자 1 처리 
    -   쓴 숫자를 바로 행으로 넣으니까 BFS

💡 그래프를 배열로 표시하는 방법

    -   2차원 배열 idx, jdx를 통해 1값 넣기

💡 중복 사용하지 않는법

    -   숫자 1차원 배열을 만들고 사용했다면 1값 주기
    
💡 DFS 와 BFS

    -   DFS 는 재귀를 사용한다
    -   BFS 는 queue를 사용한다

-----

# [미로 탐색]](https://www.acmicpc.net/problem/2178) 

### :point_right: [2178](https://github.com/Ejaeda/Data_Structure/blob/master/CodingTest/%EB%B0%B1%EC%A4%80/24_DFSAndBFS/05_2178.c)

- 핵심
```.c
1. 각 정점을 최단 경로로 방문하는 BFS를 활용
```

- 문제접근
```.c
1. graph를 배열로 표현
2. BFS 함수

* 어떻게 이동 시킬 것인가?

* 각각의 수들은 붙어서 입력 -> "%1d", graph[idx][jdx]
```

- 코드 구현
1. graph를 배열로 표현
```.c
    // (1,1)부터 출발하므로 graph[1][1] 부터 입력받기

    scanf("%d %d", &N, &M);

    idx = 0
    while (++idx <= N)
    {
        jdx = 0;
        while (++jdx <= M)
        {
            printf("%1d", &graph[idx][jdx]);
        }
    }
```

2. BFS
```.c
    // 어떻게 이동 시킬 것인가?
    //          동  서  남  북
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    // 1. while 문을 돌리면서 동 서 남 북으로 이동 시키기
    // 2. 만약 이동한 지점이 범위를 벗어나거나
    //    이동한 지점이 1이 아닌 경우는 그냥 넘기기
    // 3. 위 조건을 모두 충족 한다면 이동 + count++;

    // BFS는 queue를 활용
    // 1. queue에 시작 점을 담고
    // 2. 담을 때마다 rear++;
    // 3. pop에 queue[front] 주고 
    // 4. 줄 때마다front++;

    int BFS()
    {
        int front, rear, pop_x, pop_y;
        int move_x, move_y;

        front = rear = 0;
        queue[rear][0] = 1; (x = 1) // (1,1)에서 출발
        queue[rear][1] = 1; (y = 1)
        rear++;

        while (front < rear)
        {
            // 반복문마다 동 서 남 북 이동
            pop_x = queue[front][0];
            pop_y = queue[front][1];
            front++;

            idx = -1;
            while (++idx < N)
            {
                move_x = pop_x + dx[idx];
                move_y = pop_y + dy[idx];
            
                // 영역 이탈
                if (move_x < 1 || move_y < 1 
                || move_x > N || move_y > M)
                    continue;

                // 영역 내용이 1
                if (graph[move_x][move_y] != 1)
                    continue;

                // 이동한 좌표가 가능하다면 해당 영역에 +1
                // 마지막 도착점인 [N][M]의 값을 출력하면 되니까
                graph[move_x][move_y] = graph[pop_x][pop_y] + 1;
                queue[rear][0] = move_x;
                queue[rear][1] = move_y;
                rear++;
            }
        }
        return (graph[N][M]);
    }

```
-  새로 안 사실

💡 붙어서 하나씩 입력받고 싶을 때

    -   printf("%1d", &arr[][]);
>   %1d를 쓰면 입력받은 정수도 문자 단위로 나누어서 처리가 가능하다

💡 BFS

    -   front = 0, rear = 0,
>   front == rear 는 queue가 비었음을 의미
    -   queue에 시작점을 rear로 저장하고 rear++;
    -   queue에 저장값을 front로 빼고 front++; 
>   뺀 값은pop에 저장
    -   시작점에서 동 서 남 북 이동 후 가능한 영역에 +1을 해야하므로
>   dx[4] = {1, -1, 0, 0};  dy[4] = {0, 0, -1, 1}; 사용
    -   pop + dx, dy 이동 값을 move_x, move_y 변수에 저장

💡 DFS 와 BFS

    -   DFS 는 재귀를 사용한다
    -   BFS 는 queue를 사용한다

-----

# [미로 탐색]](https://www.acmicpc.net/problem/2178) 

### :point_right: [2178](https://github.com/Ejaeda/Data_Structure/blob/master/CodingTest/%EB%B0%B1%EC%A4%80/24_DFSAndBFS/05_2178.c)

- 핵심
```.c
1. 각 정점을 최단 경로로 방문하는 BFS를 활용
```

- 문제접근
```.c
1. graph를 배열로 표현
2. BFS 함수

* 어떻게 이동 시킬 것인가?

* 각각의 수들은 붙어서 입력 -> "%1d", graph[idx][jdx]
```

- 코드 구현
1. graph를 배열로 표현
```.c
    // (1,1)부터 출발하므로 graph[1][1] 부터 입력받기

    scanf("%d %d", &N, &M);

    idx = 0
    while (++idx <= N)
    {
        jdx = 0;
        while (++jdx <= M)
        {
            printf("%1d", &graph[idx][jdx]);
        }
    }
```

2. BFS
```.c
    // 어떻게 이동 시킬 것인가?
    //          동  서  남  북
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    // 1. while 문을 돌리면서 동 서 남 북으로 이동 시키기
    // 2. 만약 이동한 지점이 범위를 벗어나거나
    //    이동한 지점이 1이 아닌 경우는 그냥 넘기기
    // 3. 위 조건을 모두 충족 한다면 이동 + count++;

    // BFS는 queue를 활용
    // 1. queue에 시작 점을 담고
    // 2. 담을 때마다 rear++;
    // 3. pop에 queue[front] 주고 
    // 4. 줄 때마다front++;

    int BFS()
    {
        int front, rear, pop_x, pop_y;
        int move_x, move_y;

        front = rear = 0;
        queue[rear][0] = 1; (x = 1) // (1,1)에서 출발
        queue[rear][1] = 1; (y = 1)
        rear++;

        while (front < rear)
        {
            // 반복문마다 동 서 남 북 이동
            pop_x = queue[front][0];
            pop_y = queue[front][1];
            front++;

            idx = -1;
            while (++idx < N)
            {
                move_x = pop_x + dx[idx];
                move_y = pop_y + dy[idx];
            
                // 영역 이탈
                if (move_x < 1 || move_y < 1 
                || move_x > N || move_y > M)
                    continue;

                // 영역 내용이 1
                if (graph[move_x][move_y] != 1)
                    continue;

                // 이동한 좌표가 가능하다면 해당 영역에 +1
                // 마지막 도착점인 [N][M]의 값을 출력하면 되니까
                graph[move_x][move_y] = graph[pop_x][pop_y] + 1;
                queue[rear][0] = move_x;
                queue[rear][1] = move_y;
                rear++;
            }
        }
        return (graph[N][M]);
    }

```
-  새로 안 사실

💡 붙어서 하나씩 입력받고 싶을 때

    -   printf("%1d", &arr[][]);
>   %1d를 쓰면 입력받은 정수도 문자 단위로 나누어서 처리가 가능하다

💡 BFS

    -   front = 0, rear = 0,
>   front == rear 는 queue가 비었음을 의미
    -   queue에 시작점을 rear로 저장하고 rear++;
    -   queue에 저장값을 front로 빼고 front++; 
>   뺀 값은pop에 저장
    -   시작점에서 동 서 남 북 이동 후 가능한 영역에 +1을 해야하므로
>   dx[4] = {1, -1, 0, 0};  dy[4] = {0, 0, -1, 1}; 사용
    -   pop + dx, dy 이동 값을 move_x, move_y 변수에 저장
    
💡 DFS 와 BFS

    -   DFS 는 재귀를 사용한다
    -   BFS 는 queue를 사용한다

-----