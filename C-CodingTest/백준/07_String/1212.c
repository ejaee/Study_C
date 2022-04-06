#include <stdio.h>
#include <string.h>

int	main()
{
	char	str[333335] = {0};
	char	first[9][4] = {"", "1", "10", "11", "100", "101", "110", "111"};
	char	two[9][4] = {"000", "001", "010", "011", "100", "101", "110", "111"};
	int	len;
	int	idx;

	scanf("%s", str);
	len = strlen(str);
	if (str[0] == '0')
	{
		printf("0");
		return (0);
	}

	printf("%s", first[str[0] - '0']);

	idx = 0;
	while (++idx < len)
		printf("%s", two[str[idx] - '0']);
	return (0);
}
