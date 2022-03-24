#include <stdio.h>
#include <stdbool.h>

#define MAX 20001
#define INF 10000000

int		graph[MAX][MAX] = {INF};
int		d[MAX] = {0};
bool	v[MAX] = {0};

int		V, E, start;


int main()
{
	int idx, x, y, dis;

	scanf("%d %d", &V, &E);
	scanf("%d", &start);

	idx = -1;
	while (++idx < E)
	{
		scanf("%d %d %d", &x, &y, &dis);
		graph[x][y] = dix;
		graph[y][x] = dix;
	}
}
