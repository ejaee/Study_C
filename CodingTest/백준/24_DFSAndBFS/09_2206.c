#include <stdio.h>

#define MAX 1001

int map[MAX][MAX] = {0};
int	N, M;

int queue[MAX*MAX][3] = {0};
// visit[][][1] -> 아직 벽을 뚫지 않았다
// visit[][][0] -> 이미 벽을 뚫었다
int visit[MAX][MAX][2] = {0};
int move[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int		BFS()
{
	int front = 0, rear = 0, popx, popy, popb, nx, ny, idx;

	queue[rear][0] = 1;
	queue[rear][1] = 1;
	queue[rear][2] = 1;
	rear++;
	visit[1][1][1] = 1;

	while (front < rear)
	{
		popy = queue[front][0];
		popx = queue[front][1];
		popb = queue[front][2];
		front++;

		if (popy == N && popx == M)
			return (visit[popy][popx][popb]);

		idx = -1;
		while (++idx < 4)
		{
			ny = popy + move[idx][0];
			nx = popx + move[idx][1];
			
			if (nx >= 1 && ny >= 1 && nx <= M && ny <= N)
			{
				// 1이지만 block 가능한가
				if (map[ny][nx] == 1 && popb)
				{
					queue[rear][0] = ny;
					queue[rear][1] = nx;
					queue[rear][2] = popb - 1;
					rear++;

					visit[ny][nx][popb-1] = visit[popy][popx][popb] + 1;
				}
				// 0 이고 방문한 적이 없는가
				else if (!map[ny][nx] && !visit[ny][nx][popb])
				{
					queue[rear][0] = ny;
					queue[rear][1] = nx;
					queue[rear][2] = popb;
					rear++;

					visit[ny][nx][popb] = visit[popy][popx][popb] + 1;
				}
			}
		}
	}
	return (-1);
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
			scanf("%1d", &map[idx][jdx]);
	}
	printf("%d", BFS());
	return 0;

}
