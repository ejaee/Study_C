#include <stdio.h>
#include <stdbool.h>

#define MAX 101

int graph[MAX][MAX] = {0};
int C, M, X, Y;

int queue[MAX] = {0};
int front = 0, rear = 0;

bool visited[MAX] = {0};
int cnt = 0;

int BFS(int start)
{
	int pop;
	int idx, nx, ny;

	visited[1] = true;
	queue[rear] = start;
	rear++;
	while (front < rear)
	{
		pop = queue[front];
		front++;
		idx = 0;
		while (++idx <= C)
		{
			if (!visited[idx] && graph[pop][idx] == 1)
			{
				visited[idx] = true;
				queue[rear] = idx;
				rear++;
				cnt++;
			}
		}
	}
	return (cnt);
}

int main()
{
	scanf("%d", &C);
	scanf("%d", &M);

	while (M--)
	{
		scanf("%d %d", &X, &Y);
		graph[X][Y] = 1;
		graph[Y][X] = 1;
	}

	printf("%d", BFS(1));
	return 0;
}
