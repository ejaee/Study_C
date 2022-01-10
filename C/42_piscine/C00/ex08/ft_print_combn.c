#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putarr(int n, char *arr)
{
	int	idx;

	idx = 0;
	while (idx < n)
	{
		ft_putchar(arr[idx] + '0');
		idx++;
	}
	if (arr[0] != 10 - n)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}
void	ft_upgrade(int n, char *arr)
{
	int	idx;
	int max;

	idx = n - 1;
	max = 9;
	while (arr[idx] == max)
	{
		idx--;
		max--;
	}
	arr[idx]++;
	while (idx < n - 1)
	{
		arr[idx + 1] = arr[idx] + 1;
		idx++;
	}
}
void	ft_print_combn(int	n)
{
	char	arr[10];
	int		idx;

	idx = 0;
	while(idx < n)
	{
		arr[idx] = idx;
		idx++;
	}
	ft_putarr(n, arr);
	while(arr[n-1] != 9)
	{
		arr[n-1]++;
		ft_putarr(n, arr);
	}
	while(arr[0] != 10 - n)
	{
		ft_upgrade(n, arr);
		ft_putarr(n, arr);
	}
}
