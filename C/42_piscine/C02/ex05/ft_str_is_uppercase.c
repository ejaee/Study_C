#include <unistd.h>

int	ft_str_is_uppercase(char *str)
{
	int idx;

	idx = 0;
	while (str[idx])
	{
		if (str[idx] < 'A' || str[idx] > 'Z')
			return (0);
		idx++;
	}
	return (1);
}
