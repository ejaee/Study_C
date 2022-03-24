#include <stdio.h>

struct	USERDATA
{
	int		age;
	char	name[16];
	char	phone[16];
};

int main(){
    struct  USERDATA userdata = {20, "choi e-jae", "123-1234"};
	struct	USERDATA *pdata = &userdata;

    printf("1. age : %d\n", pdata->age);
    printf("2. name : %s\n", pdata->name);
    printf("3. phone : %s\n", pdata->phone);
    return 0;
}
	/*
	   포인터를 통해 구조체의 멤버 변수에 접근할 때는 '.'이 아닌

	   '->' 연산자를 사용한다

	   '->' == '*' + '.'
	 */
