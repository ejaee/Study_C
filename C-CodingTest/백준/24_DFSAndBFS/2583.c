#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 101

int N, M, K, x1, y1, x2, y2, cnt, kdx, size;
int map[MAX][MAX] = {0};
int visited[MAX][MAX] = {0};
int queue[MAX*MAX][2] = {0};
int move[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int arr[MAX*(MAX/2)]= {0};

void	BFS(int y, int x)
{
	int front, rear, idx, jdx, nx, ny, popx, popy;

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

			if (nx >= 0 && ny >= 0 && nx < N && ny < M)
			{
				if (!map[ny][nx] && !visited[ny][nx])
				{
					size++;
					queue[rear][0] = ny;
					queue[rear][1] = nx;
					rear++;

					visited[ny][nx] = 1;
				}
			}
		}
	}
}

int main()
{
	int idx, jdx, kdx, time;

	scanf("%d %d %d", &M, &N, &K);
	
	time = K;
	while (time--)
	{
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		idx = y1 - 1;
		while (++idx < y2)
		{
			jdx = x1 - 1;
			while (++jdx < x2)
				map[idx][jdx] = 1;
		}
	}

	cnt = 0;
	kdx = -1;
	idx = -1;
	while (++idx < M)
	{
		jdx = -1;
		while (++jdx < N)
		{
			if (!map[idx][jdx] && !visited[idx][jdx])
			{
				cnt++;
				size = 1;
				BFS(idx, jdx);
			}
			kdx++;
			arr[kdx] = cnt;
			arr[cnt-1] = size; 
		}
	}

	printf("%d\n", cnt);
	int *res;
	res = malloc(sizeof(int)*cnt);
	idx = -1;
	jdx = -1;
	while (++idx < cnt)
	{
		if (arr[idx])
			res[++jdx] = arr[idx];
	}

	int temp = 0;
	idx = -1;
	while (++idx < cnt-1)
	{
		jdx = -1;
		while (++jdx < (cnt-1) - idx)
		{
			if (res[jdx] > res[jdx+1])
			{
				temp = res[jdx];
				res[jdx] = res[jdx+1];
				res[jdx+1] = temp;
			}
		}
	}

	idx = -1;
	while (++idx < cnt)
		printf("%d ", res[idx]);
}
