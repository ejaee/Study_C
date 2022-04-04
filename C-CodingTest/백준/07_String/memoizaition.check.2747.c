#include <stdio.h>

int memo[100] = {0}; //메모이제이션!

int fibo(int n)
{
	if (memo[n] > 0)
		return memo[n];
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	else
		return (memo[n] = fibo(n - 2) + fibo(n - 1));
}

int main()
{
	int n;

	scanf("%d", &n);
	printf("%d\n", fibo(n));
	return (0);
}
