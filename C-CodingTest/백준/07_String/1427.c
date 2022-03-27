#include <stdio.h>
#include <string.h>

int main()
{
	int idx, jdx, temp;
	char arr[11] = {0};

	scanf("%s", arr);

	idx = -1;
	while (++idx < strlen(arr)-1)
	{
		jdx = idx;
		while (++jdx < strlen(arr))
		{
			if (arr[idx] < arr[jdx])
			{
				temp = arr[idx];
				arr[idx] = arr[jdx];
				arr[jdx] = temp;
			}
		}
	}

	printf("%s\n", arr);
	return 0;
}
