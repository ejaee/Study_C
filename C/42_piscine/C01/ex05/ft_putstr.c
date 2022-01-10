#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	ft_putstr(char *str)
{
	int idx;

	idx = 0;
	while(str[idx])
	{
		ft_putchar(str[idx]);
		idx++;
	}
}
