#include <stdio.h>
int main(){
	int A, B, C, max;
	while(1){
	scanf("%d %d %d", &A, &B, &C);
	if(A == 0 && B == 0 && C == 0) return 0;
	if(A > B && A > C){
		if(A*A == B*B + C*C)	printf("right\n");
		else					printf("wrong\n");
	}
	else if(B > A && B > C){
		if(B*B == A*A + C*C)	printf("right\n");
		else					printf("wrong\n");
	}
	else{
		if(C*C == B*B + A*A)	printf("right\n");
		else					printf("wrong\n");
	}
	}
	return 0;
}
