#include <stdio.h>

int	N, M;
int rst[1000] = {0, };
int check[1000] = {0, };

void	DFS(int count, int max)
{
	int	idx;
	int input;

	if (count == M)
	{
		idx = -1;
		while (++idx < M)
			printf("%d ", rst[idx]);
		printf("\n");
	}
	else
	{
		input = 0;
		while (++input <= N)
		{
			if (check[input] == 0 && max < input)
			{
				check[input] = 1;
				rst[count] = input;
				DFS(count + 1, input);
				check[input] = 0;
			}
		}
	}
}

int	main()
{
	scanf("%d %d", &N ,&M);

	DFS(0, 0);
	return 0;
}
