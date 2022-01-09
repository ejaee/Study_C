#include <stdio.h>

int	main(){

	char* data = "Test!";

	printf("포인터 data의 주소 : [%p]\n", &data);
	printf("string을 저장하고 있는 메모리의 주소 : [%p]\n", data);	
	printf("포인터를 통해 값을 불러오기 : %c\n", *data);

	printf("offset + 1 : %c\n", *(data+1));
	printf("offset + 4 : %c\n", *(data+4));


	return 0;
}
