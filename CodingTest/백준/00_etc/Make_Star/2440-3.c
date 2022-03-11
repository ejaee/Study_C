#include <stdio.h>

void	make(int s){
	if(s == 0) return;
	int cnt = s;
	while(cnt--){
		printf("*");
	}
	printf("\n");
	return(make(s-1));
}

int	main(){
	int s;
	scanf("%d", &s);

	make(s);
}
