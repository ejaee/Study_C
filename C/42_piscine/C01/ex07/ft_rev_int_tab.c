#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int idx;
	int tmp;
	int rev;

	idx = 0;
	rev = size - 1;
	while (idx < rev)
	{
		tmp =  tab[idx];
		tab[idx] = tab[rev];
		tab[rev]  = tmp;
		idx++;
		rev--;
	}
}
