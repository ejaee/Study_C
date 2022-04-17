#include <stdio.h>

int	main(){
	int	arr[5] = {1, 2, 3, 4, 5};
	char arr2[5] = {65, 66, 67, 68, 69};

	printf("size = 4\n");
	for (int idx = 0; idx < 5; idx++)
	{
		printf("%p : %d\n\n", arr + idx, arr[idx]);
	}
	printf("size = 1\n && print d\n");
	for (int jdx = 0; jdx < 5; jdx++)
	{
		printf("%p : %d\n\n", arr2 + jdx, arr2[jdx]);
	}
	printf("size = 1\n && print c\n");
	for (int jdx = 0; jdx < 5; jdx++)
	{
		printf("%p : %c\n\n", arr2 + jdx, arr2[jdx]);
	}
	return 0;

	/*
	char, int형 모두 자연수를 저장할 수 있다
	int형은 sizeof 4로, 숫자를 저장한다
	char형은 sizeof 1로, 숫자를 저장하면 
		1.	ascii 숫자를 저장 65 -> 'A'
		2.	ascii 숫자 자체를  %d로 출력할 수 있다
	
		char형에 저장된 숫자는 아스키 숫자가 우선되나 숫자 자체를 출력할 수 있다
	*/
}
