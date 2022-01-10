#include <unistd.h>
#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int idx;
	int tmp;

	idx = 0;
	while (idx != size - 1 || idx != size)
	{
		tmp =  tab[idx];
		tab[idx] = tab[size - 1];
		tab[size - 1]  = tmp;
		idx++;
		size--;
	}
}
/*
int main(){
	int tab[100] = {123456789};
	
	printf("뒤집기 전 : %d\n", tab);

	ft_rev_int_tab(tab);

	printf("뒤집기 후 : %d\n", tab);
	return 0;
}
