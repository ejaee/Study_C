#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int idx;
	int try;

	idx = 0;
	try = size - 1;
	while (try)
	{
		idx = 0;
		while (idx < size-1)
		{
			if (tab[idx] > tab[idx+1])
				ft_swap(&tab[idx], &tab[idx+1]);
			idx++;
		}
		try--;
	}
}

