#include <stdio.h>

void	main(){
	char	arr[128];
	
	gets(arr);

	printf("arr address number : %p\n", arr);
	printf("arr saved value : %s\n", arr);

}
