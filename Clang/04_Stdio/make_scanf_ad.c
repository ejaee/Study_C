#include <stdio.h>

void	main(){

	int nInput = 0;

	printf("Check address\nnInput's  ad : %p\n\n", &nInput);

	printf("Input number : ");

	scanf("%d", &nInput);
//	scanf("%d", 0x16d0b770c);
// I tried that change &nInput into real hexa number
// result : F (If i play gcc, The ad's number keeps changing)

	printf("%d\n", nInput);


}
