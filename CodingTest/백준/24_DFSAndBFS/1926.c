#include <stdio.h>

#define MAX 501

int n, m, cnt = 0, max_size = 0, size = 0;
int map[MAX][MAX] = {0};
int queue[MAX*MAX][2] = {0};
int move[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int visited[MAX][MAX] = {0};
int front, rear;

void	BFS()
{
	int popx, popy, nx, ny, idx, jdx;

	while (front < rear)
	{
		popy = queue[front][0];
		popx = queue[front][1];
		front++;

		idx = -1;
		while (++idx < 4)
		{
			ny = popy + move[idx][0];
			nx = popx + move[idx][1];

			if (nx >= 0 && ny >= 0 && nx < m && ny < n)
			{
				if (map[ny][nx] && !visited[ny][nx])
				{
					queue[rear][0] = ny;
					queue[rear][1] = nx;
					rear++;
					size++;

					visited[ny][nx] = size;
				}
			}
		}
	}
}

int main()
{
	int idx, jdx;

	scanf("%d %d", &n, &m);
	idx = -1;
	while (++idx < n)
	{
		jdx = -1;
		while (++jdx < m)
			scanf("%d", &map[idx][jdx]);
	}

	cnt = 0;
	front = 0;
	rear = 0;
	idx = -1;
	max_size = 0;
	while (++idx < n)
	{
		jdx = -1;
		while (++jdx < m)
		{
			if (map[idx][jdx] && !visited[idx][jdx])
			{
				cnt++;
				size = 1;
				queue[rear][0] = idx;
				queue[rear][1] = jdx;
				rear++;
				visited[idx][jdx] = size;
				BFS();
			}
		}
		if (max_size < size)
			max_size = size;
	}
	printf("%d\n%d", cnt, max_size);
}
