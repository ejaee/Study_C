#include <stdio.h>
#include <string.h>

#define MAXSIZE 100001

typedef struct _queue
{
	int queue[MAXSIZE];
	int front;
	int rear;
}				que;

char command[10];
int num;

void	q_init(que *q)
{
	q->front = 0;
	q->rear = 0;
}

int		is_empty(que *q)
{
	if (q->front == q->rear)
		return 1;
	else
		return 0;
}

int		next_idx(int idx)
{
	if (idx == MAXSIZE-1)
		return 0;
	else
		return idx+1;
}

void	enqueue(que *q, int num)
{
	if (!next_idx(q->rear))
		return ;

	q->rear = (q->rear + 1) % MAXSIZE;
	q->queue[q->rear] = num;
}

int		dequeue(que *q)
{
	if (is_empty(q))
		return -1;
	q->front = (q ->front + 1) % MAXSIZE;
	return q->queue[q->front];
}

int		size(que *q)
{
	if (q->front < q->rear)
		return q->rear - q->front;
	return 0;
}

int		front(que *q)
{
	if (is_empty(q))
		return -1;
	return q->queue[q->front + 1];
}

int		back(que *q)
{
	if (is_empty(q))
		return -1;
	return q->queue[q->rear];
}

int main()
{
	int N;
	que q;

	q_init(&q);

	scanf("%d", &N);
	while (N--)
	{
		scanf(" %s", command);
		if (!strcmp(command, "push"))
		{
			scanf(" %d", &num);
			enqueue(&q, num);
		}

		else if (!strcmp(command, "pop"))
			printf("%d\n", dequeue(&q));

		else if (!strcmp(command, "size"))
			printf("%d\n", size(&q));

		else if (!strcmp(command, "empty"))
			printf("%d\n", is_empty(&q));

		else if (!strcmp(command, "front"))
			printf("%d\n", front(&q));

		else if (!strcmp(command, "back"))
			printf("%d\n", back(&q));
		
	}
	return 0;
}
