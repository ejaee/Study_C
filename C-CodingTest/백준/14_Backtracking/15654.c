#include <stdio.h>
#include <stdlib.h>

int		N, M;
int		rst[1000] = {0};
int		check[1000] = {0};

void    DFS(int *num, int count)
{
	int    idx, input;

	if (count == M)
	{
		idx = -1;
		while (++idx < M)
			printf("%d ", rst[idx]);
		printf("\n");
	}
	else
	{
		input = -1;
		while (++input < N)
		{
			if (!check[input])
			{
				check[input] = 1;
				rst[count] = num[input];
				DFS(num, count + 1);
				check[input] = 0;
			}
		}
	}
}

void	b_sort(int *num)
{
	int idx, jdx, temp;
	idx = -1;
	while (++idx < N-1)
	{
		jdx = -1;
		while (++jdx < (N-1)-idx)
		{
			if (num[jdx] > num[jdx+1])
			{
				temp = num[jdx];
				num[jdx] = num[jdx+1];
				num[jdx+1] = temp;
			}
		}
	}
}

int main()
{
	int idx;

	scanf("%d %d", &N, &M);

	int *num = malloc(sizeof(int)*N);

	idx = -1;
	while (++idx < N)
		scanf("%d", &num[idx]);
	b_sort(num);

	DFS(num, 0);
	return 0;
}
