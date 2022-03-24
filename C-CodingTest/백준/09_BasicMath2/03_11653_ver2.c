#include <stdio.h>
//시간초과로 틀렸다. 최대한 쉽게 생각할 것!
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

int next_prime(int nb)
{
    int idx = 0;

    idx = nb;
    if(nb <= 2)
        return(2);
    while(!prime(idx))
        idx++;
    return idx;
}

int	main()
{
	int nb = 0, idx = 0, prime = 2;
	scanf("%d", &nb);
	while(nb != 1)
	{
		if(nb % prime == 0)
		{
			printf("%d\n", prime);
			nb = nb / prime;
			
		}
		else
			prime = next_prime(prime + 1);
	}
	return 0;
}
