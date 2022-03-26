#include <stdio.h>

#define MAX 50

int k;
int num[MAX] = {0};
int res[MAX] = {0};
int visit[MAX] = {0};

void	DFS(int index, int idx)
{
	int jdx;

	if (index == 6)
	{
		jdx = -1;
		while (++jdx < 6)
			printf("%d ", res[jdx]);
		printf("\n");
		return ;
	}

	idx--;
	while (++idx < k)
	{
		if (!visit[idx])
		{
			visit[idx] = 1;
			res[index] = num[idx];
			DFS(index+1, idx+1);
			visit[idx] = 0;
		}
	}

}

int main()
{
	int idx;

	while (1)
	{
		scanf("%d", &k);
		if (!k)
			return 0;

		idx = -1;
		while (++idx < k)
			scanf("%d", &num[idx]);

		DFS(0, 0);
		printf("\n");
	}
}
