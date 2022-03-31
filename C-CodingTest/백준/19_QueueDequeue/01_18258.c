#include <stdio.h>
#include <string.h>

int N, num, front = 0, rear = 0;
int queue[2000001] = {0};
char command[6] = {0};

int main()
{
	scanf("%d", &N);

	int idx;

	idx = -1;
	while (++idx < N)
	{
		scanf(" %s", command);
		if (!strcmp(command, "push"))
		{
			if (rear > 20000000)
				return 0;

			scanf("%d", &num);
			rear++;
			queue[rear] = num;
		}
		else if (!strcmp(command, "pop"))
		{
			if (front == rear)
			{
				printf("-1\n");
				continue ;
			}

			front++;
			printf("%d\n", queue[front]);
		}
		else if (!strcmp(command, "front"))
		{
			if (front == rear)
			{
				printf("-1\n");
				continue ;
			}
			printf("%d\n", queue[front + 1]);
		}
		else if (!strcmp(command, "back"))
		{
			if (front == rear)
			{
				printf("-1\n");
				continue ;
			}
			printf("%d\n", queue[rear]);
			
		}
		else if (!strcmp(command, "size"))
		{
			printf("%d\n", rear - front);
		}
		else if (!strcmp(command, "empty"))
		{
			if (front == rear)
				printf("1\n");
			else
				printf("0\n");
		}
	}
	return 0;
}
