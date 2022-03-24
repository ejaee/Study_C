#include <stdio.h>
int main(){
	int N, idx, try = 0;
	scanf("%d", &N);
	while(N > 0)
	{
		if(N % 5 == 0)
		{
			try += N / 5;
			printf("%d", try);
			return 0;
		}
		else
		{
			N -= 3;
			try++;
		}
		if(!N)
		{
			printf("%d", try);
			return 0;
		}
	}
	printf("-1");
	return 0;
}
