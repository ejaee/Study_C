#include <stdio.h>

struct	PERSON
{
	int		age;
	char	name[16];
};
struct	USERDATA
{
	struct PERSON person;
	char	phone[16];
};

int	main(){
	struct USERDATA userdata = {{ 20, "choi e-jae"}, "123-1234"};

	puts(userdata.person.name);
	puts(userdata.phone);

	return 0;
}
