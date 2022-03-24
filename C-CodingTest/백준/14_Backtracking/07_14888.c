#include <stdio.h>

int num[11];
int oper[4];
int min;
int max;

void	DFS(int count_oper)
{
	if (oper[0])
	{
		'+'
		oper[0] -= -1;
		count_oper--;
		DFS(count_oper--);
	}
	else if (oper[1])
	{
		'-'
		oper[1] -= -1;
		count_oper--;
		DFS(count_oper--);
	}
	if (oper[2])
	{
		'*'
		oper[2] -= -1;
		count_oper--;
		DFS(count_oper--);
	}
	if (oper[3])
	{
		'/'
		oper[3] -= -1;
		count_oper--;
		DFS(count_oper--);
	}
}

int main()
{
	int cnt;
	int idx;
	int nb;
	int count_oper;

	scanf("%d", &cnt);
	idx = 0;
	while (cnt--)
	{
		scanf("%d", &nb);
		num[idx] = nb;
		idx++;
	}
	cnt = 4;
	idx = 0;
	count = 0;
	while (cnt--)
	{
		scanf("%d", &nb);
		oper[idx] = nb;
		if (nb ==1)
			count_oper++;
		idx++;
	}

	DFS(count_oper);

}
