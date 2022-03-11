#include <stdio.h>
/*쉽게 생각할건 쉽게 생각하자
  오히려 함수가 많아지니까 타임아웃에 걸린다
*/
int main()
{
	int nb, idx;
	scanf("%d", &nb);

	for(idx = 2; idx <=nb; idx++)
	{
		while(nb % idx == 0)
		{
			printf("%d\n", idx);
			nb /= idx;
		}
	}

	return 0;
}
