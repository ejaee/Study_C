#include <stdio.h>

int	main(){

	int cnt = 0;
	char ch;
	char p = ' ';

	while(1){
		scanf("%c", &ch);
		if(ch == '\n')
			break;
		else if(ch != ' '&& p == ' ')
			cnt++;
		p = ch;
	}		
	printf("count word : %d\n", cnt);

	/*
		idea
		단어의 구분 : 공백 뒤에 공백이 아닐 경우
		작동   방식 : p에 공백을 넣고 시작한 후 ch의 입력값과 비교
					이후에 ch의 값을 p에 대입하고 반복문
	*/
	return 0;
}
