#include <stdio.h>

typedef	struct	USERNAME
{
	int		age;
	char	name[16];
}	userdata;

int	main(){
	userdata data	=	{ 20, "choi e-jae"};
	printf("%d\n", data.age);

	return 0;
}
