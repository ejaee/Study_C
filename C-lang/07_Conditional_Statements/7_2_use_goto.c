#include <stdio.h>

int	main(){

	char c;
	while(1){
		scanf("%c", &c);
		if(c == 'y' || c == 'Y')
			goto END;
	}

	END:
		return 0;
}
