#include <stdio.h>

char arr[100];
int idx = 0;
void    printf_ten()
{
    int cnt = 10;
    while (cnt--)
    {
		if (idx % 10 == 0 && idx)
			printf("\n");
        printf("%c", arr[idx]);
		idx++;
    }
    if (!arr[idx])
        return ;
    printf_ten();
}

int main()
{

    scanf("%s", arr);

    printf_ten();
    return 0;
}
