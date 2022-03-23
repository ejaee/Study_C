#include <stdio.h>

#define MAX 101

int visited[MAX][MAX] = {0};
int map[MAX][MAX] = {0};
int temp[MAX][MAX] = {0};
int queue[MAX*MAX][2] = {0};
int move[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int N, cnt, max_cnt = 0;

void	copy_map(int (*src)[N], int (*dest)[N])
{
	int idx, jdx;

	idx = -1;
	while (++idx < N)
	{
		jdx = -1;
		while (++jdx < N)
		{
			dest[idx][jdx] = src[idx][jdx];
		}
	}
}

void	BFS()
{
	int front, rear, popx, popy, nx, ny;
	int idx, jdx;

	front = 0;
	rear = 0;
	idx = -1;
	while (++idx < N)
	{
		jdx = -1;
		while (++jdx < N)
		{
			if (!temp[idx][jdx])
			{
				queue[rear][0] = idx;
				queue[rear][1] = jdx;
				rear++;
			}
		}
	}
printf("done push values '0'\n");
	cnt = 0;
	while (front < rear)
	{
		popy = queue[front][0];
		popx = queue[front][1];

		if (visited[popy][popx])
			continue;

		cnt++;
		visited[popy][popx] = cnt;
		idx = -1;
		while (++idx < 4)
		{
			ny = popy + move[idx][0];
			nx = popx + move[idx][1];

			if (ny >= 0 && nx >= 0 && ny < N && nx < N)
			{
				if (!temp[ny][nx] && !visited[ny][nx])
				{
					visited[ny][nx] = cnt;

					queue[rear][0] = ny;
					queue[rear][1] = nx;
					rear++;
				}
			}
		}
	}
	if (max_cnt < cnt)
		max_cnt = cnt;
printf("done one cycle max_cnt is %d\n", max_cnt);
}

int main()
{
	int idx, jdx, min, max, h;

	scanf("%d", &N);

	min = MAX;
	max = 0;
	idx = -1;
	while (++idx < N)
	{
		jdx = -1;
		while (++jdx < N)
		{
			scanf("%d", &map[idx][jdx]);
			if (max < map[idx][jdx])
				max = map[idx][jdx];
			if (min > map[idx][jdx])
				min = map[idx][jdx];
		}
	}
printf("input map done and setting max %d, min %d\n", max, min);
	h = min - 1;
	while (++h <= max)
	{
		copy_map(map, temp);
		idx = -1;
		while (++idx < N)
		{
			jdx = -1;
			while (++jdx < N)
			{
				if (temp[idx][jdx] > h)
					temp[idx][jdx] = 0;
			}
		}
printf("BFS!\n");
		BFS();
	}
	printf("%d\n", max_cnt);
}
