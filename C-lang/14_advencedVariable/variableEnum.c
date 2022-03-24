#include <stdio.h>

enum ACTION	{MOVE, JUMP, ATTACK};
typedef		enum COLOR	{RED = 100, GREEN, BLUE} COLOR;

int	main(){
	enum ACTION action = JUMP;
	COLOR	color = BLUE;

	printf("action = %d, color = %d\n", action, color);
	return 0;
}
