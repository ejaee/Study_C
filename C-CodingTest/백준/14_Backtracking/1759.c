#include <stdio.h>
#include <string.h>

int		L, C;
char	arr[15] = {0};
int		visit[15] = {0};
char	res[15] = {0};
int		ja = 2, mo = 1;

int		checkJoMo(char c)
{
	int idx;

	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return 1;
	else
		return 2;
}

void	DFS(int input, int idx)
{
	int jdx;

	if (input == L && ja <= 0 && mo <= 0)
	{
		jdx = -1;
		while (++jdx < L)
			printf("%c", res[jdx]);
		printf("\n");
		return ;
	}

	// 결과배열  자릿수 input
	// 사용 인덱스 idx
	while (++idx < C)
	{
		if (!visit[idx])
		{
			visit[idx] = 1;
			res[input] = arr[idx];
			if (checkJoMo(arr[idx]) == 1)
				mo--;
			else if (checkJoMo(arr[idx]) == 2)
				ja--;
			DFS(input + 1, idx);
			if (checkJoMo(arr[idx]) == 1)
				mo++;
			else if (checkJoMo(arr[idx]) == 2)
				ja++;
			visit[idx] = 0;
		}
	}

}

void	ft_sort()
{
	int idx, jdx, temp;

	idx = -1;
	while (++idx < C-1)
	{
		jdx = -1;
		while (++jdx < C-1 -idx)
		{
			if (arr[jdx] > arr[jdx + 1])
			{
				temp = arr[jdx];
				arr[jdx] = arr[jdx+1];
				arr[jdx+1] = temp;
			}
		}
	}
}

int main()
{
	scanf("%d %d", &L, &C);

	int idx;

	idx = -1;
	while (++idx < C)
		scanf(" %c", &arr[idx]);

	ft_sort();

	DFS(0, -1);
	return 0;
}
