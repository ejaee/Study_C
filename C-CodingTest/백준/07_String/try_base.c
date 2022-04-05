#include <stdio.h>

int make_ten(int num)
{
	int cnt;
	int res;

	cnt = 0;
	res = 0;
	while (num >= 0)
	{
		if (cnt == 0)
			res += num % 10;
		else
			res += num % 10  * 8 * cnt;
		num /= 10;
		cnt++;
		if (num == 0)
			break;
	}
	return (res);
}

int make_two(int num)
{
	int idx;
	int res;

	res = 0;
	idx = 0;
	while (num >= 0)
	{
		if (idx == 0)
			res += num % 2;
		else
			res += num % 2 * 10 * idx;
printf("res : %d : %d\n", idx, res);
		num /= 2;
		idx++;
		if (num == 0)
			break;
	}
	return (res);
}

int main()
{
	int num;

	scanf("%d", &num);

	num = make_ten(num);
	printf("octa -> ten : %d\n", num);
	num = make_two(num);
	printf("ten -> two : %d\n", num);
}
