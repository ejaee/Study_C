#include <unistd.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int	idx;

	idx = 0;
	while (idx < n)
	{
		dest[idx] = src[idx];
		idx++;
	}
	if (idx != n)
		while (idx < n)
		{
			dest[idx] = 0;
			idx++;
		}
	dest[idx] = 0;
	return (dest);
}

