#include <stdio.h>

void	main(){

	int time;
	scanf("%d", &time);

	printf("%02d :%02d :%02d\n", time/3600, (time%3600)/60, (time%3600)%60);

}
