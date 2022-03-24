#include <stdio.h>

int input_x, input_y;
int map[1001][1001];
int enqueue[1000001][2];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int cnt = 0;
int front = 0, rear = 0;

int BFS()
{
	int pop_x, pop_y;
	int move_x, move_y;
	int idx, jdx;

	while (front < rear)
	{
		pop_x = enqueue[front][0];
		pop_y = enqueue[front][1];
		front++;
		idx = -1;
		while (++idx < 4)
		{
			move_x = pop_x + dx[idx];
			move_y = pop_y + dy[idx];

			if (move_x >= 0 && move_y >= 0 && move_x < input_x && move_y < input_y)
			{
				if (!map[move_x][move_y])
				{	
					map[move_x][move_y] = map[pop_x][pop_y] + 1;
					enqueue[rear][0] = move_x;
					enqueue[rear][1] = move_y;
					rear++;
					cnt--;
				}
			}
		}
	}
	if (!cnt)
		return (map[pop_x][pop_y] - 1);
	return -1;
}

int	main()
{
	int	idx, jdx;

	scanf("%d %d", &input_y, &input_x);
	idx = -1;
	while (++idx < input_x)
	{
		jdx = -1;
		while (++jdx < input_y)
		{
			scanf("%d", &map[idx][jdx]);
			if (map[idx][jdx] == 0)
				cnt++;
			else if (map[idx][jdx] == 1)
			{
				enqueue[rear][0] = idx;
				enqueue[rear][1] = jdx;
				rear++;
			}
		}
	}
	printf("%d", BFS());
}
