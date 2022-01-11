#include <unistd.h>

char	*ft_strupcase(char *str)
{
	int idx;

	idx = 0;
	while(str[idx])
	{
		if (str[idx] >= 'a' && str[idx] <= 'z')
			str[idx] -= 32;
		idx++;
	}
	return (str);
}

