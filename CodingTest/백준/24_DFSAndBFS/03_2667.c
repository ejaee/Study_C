#include <stdio.h>

#define MAX 26
int N;
int map[MAX][MAX] = {0};
int house[MAX*(MAX/2)];
int cnt = 0;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};


void	DFS(int x, int y, int change_num)
{
	int idx, nx, ny;

	map[x][y] = change_num;
	idx = -1;
	while (++idx < 4)
	{
		nx = x + dx[idx];
		ny = y + dy[idx];

		if (nx >= 0 && ny >= 0 && nx < N && ny <N)
		{
			if (map[nx][ny] == 1)
				DFS(nx, ny, change_num);
		}
	}
}

void	setting()
{
	int x, y;

	x = -1;
	while (++x < N)
	{
		y = -1;
		while (++y < N)
		{
			if (map[x][y] == 1)
			{
				cnt++;
				DFS(x, y, cnt + 1);
			}
		}
	}

	x = -1;
	while (++x < N)
	{
		y = -1;
		while (++y < N)
		{
			if (map[x][y] > 1)
				house[map[x][y]-2]++;
		}
	}
}

void	ft_swap(int *arr, int a, int b)
{
	int temp;

	temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void	bubble_sort(int *arr)
{
	int idx, jdx;

	idx = -1;
	while (++idx < cnt)
	{
		jdx = -1;
		while (++jdx < cnt - 1)
		{
			if (arr[jdx] > arr[jdx+1])
				ft_swap(arr, jdx, jdx+1);
		}
	}
}

int main()
{
	int x, y;
	scanf("%d", &N);

	x = -1;
	while (++x < N)
	{
		y = -1;
		while (++y < N)
			scanf("%1d", &map[x][y]);
	}


	setting();
	printf("%d\n", cnt);
	bubble_sort(house);
	x = -1;
	while (++x < cnt)
		printf("%d\n", house[x]);
	return 0;
}
