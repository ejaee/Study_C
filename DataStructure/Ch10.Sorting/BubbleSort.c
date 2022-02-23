#include <stdio.h>

void	BubbleSort(int arr[], int n)
{
	int idx;
	int jdx;
	int temp;

	for (idx = 0; idx < n - 1; idx++)
	{
		for (jdx = 0; jdx < (n - idx) - 1; jdx++)
		{
			if (arr[jdx] > arr[jdx + 1])
			{
				temp = arr[jdx];
				arr[jdx] = arr[jdx + 1];
				arr[jdx + 1] = temp;
			}
		}
	}
}

int main()
{
	int arr[4] = {30, 20, 50, 10};
	int idx;

	BubbleSort(arr, sizeof(arr) / sizeof(int));

	for(idx = 0; idx < 4; idx++)
		printf ("%d ", arr[idx]);

	printf("\n");
	return (0);
}
