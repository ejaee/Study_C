#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char arr[20000][50] = {0};

void	merge(int arr[], int left, int mid, int right)
{
	int fdx = left;
	int rdx = mid + 1;
	int i;

	int *sortArr = malloc(sizeof(int) * (right+1));
	int sdx = left;

	while (fdx <= mid && rdx <= right)
	{
		if (arr[fdx] <= arr[rdx])
			sortArr[sdx] = arr[fdx++];
		else
			sortArr[sdx] = arr[rdx++];
		sdx++;
	}

	if (fdx > mid)
	{
		for (i = rdx; i <= right; i++, sdx++)
			sortArr[sdx] = arr[i];
	}
	else
	{
		for (i = fdx; i <= mid; i++, sdx++)
			sortArr[sdx] = arr[i];
	}

	for (i = fdx; i <= right; i++)
		arr[i] = sortArr[i];

	free(sortArr);
}

void	merge_sort(int arr[], left, int right)
{
	int	mid;

	if (left < right)
	{
		mid = (left + right) / 2;

		merge_sort(arr, left, mid);
		merge_sort(arr, mid + 1, right);

		merge(arr, left, mid, right);
	}
}

int	main()
{
	int N, idx, jdx;

	scanf("%d", &N);
	idx = -1;
	while (++idx < N)
		scanf("%s", arr[idx]);

	merge_sort(arr, 0, N - 1);

	idx = -1;
	while (++idx < N)
		printf("%s\n", arr[idx]);
		
}
