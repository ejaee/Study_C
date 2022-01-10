#include <unistd.h>

int	ft_strlen(char *str)
{
	int cnt;
	int idx;
	
	cnt = 0;
	idx = 0;
	while (str[idx])
	{
		cnt++;
		idx++;
	}
	return cnt;
}
