#include <stdio.h>

struct	USERDATA
{
	int		age;
	char	name[16];
	char	phone[16];
};

int	main(){
	struct	USERDATA userdata = {0};
	userdata.age = 20;
	sprintf(userdata.name, "%s", "choi e-jae");
	sprintf(userdata.phone, "%s", "123-1234");

	printf("1. age : %d\n", userdata.age);
	printf("2. name : %s\n", userdata.name);
	printf("3. phone : %s\n", userdata.phone);
	return 0;

	/*
		3 ~ 8행에서 구조체는 변수 선언이 아니다

		자료형을 만든 것이므로 11행에서 처럼 변수선언을 해줘야 한다
	 */
}
