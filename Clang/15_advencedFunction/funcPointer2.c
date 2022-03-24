#include <stdio.h>

int	funcIos(int param)	{ return param*2;}
int funcWindow(int param)	{return param*3;}

int	main(){
	int param;
	int (*pfunc)(int);

	scanf("%d", &param);
	if (param > 5)
		pfunc = funcIos;
	else
		pfunc= funcWindow;

	printf("%d\n", pfunc(param));
	return 0;
}
