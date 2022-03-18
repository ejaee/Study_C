#include <stdio.h>

#define MAX_N	1001 
int use_DFS[MAX_N] = {0};
int use_BFS[MAX_N] = {0};
int graph[MAX_N][MAX_N] = {0};
int queue[MAX_N] = {0};

void	DFS(int V, int N)
{
	int idx;

	use_DFS[V] = 1;
	printf("%d ", V);
	idx = 0;
	while (++idx <=  N)
	{
		if (graph[V][idx] && !use_DFS[idx])
			DFS(idx, N);
	}
}

void	BFS(int V, int N)
{
	int front, rear, pop, idx;
	front = rear = 0;

	use_BFS[V] = 1;
	printf("%d ", V);
	queue[0] = V;
	rear++;
	while (front < rear)
	{
		pop = queue[front];
		front++;
		idx = 0;
		while (++idx <= N)
		{
			if (graph[pop][idx] && !use_BFS[idx])
			{
				use_BFS[idx] = 1;
				printf("%d ", idx);
				queue[rear] = idx;
				rear++;
			}
		}
	}
}

int main()
{
	int N, M, V;
	int i, j;

	scanf("%d %d %d", &N, &M, &V);

	while (M--)
	{
		scanf("%d %d", &i, &j);
		graph[i][j] = 1;
		graph[j][i] = 1;
	}

	DFS(V, N);
	printf("\n");
	BFS(V, N);

	return 0;
}
