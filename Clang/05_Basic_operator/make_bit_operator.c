#include <stdio.h>

void	main(){

	int idx1 = 0x11223344, idx2 = -0x11223344;

	printf("%X\n", idx1 & 0xFFFF0000);		//11220000
	printf("%X\n", idx1 >> 16);				//1122		(2의 4승 >>)
	printf("%X\n", idx1 << 8);				//22334400	(2의 3승 <<)
	printf("%X\n", idx1 | 0x2211FFFF);		//3333FFFF
	printf("%X\n", idx1 ^ 0x2211FFFF);		//3333CCBB
	printf("%X\n", ~idx1);					//EEDDCCBB	(1의 보수)

	/*
		<비트 연산자>
		& : AND
		| : OR
		^ : XOR(서로 다르면 1, 같으면 0)
		~ : NOT
		>>, << : shift(왼쪽 이동 곱셈, 오른쪽 이동 나눗셈)

		고급언어 이면서 기계어처럼 비트단위의 정보를 다룰 때 사용
		
		32비트 자료형일 때 마치 32개의 전등을 끄고 켤 수 있는
		32개 스위치를 관리한다고 생각

		shift 후 잘려나간 자리를 0으로 채우는 것 = 패딩(Padding)
		정보가 27비트밖에 없을때 32비트 단위로 메모리를 묶으려고
		5비트를 추가하여 강제로 32비트를 되게 하는것도 패딩에 해당
	*/
	
	// 심화

	printf("음수로 전환\n");

	printf("%X\n", idx2 & 0xFFFF0000);       //EEDD0000
	printf("%X\n", idx2 >> 16);              //FFFFEEDD
    printf("%X\n", idx2 << 8);               //DDCCBC00
    printf("%X\n", idx2 | 0x2211FFFF);       //EEDDFFFF
    printf("%X\n", idx2 ^ 0x2211FFFF);       //CCCC3343
    printf("%X\n", ~idx2);					 //11223343

	/*
		음수 부호 정보를 유지하려다보니 다른 값이 발생


	*/
}
