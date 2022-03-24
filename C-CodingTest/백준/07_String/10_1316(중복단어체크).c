/*중복 단어를 체크해주는 allUnique 함수 익히기*/

#include <stdio.h>
#include <string.h>

int allUnique(char *str) {
    int i, j;
    char *p = str;
    int l = strlen(str);

    for(i = 0; i < l - 1; i++) {
        for(j = i + 1; j < l; j++) {
            if(p[i] == p[j]) return 0; 
        }
    }
    return 1; 
}

int main()
{
	int		idx1 = 0, idx2 = 0, cnt = 0, tim, times = 0;
	char	str[101] = {0, };
	char	cpr[101] = {0, };
	scanf("%d", &times);

	for(tim = 0; tim < times; tim++)
	{
		idx1 = 0;
		idx2 = 0;
		scanf("%s", str);
		while(str[idx1])
		{
			if (str[idx1] != str[idx1 + 1])
			{
				cpr[idx2] = str[idx1];
				idx1++;
				idx2++;
			}
			else
				idx1++;
		}
		str[idx1] = '\0';
		cpr[idx2] = '\0';
		if (allUnique(cpr))
			cnt++;
	}
	printf("%d", cnt);
	return 0;
}
