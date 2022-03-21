#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 301

int T, I, x, y, rx, ry;

int chess[MAX][MAX] = {0};
int queue[MAX*MAX][2] = {0};
int front, rear;

int dx[8] = {1, 2, 1, 2, -1, -2, -1, -2};
int dy[8] = {2 ,1, -2, -1, 2, 1, -2, -1};

bool v[MAX][MAX] = {0};

int		BFS()
{
	int popx, popy, nx, ny, idx;

	memset(v, 0, sizeof(v));
	memset(queue, 0, sizeof(queue));
	front = 0, rear = 0;

	queue[rear][0] = x;
	queue[rear][1] = y;
	rear++;
	v[x][y] = true;
	while (front < rear)
	{
		popx = queue[front][0];
		popy = queue[front][1];
		front++;

		idx = -1;
		while (++idx < 8)
		{
			nx = popx + dx[idx];
			ny = popy + dy[idx];

			if (nx >= 0 && ny >= 0 && nx < I && ny < I \
					&& !v[nx][ny])
			{
				if (chess[rx][ry] != chess[nx][ny])
				{
					
					chess[nx][ny] = chess[popx][popy] + 1;
					queue[rear][0] = nx;
					queue[rear][1] = ny;
					rear++;
					v[nx][ny] = true;
				}
			}
		}
	}
	return (chess[popx][popy]);
}

int	main()
{
	scanf("%d", &T);

	while (T--)
	{
		scanf("%d", &I);
		memset(chess, 0, sizeof(chess));
		scanf("%d %d", &x, &y);
		scanf("%d %d", &rx, &ry);
		printf("%d\n", BFS());
	}
}
