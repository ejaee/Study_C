#include <stdio.h>
#include <string.h>

#define MAX 301

int		chess[MAX][MAX] = {0};
int		queue[MAX*MAX][2] = {0};
int		visit[MAX][MAX] = {0};
int		dy[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int		dx[8] = {1, -1, 2, -2, 2, -2, 1, -1};

int	T, size, x, y, rx, ry;

void	BFS()
{
	int idx, nx, ny, popx, popy, front, rear;

	front = 0;
	rear = 0;

	memset(visit, 0, sizeof(visit));
	memset(queue, 0, sizeof(queue));

	queue[rear][0] = y;
	queue[rear][1] = x;
	rear++;
	visit[y][x] = 1;
	while (front < rear)
	{
		popy = queue[front][0];
		popx = queue[front][1];
		front++;
		idx = -1;
		if (popy == ry && popx == rx)
			printf("%d\n", chess[popy][popx]);
		while (++idx < 8)
		{
			ny = popy + dy[idx];
			nx = popx + dx[idx];
		
			if (nx < 0 || ny < 0 || nx >= size || ny >= size)
				continue ;
			if (visit[ny][nx])
				continue ;
			
				queue[rear][0] = ny;
				queue[rear][1] = nx;
				rear++;
				visit[ny][nx] = 1;
				chess[ny][nx] = chess[popy][popx] + 1;
		}
	}
}

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &size);
		scanf("%d %d", &x, &y);
		scanf("%d %d", &rx, &ry);
		memset(chess, 0, sizeof(chess));
		BFS();
	}
}
