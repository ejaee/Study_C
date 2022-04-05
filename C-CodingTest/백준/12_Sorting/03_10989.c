#include <stdio.h>

#define max 10001

int count[max] = {0};

int	main()
{
	int N, num;
	int idx, jdx;
	scanf("%d", &N);

	idx = -1;
	while (++idx < N)
	{
		scanf("%d", &num);
		count[num]++;
	}
	idx = -1;
	while (++idx <= max)
	{
		if (count[idx] == 0)
			continue;
		jdx = -1;
		while (++jdx < count[idx])
			printf("%d\n", idx);
	}
	return (0);
}
