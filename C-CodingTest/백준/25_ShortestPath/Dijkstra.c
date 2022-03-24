#include <stdio.h>
#include <stdbool.h>

#define INF 10000000

int num = 6;

int graph[6][6] = {	{0, 2, 5, 1, INF, INF},
					{2, 0, 3, 2, INF, INF},
					{5, 3, 0, 3, 1, 5},
					{1, 2, 3, 0, 1, INF},
					{INF, INF, 1, 1, 0, 2},
					{INF, INF, 5, INF, 2, 0}};

bool	v[6];
int		d[6];

int		getSmallIndex()
{
	int idx, res;
	int min = INF;

	idx = -1;
	res = 0;
	while (++idx < 6)
	{
		if (d[idx] < min && !v[idx])
		{
			min = d[idx];
			res = idx;
		}

	}
	return (res);
}

void	Dijstra(int start)
{
	int idx, jdx, cur;

	idx = -1;
	while (++idx < 6)
		d[idx] = graph[start][idx];
	v[start] = true;

	idx = -1;
	while (++idx < 4)
	{
		cur = getSmallIndex();
		v[cur] = true;
		jdx = -1;
		while (++jdx < 6)
		{
			if (!v[jdx])
			{
				if (d[cur] + graph[cur][jdx] < d[jdx])
					d[jdx] = d[cur] + graph[cur][jdx];
			}
		}
	}
}

int main()
{
	Dijstra(0);
	for (int idx = 0; idx < 6; idx++)
		printf("%d ", d[idx]);
	return 0;
}
