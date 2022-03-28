#include <stdio.h>
#include <stdlib.h>

int map[9][9] = {0};
int row[9][10] = {0};
int col[9][10] = {0};
int square[9][10] = {0};

void	DFS(int y, int x)
{
	int idx, jdx, num;

	if (y == 9)
	{
		idx = -1;
		while (++idx < 9)
		{
			jdx = -1;
			while (++jdx < 9)
				printf("%d ", map[idx][jdx]);
			printf("\n");
		}
		exit(0);
	}

	if (map[y][x])
		x == 8 ? DFS(y + 1, 0) : DFS(y, x + 1);
	else
	{
		num = 0;
		while (++num < 10)
		{
			if (!row[y][num] && !col[x][num] && !square[((y/3)*3) + (x/3)][num])
			{
				map[y][x] = num;
				row[y][num] = 1;
				col[x][num] = 1;
				square[((y/3)*3) + (x/3)][num] = 1;
				// DFS로 이동한다는 것은
				// 해당 칸을 채웠다는 것을 의미하므로
				// 그 다음칸으로 이동한다는 것을 뜻함
				x == 8 ? DFS(y + 1, 0) : DFS(y, x + 1);
				map[y][x] = 0;
				row[y][num] = 0;
				col[x][num] = 0;
				square[((y/3)*3) + (x/3)][num] = 0;
			}	
		}
	}
}

int main()
{
	int idx, jdx;

	idx = -1;
	while (++idx < 9)
	{
		jdx = -1;
		while (++jdx < 9)
		{
			scanf("%d", &map[idx][jdx]);
			if (map[idx][jdx])
			{
				row[idx][map[idx][jdx]] = 1;
				col[jdx][map[idx][jdx]] = 1;
				square[((idx/3)*3) + (jdx/3)][map[idx][jdx]] = 1;
			}
		}
	}

	DFS(0, 0);
	return (0);
}
