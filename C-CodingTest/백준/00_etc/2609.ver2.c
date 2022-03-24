#include <stdio.h>
int gcd(int a, int b){
	if(b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int	main(){
	int a, b, tmp;

	scanf("%d %d", &a, &b);
	
	if(a < b){
		tmp = b;
		b = a;
		a = tmp;
	}

	printf("%d\n%d\n", gcd(a,b), (a*b) / gcd(a,b));

	return 0;
}
