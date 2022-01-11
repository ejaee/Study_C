#include <stdio.h>

char *ft_strcpy(char *dest, char *src);

int	main(){
	char pst[] = "reset";
	char buf[100];

	printf("\n수정 문자열 : ");
	printf("%s\n", ft_strcpy(buf, pst));

	return 0;
}
