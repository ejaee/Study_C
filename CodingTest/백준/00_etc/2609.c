#include <stdio.h>
int gcd(int a, int b){
	int min, gcd, num = 1;
	min = a < b ? a: b;
	
	while(num <= min){
		if(a % num == 0 && b % num ==0)
			gcd = num;
		num++;
	}
	return gcd;
}



int	main(){
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d\n%d\n", gcd(a, b), (a*b) / gcd(a, b));

	return 0;
}
