#include <stdio.h>
#include <stdlib.h>

int N, max = -800, res;
int A[8] = {0};
int visit[8] = {0};
int temp[8] = {0};

void	cal()
{
	int idx;

	res = 0;
	idx = -1;
	while (++idx < N-1)
		res += abs(temp[idx] - temp[idx+1]);
	if (max < res)
		max = res;
}

void	DFS(int input)
{
	int idx;

	if (input == N)
	{
		cal();
		return ;
	}

	idx = -1;
	while (++idx < N)
	{
		if (!visit[idx])
		{
			visit[idx] = 1;
			temp[input] = A[idx];
			DFS(input+1);
			visit[idx] = 0;
		}
	}
}

int main()
{
	scanf("%d", &N);

	int idx;

	idx = -1;
	while (++idx < N)
		scanf("%d", &A[idx]);

	DFS(0);
	printf("%d\n", max);
	return 0;
}
