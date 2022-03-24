#include <stdio.h>

int	main(){
	int N;
	scanf("%d", &N);

	if(N == 1000000){
		printf("0\n");
		return 0;
	}

	else if(N >= 100000 && N < 1000000){
		for(int M = 100000; M < N; M++){
			if(N == M + M/100000 + (M%100000)/10000 + (M%10000)/1000 + (M%1000)/100 + (M%100)/10  + M%10){
				printf("%d\n", M);
				return 0;
				}
		}
	}

	else if(N >= 10000 && N < 100000){
		for(int M = 10000; M < N; M++){
			if(N == M + M/10000 + (M%10000)/1000 + (M%1000)/100 + (M%100)/10 + M%10){
				printf("%d\n", M);
				return 0;
				}
		}
	}

	if(N >= 1000 && N < 10000){
		for(int M = 1000; M < N; M++){
			if(N == M + M/1000 + (M%1000)/100 + (M%100)/10 + M%10){
				printf("%d\n", M);
				return 0;
				}
		}
	}

	else if(N >= 100 && N < 1000){
		for(int M = 100; M < N; M++){
			if(N == M + M/100 + (M%100)/10 + M%10){
				printf("%d\n", M);
				return 0;
				}
		}
	}
	else if(N >= 10 && N < 100){
		for(int M = 10; M < N; M++){
            if(N == M + M/10 + M%10){
				printf("%d\n", M);
                return 0;
            }
		}
	}
	printf("0");

	return 0;
}
