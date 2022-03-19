#include <stdio.h>

int M, N, H;
int graph[100][100][100] = {0};
int queue[1000000][3] = {0};
int front = 0, rear = 0;
int cnt = 0;

int dz[6] = {0, 0, 0, 0, 1, -1};
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};

int BFS()
{
	int popx, popy, popz;
	int nx, ny, nz;
	int idx;
	
	while (front < rear)
	{
		popz = queue[front][0];
		popx = queue[front][1];
		popy = queue[front][2];
		front++;
		idx = -1;
		while (++idx < 6)
		{
			nz = popz + dz[idx];
			nx = popx + dx[idx];
			ny = popy + dy[idx];
			if (nx >= 0 && ny >= 0 && nz >= 0 && nx < N && ny < M && nz < H)
				if (!graph[nz][nx][ny])
				{
					cnt--;
					graph[nz][nx][ny] = graph[popz][popx][popy] + 1;
					queue[rear][0] = nz;
					queue[rear][1] = nx;
					queue[rear][2] = ny;
					rear++;
				}
		}
	}

	if (!cnt)
		return (graph[popz][popx][popy] - 1);
	return (-1);
}

int main()
{
	int x, y, z;

	scanf("%d %d %d", &M, &N, &H);
	z = -1;
	while (++z < H)
	{
		x = -1;
		while (++x < N)
		{
			y = -1;
			while (++y < M)
			{
				scanf("%d", &graph[z][x][y]);
				if (!graph[z][x][y])
					cnt++;
				else if(graph[z][x][y] == 1)
				{
					queue[rear][0] = z;
					queue[rear][1] = x;
					queue[rear][2] = y;
					rear++;
				}
			}
		}
	}

	printf("%d", BFS());
	return 0;
}
