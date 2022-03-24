#include <stdio.h>

typedef struct _tree
{
	struct _tree *left;
	struct _tree *right;
	int item;
} tree;

int main()
{
	tree *node;
	int time;
	int x, y;

	scanf("%d", &time);
	while (time)
	{
		scanf("%d %d", &x, &y);
	}
}
// c로는 못푸나...?
