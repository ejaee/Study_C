#include <stdio.h>
#include <math.h>
int	main(){
	int T, d;
	long long x, y, sq;
	scanf("%d", &T);
	while(T--){
		scanf("%lld %lld", &x, &y);
		d = y - x;
		sq = sqrt(d);
		if(d == sq * sq) 
			printf("%d\n", sq*2 -1);
		else if(sq * sq < d && d <= sq * sq + sq) 
			printf("%d\n", sq*2);
		else if(sq * sq + sq < d && d < (sq + 1)*(sq + 1))
			printf("%d\n", sq*2 + 1);
	}
	return 0;
}
