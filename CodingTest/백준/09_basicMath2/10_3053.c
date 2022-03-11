#include <stdio.h>
#include <math.h>
#define	PI 3.14159265358979

int	main(){
	int R;
	scanf("%d", &R);
	printf("%.6f\n", pow(R,2) * PI);
	printf("%.6f\n", pow(R,2) * 2);
	return 0;
}
