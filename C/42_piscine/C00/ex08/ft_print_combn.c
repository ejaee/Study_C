#include <unistd.h>

void	ft_putchar(char	c)
{
	write(1, &c, 1);
}

void	ft_print_combn(int	n)
{
	int a;
	int b;

	a = 0;
	while(a <= 10 - n)
	{
		b = a + 1;
		while(b <= 9)
		{
			ft_putchar(a + '0');
			ft_putchar(b + '0');
			if(a != 8)
				write(1, ", ", 2);
			b++;
		}
		a++;
	}
}

void	main()
{
	ft_print_combn(22);
}

