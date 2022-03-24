#include <stdio.h>

void	R_putstr(char *str)
{
	if (*str == 0)
	{
		putchar('\n');
		return;
	}
	putchar(*str);
	R_putstr(str + 1); // error : str++
	
}

void	R_putrev(char * str)
{
	if (*str == 0)
	{
		putchar('\n');
		return;
	}
	R_putrev(str+1);
	putchar(*str);
}


int	main(){
	char *str = "hello everyone";
	R_putstr(str);
	putchar('\n');
	R_putrev(str);
	return 0;
}

	/*
		문자 출력, 재귀 호출의 순서에 따라 문자열 출력 순서가 바뀐다

		재귀 호출 우선 : 스택이 소멸하면서 문자를 출력
						스택은 맨 마지막에 입력된 것을 제일 먼저 꺼낸다
	 */
