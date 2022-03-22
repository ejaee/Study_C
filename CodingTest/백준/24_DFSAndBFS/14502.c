#include <stdio.h>

#define MAX 8
int N, M, max = 0, count_safe;
int map[MAX][MAX] = {0};
int temp[MAX][MAX] = {0};

int queue[MAX*MAX][2] = {0};

int move[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void	map_copy(int (*a)[MAX], int (*b)[MAX])
{
	int idx, jdx;

	idx = -1;
	while (++idx < N)
	{
		jdx = -1;
		while (++jdx < M)
			b[idx][jdx] = a[idx][jdx];
	}
}

void	spread_v()
{
	int idx, jdx, popx, popy, nx, ny;
	int front, rear;
	int spread_map[MAX][MAX] = {0};

	map_copy(temp, spread_map);

	front = 0;
	rear = 0;
	idx = -1;
	while (++idx < N)
	{
		jdx = -1;
		while (++jdx < M)
		{
			if (spread_map[idx][jdx] == 2)
			{
				queue[rear][0] = idx;
				queue[rear][1] = jdx;
				rear++;
			}
		}
	}
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
		
			if (nx >= 0 && ny >= 0 && nx < M && ny < N)
			{
				if (!spread_map[ny][nx])
				{
					spread_map[ny][nx] = 2;

					queue[rear][0] = ny;
					queue[rear][1] = nx;
					rear++;
				}
			}
		}
	}
	count_safe = 0;
	idx = -1;
	while (++idx < N)
	{
		jdx = -1;
		while (++jdx < M)
		{
			if (spread_map[idx][jdx] == 0)
				count_safe++;
		}
	}
	if (max < count_safe)
		max = count_safe;
}

void	wall(int cnt)
{
	int idx, jdx;

	if (cnt == 3)
	{
		spread_v();
		return ;
	}

	idx = -1;
	while (++idx < N)
	{
		jdx = -1;
		while (++jdx < M)
		{
			if (!temp[idx][jdx])
			{
				temp[idx][jdx] = 1;
				wall(cnt+1);		//DFS
				temp[idx][jdx] = 0;
			}
		}
	}
}

int		main()
{
	int idx, jdx;

	scanf("%d %d", &N, &M);
	idx = -1;
	while (++idx < N)
	{
		jdx = -1;
		while (++jdx < M)
		{
			scanf("%d", &map[idx][jdx]);
		}
	}
	idx = -1;
	while (++idx < N)
	{
		jdx = -1;
		while (++jdx < M)
		{
			if (!map[idx][jdx])
			{
				map_copy(map, temp);
				temp[idx][jdx] = 1;
				wall(1);
				temp[idx][jdx] = 0;
			}
		}
	}
	printf("%d\n", max);
	return 0;
}
