#include <stdio.h>
int main(){
    int arr[5] = {1, 2, 3, 4, 5};

    for (int idx = 0; idx < 5; idx++)
    {
        printf("%p : %d\n\n", arr + idx, *(arr + idx));
    }
    return 0;
}
