#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	ft_hexa(unsigned char c)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	ft_putchar(hexa[c / 16]);
	ft_putchar(hexa[c % 16]);
}
void	ft_putstr_non_printable(char *str)
{
	int idx;
	
	idx = 0;
	while (str[idx])
	{
		if (str[idx] < 32 || str[idx] > 126)
		{
			write(1, "\\", 1);
			ft_hexa(str[idx]);
		}
		else
			ft_putchar(str[idx]);
		idx++;
	}
}


