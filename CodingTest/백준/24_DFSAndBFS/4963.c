#include <stdio.h>

#define MAX 51

int map[MAX][MAX] = {0};
int w, h, cnt;

int move[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0},
				{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

void	DFS(int y, int x, int visited)
{
	int idx, nx, ny;

	map[y][x] = visited;
	idx = -1;
	while (++idx < 8)
	{
		ny = y + move[idx][0];
		nx = x + move[idx][1];

		if (nx > 0 && ny > 0 && nx <= w && ny <= h)
		{
			if (map[ny][nx] == 1)
			{
				DFS(ny, nx, visited);
			}
		}
	}
}

int main()
{
	int x, y;

	while (1)
	{
		cnt = 0;
		scanf("%d %d", &w, &h);
		if (w == 0 && h == 0)
			return 0;

		y = 0;
		while (++y <= h)
		{
			x = 0;
			while (++x <= w)
			{
				scanf("%d", &map[y][x]);
			}
		}

		y = 0;
		while (++y <= h)
		{
			x = 0;
			while (++x <= w)
			{
				if (map[y][x] == 1)
				{
					cnt++;
					DFS(y, x, cnt + 1);
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
