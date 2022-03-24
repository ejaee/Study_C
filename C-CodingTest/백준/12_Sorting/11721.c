#include <stdio.h>
#include <string.h>

int	main()
{
	char arr[100] = {0, };
	scanf("%s", arr);

	printf("%c", arr[0]);
	for(int idx = 1; idx < strlen(arr); idx++)
	{
		if (idx % 10 == 0)
			printf("\n");
		printf("%c", arr[idx]);
	}
	return 0;
}
