/*문자열의 갯수와 문자열의 내용을 뒤집 함수*/

#include <stdio.h>
#include <string.h>
void	change(int count, char *str)
{
	char	temp;

	for(int idx = 0; idx < count / 2 ; idx++)
	{
		temp = str[idx];
		str[idx] = str[count - idx -1];
		str[count - idx - 1] = temp;
	}
}

int	main()
{
	char	str[10000] = {0, };
	int N = 0;

	scanf("%d", &N);
	while (N)
	{
		scanf("%s", str);
		int len = strlen(str);
		change(len, str);
		printf("%s\n", str);
		N--;
	}
	return 0;
}
