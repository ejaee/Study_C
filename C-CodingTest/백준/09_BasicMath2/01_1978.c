#include <stdio.h>

int check_prime(int c)
{
	int idx = 2;
	
	if(c <= 1)
		return 0;
	
	while (c % idx != 0)
		idx++;
	if(idx == c)
		return 1;
	else
		return 0;
}

int	main()
{
	int nb = 0, cnt =0,  times = 0;

	scanf("%d", &times);
	for(int idx = 0; idx < times; idx++)
	{
		scanf("%d", &nb);
		if(check_prime(nb))
			cnt++;
	}
	printf("%d", cnt);
	return 0;
}
