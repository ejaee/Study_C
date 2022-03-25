#include <stdio.h>

#define MAX 21

int N, res, min = 101;
int map[MAX][MAX] = {0};
int visit[MAX] = {0};

void    DFS(int num, int cnt)
{
	int idx, jdx, team1, team2;
	int bal;

	if (cnt == N/2)
	{
		team1 = 0;
		team2 = 0;
		idx = 0;
		while (++idx <= N)
		{
			jdx = 0;
			while (++jdx <= N)
			{
				if (visit[idx] && visit[jdx] && idx != jdx)
					team1 += map[idx][jdx];
				else if (!visit[idx] && !visit[jdx] && idx != jdx)
					team2 += map[idx][jdx];
			}
		}
		bal = team1 -team2;
		res = (bal) < 0 ? -1 * bal : bal;

		if (min > res)
			min = res;
		return ;
	}

	idx = num;
	while (++idx <= N)
	{
		visit[idx] = 1;
		DFS(idx, cnt+1);
		visit[idx] = 0;
	}

}

int main()
{
	int idx, jdx;

	scanf("%d", &N);
	idx = 0;
	while (++idx <= N)
	{
		jdx = 0;
		while (++jdx <= N)
			scanf("%d", &map[idx][jdx]);
	}

	idx = 0;
	while (++idx <= N)
	{
		visit[idx] = 1;
		DFS(idx, 1);
		visit[idx] = 0;
	}
	printf("%d", min);
}
