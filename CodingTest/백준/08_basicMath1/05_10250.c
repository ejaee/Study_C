#include <stdio.h>
int main()
{
	int cnt, idx = 1, try, W, H, N;
	scanf("%d", &try);
	while(try--)
	{
		cnt = 0;
		scanf("%d %d %d", &H, &W, &N);
		while(N > H)
		{
			N -= H;
			cnt++;
		}
		printf("%d", N);
		if(cnt < 9)
			printf("0");
		printf("%d\n", cnt + 1);
	}
}

