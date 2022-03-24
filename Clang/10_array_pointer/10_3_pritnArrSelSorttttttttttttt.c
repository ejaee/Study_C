#include <stdio.h>
int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	main(){
	char *arr;
	char *temp;
	int idx = 0;
	int jdx;

	arr = "ekdjd";
	while (arr[idx]){
		jdx = idx + 1;
		while (arr[jdx]){
			if(ft_strcmp(arr + idx, arr + jdx) > 0){
				*temp = arr[idx];
				arr[idx] = arr[jdx];
				arr[jdx] = *temp;
			}
			jdx++;
		}
		printf("%c\n", *(arr + idx));
		idx++;
	}
	return 0;
}
