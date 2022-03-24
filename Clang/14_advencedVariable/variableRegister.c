#include <stdio.h>

int	main(){
	int n = 0;
	register int i = 0;
	for (i = 0; i < 10; ++i){
		n += i;
	}

	printf("%d\n", i);
	// printf("%p\n", &i);				error!!

	return 0;
}
