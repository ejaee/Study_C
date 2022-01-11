
#include <unistd.h>

char	*ft_strlowcase(char *str)
{
	int idx;

	idx = 0;
	while(str[idx])
	{
		if (str[idx] >= 'A' && str[idx] <= 'Z')
			str[idx] += 32;
		idx++;
	}
	return (str);
}

