#include <stdio.h>
int era(int nb){
	int cnt = 0, arr[250000] = {0, };
	arr[1] = 1;
	for(int idx = 2; idx <= 2*nb; idx++){
		for(int idx2 = 2; idx*idx2 <= 2*nb; idx2++)
			arr[idx*idx2] = 1;
	}
	for(int idx = nb + 1; idx <= 2*nb; idx++)
		if(arr[idx] == 0 )cnt++;
	return (cnt);
}

int	main(){
	int try, cnt;

	while(1){
		scanf("%d", &try);
		if (try == 0)
			return 0;
		else
			cnt = era(try);
		printf("%d\n", cnt);
	}
}

