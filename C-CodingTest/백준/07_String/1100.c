#include <stdio.h>

int	main()
{
	char	chess[8][8] = {0};

	int	row, col, cnt = 0;

	row = -1;
	while (++row < 8)
	{
		col = -1;
		while (++col < 8)
			scanf(" %c", &chess[row][col]);
	}

	row = 0;
	while (row < 8)
	{
		col = row % 2;
		while (col < 8)
		{
			if (chess[row][col] == 'F')
				cnt++;
			col += 2;
		}
		row++;
	}

	printf("%d\n", cnt);
}
