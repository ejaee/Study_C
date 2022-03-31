#include <stdio.h>

int N;
int Queue[1000000];
int	front = 0, rear = 0;


int	main()
{
	scanf("%d", &N);

	int idx;

	idx = 0;
	while (++idx <= N)
	{	
		Queue[rear] = idx;
		rear++;
	}

	idx = -1;
	while (1)
	{
		if (rear == front + 1)
		{
			printf ("%d\n", Queue[front]);
			return 0;
		}
		front++;
		Queue[rear] = Queue[front];
		rear++;
		front++;
	}
}
