#include <stdio.h>

struct USERDATA
{
	int		age;
	char	name[16];
	char	phone[16];
};

int main(){
    struct  USERDATA userdata = {20,	"choi e-jae", "123-1234"};

    printf("1. age : %d\n", userdata.age);
    printf("2. name : %s\n", userdata.name);
    printf("3. phone : %s\n", userdata.phone);
    return 0;
}
