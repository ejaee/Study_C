#include <stdio.h>

int N, S;
int num[21] = {0};
int visit[21] = {0};
int cnt = 0;

void	DFS(int input, int res)
{
	int idx;

	if (res == S)
		cnt++;

	idx = input-1;
	while (++idx < N)
	{
		if (!visit[idx])
		{
			visit[idx] = 1;
			DFS(idx+1, res + num[idx]);
			visit[idx] = 0;
		}
	}
	return ;
}

int main()
{
	scanf("%d %d", &N, &S);

	int idx;

	idx = -1;
	while (++idx < N)
		scanf("%d", &num[idx]);

	if (!S)
		cnt -=1;
	DFS(0, 0);
	printf("%d\n", cnt);
}
