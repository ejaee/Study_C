#include <stdio.h>

int check(int x){
	int rst = 0, idx = x;
	
	while(idx--){
			if(idx==2)
				rst += 28;
			else if(idx==1||idx==3||idx==5||idx==7||idx==8||idx==10||idx==12)
				rst += 31;
			else if(idx==4||idx==6||idx==9||idx==11)
				rst += 30;
	}
	return rst;
}

int	main(){
	int x, y, sum = 0;
	scanf("%d %d", &x, &y);

	sum = check(x) + y;

	if(sum % 7 == 1) printf("MON\n");
	else if(sum % 7 == 2) printf("TUE\n");
	else if(sum % 7 == 3) printf("WED\n");
	else if(sum % 7 == 4) printf("THU\n");
	else if(sum % 7 == 5) printf("FRI\n");
	else if(sum % 7 == 6) printf("SAT\n");
	else printf("SUN\n");
	return 0;
}
