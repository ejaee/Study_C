#include <stdio.h>

#define MAX 1001

int N, M, x, y, cnt = 0;
int map[MAX][MAX] = {0};
int v[MAX] = {0};

void	DFS(int x)
{
	int idx;

	v[x] = 1;
	idx = 0;
	while (++idx <= N)
	{
	
		if (map[x][idx] == 1 && !v[idx])
			DFS(idx);
	}
}

int main()
{
	int idx;

	scanf("%d %d", &N, &M);
	idx = -1;
	while (++idx < M)
	{
		scanf("%d %d", &x, &y);
		map[x][y] = 1;
		map[y][x] = 1;
	}

	idx = 0;
	while (++idx <= N)
	{
		if (v[idx] == 0)
		{
			cnt++;
			DFS(idx);
		}
	}

	printf("%d", cnt);
}
