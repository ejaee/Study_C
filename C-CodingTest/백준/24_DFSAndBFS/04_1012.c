#include <stdio.h>

#define MAX 50

int T, M, N, K, X, Y;
int map[MAX][MAX] = {0};

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int cnt;

void	DFS(int x, int y, int visited_sign)
{
	int idx, nx, ny;

	map[x][y] = visited_sign;

	idx = -1;
	while (++idx < 4)
	{
		nx = x + dx[idx];
		ny = y + dy[idx];

		if (nx >= 0 && ny >= 0 && nx < N && ny < M)
		{
			if (map[nx][ny] == 1)
			{
				DFS(nx, ny, visited_sign);
			}
		}
	}

	return ;
}

int	main()
{
	int idx, jdx;
	scanf("%d", &T);

	while (T--)
	{
		cnt = 0;
		scanf("%d %d %d", &M, &N, &K);
		while (K--)
		{
			scanf("%d %d", &Y, &X);
			map[X][Y] = 1;
		}

		idx = -1;
		while (++idx < N)
		{
			jdx = -1;
			while (++jdx < M)
			{
				if (map[idx][jdx] == 1)
				{	
					cnt++;
					DFS(idx, jdx, cnt+1);
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
