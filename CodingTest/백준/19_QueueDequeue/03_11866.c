#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	struct _node *next;
	struct _node *prev;
	int			data;
}				node;

node *head = 0;
node *tail = 0;

node *create_node(int data)
{
	node *newnode = malloc(sizeof(node));
	newnode->next = 0;
	newnode->prev = 0;
	newnode->data = data;
	return (newnode);
}

void	cycle_node(int data)
{
	node *newnode = create_node(data);
	node *temp;

	if (!head)
	{
		head = newnode;
		tail = newnode;
	}
	else
	{
		temp = tail;
		temp->next = newnode;
		newnode->prev = temp;
		tail = newnode;
	}
}

void	print_node(node *start, int N, int K)
{
	node *temp = start->prev;
	int move;
	int idx;

	idx = 0;
	printf("<");
	while (idx < N)
	{
		move = K;
		while (move--)
			temp = temp->next;
		printf(idx++ ? ", %d" : "%d" , temp->data);
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
	}
	printf(">");
}

int	main()
{
	int N, K;
	int idx;

	scanf("%d %d", &N, &K);
	idx = 0;
	while (++idx <= N)
		cycle_node(idx);	tail->next = head;
	head->prev = tail;

	print_node(head, N, K);
	return (0);
}
