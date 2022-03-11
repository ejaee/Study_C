#include <stdio.h>
int main(){
	int try = 6, arr[6] = {0};
	scanf("%d %d", &arr[0], &arr[3]);
	scanf("%d %d", &arr[1], &arr[4]);
	scanf("%d %d", &arr[2], &arr[5]);
	for(int idx = 0; idx < 2; idx++){
		for(int idx2 = idx+1; idx2 <= 2; idx2++)
			if(arr[idx] == arr[idx2]){
				arr[idx] = 0;
				arr[idx2] = 0;
			}
	}
	for(int idx = 3; idx < 5; idx++){
		for(int idx2 = idx+1; idx2 <= 5; idx2++)
            if(arr[idx] == arr[idx2]){
                arr[idx] = 0;
                arr[idx2] = 0;
            }
	}

	int idx = 0;
	while(try--){
		if(arr[idx] != 0){
			printf("%d", arr[idx]);
			printf(" ");
		}
		idx++;
	}
}



