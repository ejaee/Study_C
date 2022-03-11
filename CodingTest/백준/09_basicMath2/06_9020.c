#include <stdio.h>
void	erasto(int nb){
	int arr[10001] = {0, 1};

	for(int idx = 2; idx <= nb; idx++)
		for(int idx2 = 2; idx*idx2 < nb; idx2++)
			arr[idx*idx2] = 1;

	for(int idx = nb/2; idx >0; idx--){
		if(arr[idx] != 1&& arr[nb - idx] != 1){
			printf("%d %d\n", idx, nb - idx);
			break;
		}
	}
}

int main(){
	int try, nb;
	scanf("%d", &try);

	while(try--){
		scanf("%d", &nb);
		erasto(nb);
	}
}
	
