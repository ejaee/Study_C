#include <stdio.h>
int prime(int nb)
{
	int idx = 2;
	if(nb <= 2)
		return 0;
	while(idx <= nb / idx)
	{
		if(nb % idx == 0)
			return 0;
		idx++;
	}
	return(1);
}

int	next_prime(int nb)
{
	int	idx;

	idx = nb;
	if(nb <= 2)
		return(2);
	while(!prime(idx))
		idx++;
	return idx;
}

int	main()
{
	int M = 0, N = 0, idx = 0, nb = 0, sum = 0;
	scanf("%d", &M);
	scanf("%d", &N);
	nb = M;
	while(nb <= N)
	{
		nb = next_prime(nb);
		if (nb <=  N)
			sum += nb;
		nb++;
	}
	if(sum != 0)
	{
		printf("%d\n", sum);
		printf("%d\n", next_prime(M));
		return 0;
	}
	printf("-1\n");
	return 0;
}
