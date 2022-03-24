#include <stdio.h>
int chess[50][50] = {0};

int check(int x, int y){
	int cnt1 = 0;
	int cnt2 = 0;
	int min;

	for(int idx = x; idx < x + 8; idx++){
		for(int idx2 = y; idx2 < y + 8; idx2++){
			if((idx+idx2) % 2 == chess[idx][idx2]) 
				cnt1++;
			if((idx+idx2 + 1) % 2 == chess[idx][idx2]) cnt2++;
		}
	}
	min = cnt1 < cnt2 ? cnt1 : cnt2;
	return min;
}

int	main(){
	int N, M, min = 64;
	char c[50][50];
	scanf("%d %d", &N, &M);

	for(int idx = 0; idx < N; idx++){
		scanf("%s", c[idx]);
		for(int idx2 = 0; idx2 < M; idx2++){
			if(c[idx][idx2] == 'B') chess[idx][idx2] = 0;
			else		chess[idx][idx2] = 1;
		}
	}
	// 8*8 시작점 경우의 수
	for(int idx = 0; idx <= N-8; idx++){
		for(int idx2 = 0; idx2 <= M-8; idx2++)
			if(min > check(idx, idx2)) min = check(idx, idx2);
	}
	printf("%d", min);
	return 0;
}
