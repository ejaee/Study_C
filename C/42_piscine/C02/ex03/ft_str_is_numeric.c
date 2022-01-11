#include <unistd.h>

int	ft_str_is_numeric(char *str)
{
	int idx;

	idx = 0;
	while (str[idx])
	{
		if (str[idx] < '0' || str[idx] > '9')
			return (0);
		idx++;
	}
	return (1);
}
