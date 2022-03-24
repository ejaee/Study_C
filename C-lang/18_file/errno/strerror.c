#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <fcntl.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(2, str++, 1);
}

int main(){

	error = E2BIG;
	ft_putstr(strerror(errno));

	return 0;
}
