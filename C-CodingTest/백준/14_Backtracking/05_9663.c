#include <stdio.h>

int	chess[15] = {0, };

int		ft_abs(int a, int b)
{
	return (a-b > 0 ? a - b : b - a);
}

int		is_pos(int row, int col)
{
	int	idx;

	idx = -1;
	while (++idx < row)
	{
		if (chess[idx] == col || (row -  idx) == ft_abs(chess[idx],  col))
			return 0;
	}
	return 1;
}

void	DFS(int N, int row, int *rst)
{
	int col;
	int	idx;

	if (row == N)
	{
		(*rst)++;
	//	idx = -1;
	//	while (++idx < N)
	//		printf("%d", chess[idx]);
	//	printf("\n");
	}
	else
	{
		col = 0;
		while (col < N)
		{
			if (is_pos(row, col))
			{
				chess[row] = col;
				DFS(N, row + 1, rst);
			}
			col++;
		}
	}
}

int	main()
{
	int	N;
	int rst;

	rst = 0;
	scanf("%d", &N);
	DFS(N, 0, &rst);
	printf("%d\n", rst);
	return 0;
}
