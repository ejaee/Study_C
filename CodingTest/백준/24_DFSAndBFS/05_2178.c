#include <stdio.h>

int graph[101][101] = {0, };
int visit[10001][2] = {0, };

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int N, M;

int DFS()
{
	int front = 0, rear = 0;
	int	pop_x, pop_y;
	int nx, ny;
	int idx;

	visit[rear][0] = 1;
	visit[rear][1] = 1;
	rear++;

	while (front < rear)
	{
		pop_x = visit[front][0];
		pop_y = visit[front][1];
		front++;
		idx = -1;
		while (++idx < 4)
		{
			nx = pop_x + dx[idx];
			ny = pop_y + dy[idx];

			if (nx < 1 || ny < 1 || nx > N || ny > M)
				continue;

			if (graph[nx][ny] != 1)
				continue;

			graph[nx][ny] = graph[pop_x][pop_y] + 1;
			visit[rear][0] = nx;
			visit[rear][1] = ny;
			rear++;
		}
	}
	return (graph[N][M]);
}

int main()
{
	int idx, jdx;

	scanf("%d %d", &N, &M);
	idx = 0;
	while (++idx <= N)
	{
		jdx = 0;
		while (++jdx <= M)
			scanf("%1d", &graph[idx][jdx]);
	}

	printf("%d", DFS());
	return 0;
}
