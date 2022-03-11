#include <stdio.h>
int main()
{
	int nb, idx = 1, cnt = 0;
	scanf("%d", &nb);

	while(nb > idx)
	{
		nb -= idx;
			idx++;
	}
	// nb = 양수인 상태, idx = 한번 더 더해짐(이게맞지)
	// nb만큼 이동하면 원하는 숫자
	// idx가 짝수이면 분자가 커진다
	// nb 는 분자
	// 분모는 idx - nb +1
	// 홀 짝수에 따라 분자 분모의 변화가 바뀐다
	if(idx % 2 == 0)
	{
		printf("%d", nb);
		printf("/");
		printf("%d", idx - nb + 1);
		return 0;
	}
	else
		printf("%d", (idx - nb + 1));
		printf("/");
		printf("%d", nb);
		return 0;
}


