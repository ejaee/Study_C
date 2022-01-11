#include <unistd.h>

char	ft_upper(char c)
{
	c -= 32;

	return c;
}
char	ft_lower(char c)
{
	c += 32;

	return c;
}
char	*ft_strcapitalize(char	*str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if (str[idx] >= 97 && str[idx] <= 122)
		{
			ft_upper(str[idx]);
		}

