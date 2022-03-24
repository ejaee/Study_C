#include <stdio.h>

int lower(int * card, int e, int number)
{
    int left=0,right=e,mid;
    int lower_bnd = -1;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (card[mid] >= number)
        {
            lower_bnd = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }
    return lower_bnd;
}

int upper(int * card, int e, int number)
{
    int left=0,right=e,mid;
    int upper_bnd=-1;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (card[mid] <= number)
        {
            upper_bnd = mid;
            left = mid + 1;
        }
        else right = mid - 1;
    }
    return upper_bnd+1 >= N ? -1: upper_bnd+1;
}

void    check(int arr[], int N){
    int min, temp;

    for(int idx = 0; idx < N-1; idx++){
        min = idx;
        for(int idx2 = idx + 1; idx2 < N; idx2++){
            if(arr[min] > arr[idx2])
                min = idx2;
		}
		temp = arr[idx];
		arr[idx] = arr[min];
		arr[min] = temp;
    }
}

int	main(){
	int N, M, card[500000] = {0}, cmp[50000] = {0};
	scanf("%d", &N);
	for(int idx = 0; idx < N; idx++)
		scanf("%d" &card[idx]);
	card[N] = 0;
	check(card, N);
	
	scanf("%d", &M);
	for(int idx = 0; idx < M; idx++)
		scanf("%d" &cmp[idx]);
	cmp[M] = 0;

	for(int idx = 0; idx < M; idx++)
		printf("%d ", upper(card, N, cmp[idx]) - lower(card, N, cmp[idx]));
	return 0;
}
