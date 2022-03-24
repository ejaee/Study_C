#include <stdio.h>

int	GetLength(char *str){
	int cnt;

	cnt = 0;
	while (str[cnt])
		cnt++;
	return (cnt);
}

int	main(){
	char *arr = "this is strlen";

	printf("arr's length is %d", GetLength(arr));
	return 0;
}
