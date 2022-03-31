#include <stdio.h>

int main()
{
	int arr[] = {3, 5, 2, 1, 6};
	int idx, jdx, temp;

	idx = -1;
	while (++idx < sizeof(arr)/sizeof(int))
	{
		jdx = -1;
		while (++jdx < idx)
		{
			if (arr[jdx] > arr[idx])
			{
				temp = arr[jdx];
				arr[jdx] = arr[idx];
				arr[idx] = temp;
			}
		}
	}
	idx = -1;
	while (++idx < 5)
		printf("%d ", arr[idx]);
}
