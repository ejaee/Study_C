#include <stdio.h>

void    InsertionSort(int arr[], int n)
{
    int idx;
    int jdx;
    int target;

    for (idx = 1; idx < n; idx++)
    {
        target = arr[idx];

        for (jdx = idx - 1; jdx >= 0; jdx--)
        {
            if (arr[jdx] > target)
                arr[jdx + 1] = arr[jdx];	// 비교대상 한 칸 뒤로 밀기
			else
				break;	// 삽입위치 찾았으니 종료
        }
            arr[jdx + 1] = target;
    }
}

int main()
{
    int arr[4] = {30, 20, 50, 10};
    int idx;

    InsertionSort(arr, sizeof(arr) / sizeof(int));

    for(idx = 0; idx < 4; idx++)
        printf ("%d ", arr[idx]);

    printf("\n");
    return (0);
}
