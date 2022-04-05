#include <stdio.h>
#include <stdlib.h>

int	ft_count(char *str)
{
	int	cnt;

	cnt = 0;
	while (*str)
	{
		while (*str &&*str == ',')
			str++;
		if (!*str)
			break;
		cnt++;
		while (*str && *str != ',')
			str++;
	}
	return (cnt);
}

void	ft_strncpy(char *dest, char *src, int size)
{
	int idx;

	idx = -1;
	while (++idx < size)
		*dest++ = *src++;
	*dest = 0;
}

char **ft_split(char *str, char *c)
{
	int	idx;
	int cnt_word;
	char **dest;
	char *from;

	cnt_word = ft_count(str);
printf("word : %d\n", cnt_word);
	dest = (char **)malloc(sizeof(char *) * (cnt_word + 1));
	if (!dest)
		return (0);
	idx = -1;
	while (++idx < cnt_word)
	{
		while (*str == ',')
			str++;
		if (!*str)
			return (0);
		from = str;
		while (*str != ',')
			str++;
		if (!*str)
			return (0);
		dest[idx] = malloc(sizeof(char) * (str - from + 1));
		ft_strncpy(dest[idx], from, str - from);
	}
	dest[idx] = 0;
	return dest;
}

int	main()
{
	char **res;
	char arr[101] = {0};
	int	idx;

	scanf("%s", arr);

	res = ft_split(arr, ",");
	idx = -1;
	while (res[++idx]) //자연수이므로 0이 들어올 수 없다
		printf("%s\n", res[idx]);
}
