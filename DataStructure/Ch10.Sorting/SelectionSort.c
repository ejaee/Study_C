#include <stdio.h>

void    SelectionSort(int arr[], int n)
{
    int idx;
    int jdx;
	int min;
    int temp;

    for (idx = 0; idx < n; idx++)
    {
		min = idx;

        for (jdx = idx + 1; jdx < n; jdx++)	// 최솟값 탐색
        {
            if (arr[jdx] < arr[min])
				min = jdx;
        }
            temp = arr[idx];
            arr[idx] = arr[min];
            arr[min] = temp;
    }
}

int main()
{
    int arr[4] = {30, 20, 50, 10};
    int idx;

    SelectionSort(arr, sizeof(arr) / sizeof(int));

    for(idx = 0; idx < 4; idx++)
        printf ("%d ", arr[idx]);

    printf("\n");
    return (0);
}
