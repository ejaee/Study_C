#include <stdio.h>

void	main(){

	char *buf = "Study hard!";

	printf("%s\n", buf);			// value

	// %p : hexadecimal ad
	printf("%p\n", buf);			// value's ad
	printf("%p\n", &buf);			// buf's ad by operator '&'

}
