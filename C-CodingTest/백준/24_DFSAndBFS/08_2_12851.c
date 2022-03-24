#include <stdio.h>

#define MAX 100001 

int N, K;
int check[MAX] = {0};
int result[MAX] = {0};
int cnt[MAX] = {0};

int queue[MAX] = {0};
int front = 0, rear = 0;

void	BFS()
{
	int np, pop, idx;

	queue[rear] = N;
	rear++;
	cnt[N] = 1;
	check[N] = 1;
	while (front < rear)
	{
		if (N == K)
			break;

		pop = queue[front];
		front++;

		idx = -1;
		while (++idx < 3)
		{
			if (idx == 0)
				np = pop + 1;
			else if (idx == 1)
				np = pop - 1;
			else if (idx == 2)
				np = pop * 2;

			if (np >= 0 && np < MAX)
			{
				if (!check[np])
				{
					queue[rear] = np;
					rear++;
					check[np] = 1;

					cnt[np] = cnt[pop];
					result[np] = result[pop] + 1;
				}


				else if (result[np] == result[pop] + 1)
					cnt[np] += cnt[pop];
			}
		}
	}
}

int main()
{
	scanf("%d %d", &N, &K);
	BFS();
	printf("%d\n%d", result[K], cnt[K]);
	return 0;
}
