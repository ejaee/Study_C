int	ft_strlen(char *str)
{
	int cnt;
	
	cnt = 0;
	while (*str)
	{
		cnt++;
		str++;
	}
	return (cnt);
}

int	ft_check_base(char *base)
{




void	ft_putnbr_base(int nbr, char *base)
{
	int leng;

	leng = ft_strlen(base);
	
