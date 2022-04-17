#include <stdio.h>

int res[41][2] = {0};
int zero = 0, one = 0;

int		fibo(int n)
{
	if (n == 0)
	{
		zero++;
		return (0);
	}
	else if(n == 1)
	{
		one++;
		return (1);
	}
	else
		return (fibo(n - 1) + fibo(n - 2));
}

int	main()
{
	int N, nb;
	scanf("%d", &N);

	int idx;

	idx = -1;
	while (++idx <= 40)
	{
		nb = fibo(idx);
		res[idx][0] = zero;
		res[idx][1] = one;
		zero = 0;
		one = 0;
	}
	while (N--)
	{
		scanf("%d", &nb);
		printf("%d %d\n", res[nb][0], res[nb][1]);
	}
}
