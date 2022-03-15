#include <stdio.h>
#include <string.h>

char word[20000][50];
int cnt;

void	sort_size()
{
	int idx, jdx;
	char *temp[cnt];

	idx = 1;
	while (*word[idx])
	{
		jdx = idx - 1;
		while (*word[jdx])
		{
			if (strlen(word[jdx]) > strlen(word[idx]))
			{
				*temp = word[idx];
				word[idx] = word[jdx];
				word[jdx] = *temp;
			}
			jdx++;
		}
		idx++;
	}
}

int	main()
{
	int idx;
	int try;

	idx = 0;
	scanf("%d", &cnt);
	try = cnt;
	while (try--)
	{
		scanf("%s", word[idx]);
		idx++;
	}

//	idx = 0;
//	while (*word[idx])
//		printf("%s\n", word[idx++]);

	sort_size();


	idx = 0;
	while (*word[idx])
		printf("%s\n", word[idx++]);

	return 0;
}
