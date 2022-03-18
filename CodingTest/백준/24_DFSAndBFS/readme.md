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