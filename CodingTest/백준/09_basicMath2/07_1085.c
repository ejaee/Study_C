#include <stdio.h>
int main()
{
	int x = 0, y = 0, w = 0, h = 0, min1 = 0, min2 = 0, min = 0;
	scanf("%d %d %d %d", &x, &y, &w, &h);

	if(x > y)
		min1 = y;
	else
		min1 = x;
	if(w-x > h-y)
		min2 = h-y;
	else
		min2 = w-x;
	if(min1 > min2)
		printf("%d", min2);
	else
		printf("%d", min1);
	return 0;
}
