#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num;
	int idx;
	int len;
	char *base = "01";
	char *base10 = "0123456789";
	char stack1[1000000] = {0};
	char stack2[1000000] = {0};
	char *res2;

	num = 314;
//	scanf("%d", &num);

	
	idx = 0;
	len = 0;
	while (num >= 0)
	{
		stack1[idx++] = num % 10;
		num /= 10;
		len++;
		if (num == 0)
			break;
	}


	num = 0;
	idx = -1;
	while (++idx < len)
		num = num * 10 + base10[stack1[idx]];
printf("num10 : %d\n", num);
	idx = 0;
	len = 0;
	while (num >= 0)
	{
		stack2[idx++] = num % 2;
printf("stack[] : %d\n", num % 2);
		num /= 2;
		len++;
		if (num == 0)
			break;
	}

	res2 = malloc(sizeof(char) * (len + 1));
	idx = -1;
	while (++idx < len)
		res2[idx] = stack2[idx];
	res2[idx] = 0;
	
	idx = -1;
	while (++idx < len)
		printf("%d", res2[idx]);

	return (0);
}
