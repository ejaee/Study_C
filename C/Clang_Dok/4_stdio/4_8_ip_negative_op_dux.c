#include <stdio.h>

void	main(){
	int idx = 0;
	scanf("%d", &idx);

	printf("decimal  : %d\n", idx);
	printf("unsigned : %u\n", idx);
	printf("hexa     : %x\n", idx);

	/*
		octal : %o
		unsigned int : %u
		hexa : %x
		double(float) : %f
			double	:	소수점 이하 15자리... f	
			float	:	소수점 이하 6자리... lf
	 */
}
