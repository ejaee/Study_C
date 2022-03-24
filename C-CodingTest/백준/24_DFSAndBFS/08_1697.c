#include <stdio.h>

int N, K;
int graph[100001] = {0};
int dx[2] = {1, -1};
int visit[100001] = {0};

int queue[100001] = {0};
int front = 0, rear = 0;

int BFS()
{
    int popw, popt;
    int wdx, tpx;
    int wp, tp, idx;

    while (front < rear)
    {
        if (N == K)
            break;
        
        popw = queue[front];
        popt = queue[front];
        front++;

        idx = -1;
        while (++idx < 2)
        {
            wp = popw + dx[idx];
            if (wp >= 0 && wp < 100001 && !visit[wp])
            {
                visit[wp] = visit[popw] + 1;
                queue[rear] = wp;
                rear++;
            }
        }
        tp = popt * 2;
        if (tp >= 0 && tp < 100001 && !visit[tp])
        {
            visit[tp] = visit[popt] + 1;
            queue[rear] = tp;
            rear++;
        }
    }
    return (visit[K]);

}


int main()
{
    scanf("%d %d", &N, &K);
    queue[rear] = N;
    rear++;
    printf("%d", BFS());
    return 0;
}
