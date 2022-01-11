int	ft_strlen(char *src)
{
	int idx;
	int cnt;

	idx = 0;
	cnt = 0;
	while (src[idx])
	{
		cnt++;
		idx++;
	}
	return (cnt);
}

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	idx;
	int src_len;
	idx = 0;
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	while (src[idx] && idx < (size - 1))
	{
		dest[idx] = src[idx];
		idx++;
	}

	dest[idx] = '\0';
	return (src_len);
}
