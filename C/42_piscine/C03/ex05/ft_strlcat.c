int	ft_strlen(char *arr)
{
	int cnt;

	cnt = 0;
	while (*arr)
	{
		cnt++;
		arr++;
	}
	return (cnt);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int dest_len;
	int src_len;
	int cnt;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if ((int)size <= dest_len)
		return (src_len + size);
	while (*dest)
	{
		dest++;
	}
	cnt = 0;
	while (*src && dest_len + cnt < (int)size - 1)
	{
		*dest = *src;
		dest++;
		src++;
		cnt++;
	}
	*dest = '\0';
	return (dest_len + src_len);
}

