#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b){
    return *(int*)a > *(int*)b ? 1 : *(int*)a < *(int*)b ? -1 : 0;
}
int binary_search(int arr[], int num, int size)
{
    int front, rear, pivot;
    front = 0;
    rear = size - 1;
    while (1) {
        pivot = (front + rear) / 2;
        if (arr[pivot] == num) return 1;
        if (arr[front] == num) return 1;
        if (arr[rear] == num) return 1;

        if (arr[pivot] < num)
            front = pivot + 1;
        else 
            rear = pivot - 1;
        if (front >= rear)
            return 0;
    }
}
int main(void){
    int n;
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int m;
    scanf("%d", &m);
    int *arr2 = (int*)malloc(m * sizeof(int));

    for(int i = 0; i < m; i++){
        scanf("%d", &arr2[i]);
    }

    qsort(arr, n, sizeof(int), compare);

    for(int j = 0; j < m; j++){
        printf("%d\n", binary_search(arr, arr2[j], n));
    }
    return 0;
}
