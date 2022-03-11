#include <stdio.h>
#include <math.h>
void	hanoi(int n, int from, int by, int to){
	int	idx, cnt = 0;
	if(n == 1){
		printf("%d %d\n", from, to);	
		cnt++;
	}
	else{
	hanoi(n-1, from, to, by);
	printf("%d %d\n", from, to);
	cnt++;
	hanoi(n-1, by, from, to);
	}
}

int main(){
	int n, k;
	scanf("%d", &n);
	k = pow(2,n) -1;
	printf("%d\n", k);

	hanoi(n, 1, 2, 3);
	return 0;
}
