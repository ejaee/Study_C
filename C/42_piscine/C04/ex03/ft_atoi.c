int	ft_atoi(char *str)
{
	int sign;
	int rtn;

	sign = 1;
	rtn = 0;
	while (*str && ((*str >= 9 && *str <= 13) || *str == 32))
		str++;
	while (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		rtn = rtn * 10 + (*str - '0');
		str++;
	}
	return (sign * rtn);
}
