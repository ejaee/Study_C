int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int cnt;

	cnt = 0;
	while (*s1 && *s2 && *s1 == *s2)
	{
		cnt++;
		if (n == cnt)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
