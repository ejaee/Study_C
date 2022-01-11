char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	idx;

	idx = 0;
	while (src[idx] && idx < n)
	{
		dest[idx] = src[idx];
		idx++;
	}

	while (idx < n)
	{
		dest[idx] = 0;
		idx++;
	}
	return (dest);
}

