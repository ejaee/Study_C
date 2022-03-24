#include <stdio.h>

void	main(){
	char ch;
	
	ch = getchar();		// buffer empty
	putchar(ch);
	ch = getchar();
	putchar(ch);
	ch = getchar();
	putchar(ch);
	ch = getchar();
	putchar(ch);

	// if program is restarted, buffer reset
}
