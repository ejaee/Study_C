#include <stdio.h>

#define MAX 11

int		N, max = -100000001, min = 100000001;
int		num[MAX] = {0};
int		op[4] = {0};

void	DFS(int res, int input)
{
	int idx;

	if (input == N)
	{
		if (max < res)
			max = res;
		if (min > res)
			min = res;
		return ;
	}

	else
	{
		idx = -1;
		while (++idx < 4)
		{
			if (op[idx])
			{
				op[idx]--;
				if (idx == 0)
					DFS(res + num[input], input+1);
				else if (idx == 1)
					DFS(res - num[input], input+1);
				else if (idx == 2)
					DFS(res * num[input], input+1);
				else if (idx == 3)
					DFS(res / num[input], input+1);
				op[idx]++;
			}
		}
	}
}

int		main()
{
	int idx;

	scanf("%d", &N);
	
	idx = -1;
	while (++idx < N)
		scanf("%d", &num[idx]);

	idx = -1;
	while (++idx < 4)
		scanf("%d", &op[idx]);

	DFS(num[0], 1);

	printf("%d\n%d", max, min);
	return 0;
}
