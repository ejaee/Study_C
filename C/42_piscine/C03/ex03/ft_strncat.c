char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int idx_d;
	int idx_s;

	idx_d = 0;
	idx_s = 0;
	while (dest[idx_d])
	{
		idx_d++;
	}
	while (src[idx_s]  && idx_s < (int)nb)
	{
		dest[idx_d] = src[idx_s];
		idx_d++;
		idx_s++;
	}
	dest[idx_d] = '\0';
	return (dest);
}
