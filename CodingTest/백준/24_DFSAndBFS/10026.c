#include <stdio.h>
#include <string.h>

#define MAX 101

int N, cnt;
char map[MAX][MAX] = {0};
int move[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int visited[MAX][MAX] = {0};
int queue[MAX*MAX][2] = {0};

void	BFS(int y, int x)
{
	int front, rear, popx, popy, nx, ny, idx, jdx;

	visited[y][x] = 1;
	front = 0;
	rear = 0;

	queue[rear][0] = y;
	queue[rear][1] = x;
	rear++;
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

			if (nx >= 0 && ny >= 0 && nx < N && ny < N)
			{
				if (map[ny][nx] == map[popy][popx] && !visited[ny][nx])
					{
						queue[rear][0] = ny;
						queue[rear][1] = nx;
						rear++;

						visited[ny][nx] = 1;
					}
			}
			
		}
	}

	
}

void GtoR()
{
	int idx, jdx;

	idx = -1;
	while (++idx < N)
	{
		jdx = -1;
		while (++jdx < N)
		{
			if (map[idx][jdx] == 'G')
				map[idx][jdx] = 'R';
		}
	}
}

int main()
{
	int idx, jdx;

	scanf("%d", &N);
	idx = -1;
	while (++idx < N)
	{
			scanf("%s", &map[idx][0]);
	}

	cnt = 0;
	idx = -1;
	while (++idx < N)
	{
		jdx = -1;
		while (++jdx < N)
		{
			if (!visited[idx][jdx])
			{
				cnt++;
				BFS(idx, jdx);
			}
		}
	}
	printf("%d ", cnt);
	GtoR();
	memset(visited, 0, sizeof(visited));

	cnt = 0;
	idx = -1;
	while (++idx < N)
	{
		jdx = -1;
		while (++jdx < N)
		{
			if (!visited[idx][jdx])
			{
				cnt++;
				BFS(idx, jdx);
			}
		}
	}
	printf("%d", cnt);
}
