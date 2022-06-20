#include <stdio.h>

int cnt1, cnt0, T, N;

int fibonacci(int n) {
	if (n == 0) {
		cnt0++;
		return 0;
	} else if (n == 1) {
		cnt1++;
		return 1;
	} else {
		if (fibonacci(n-1))
		return fibonacci(n‐1) + fibonacci(n‐2);
	}
}

int main()
{
	scanf("%d", &T);

	int idx, res;

	idx = -1;
	while (++idx < T)
	{
		cnt0 = 0;
		cnt1 = 0;
		scanf("%d", &N);
		res = fibonacci(N);
		printf("%d", cnt0);
		printf("%d", cnt1);
	}
	return 0;
}
