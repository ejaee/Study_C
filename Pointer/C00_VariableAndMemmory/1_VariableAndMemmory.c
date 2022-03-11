#include <stdio.h>

int	main(){
	char c1 = 'A', c2 = 'B';
	int	n1 = 100, n2;

	//	자료형에 맞게 메모리 사이즈 할당	
	printf("\n자료형에 맞게 메모리 사이즈 할당\n");
    printf("%d\n", sizeof(c1));
    printf("%c\n", c1);

	// 변수 이름 앞에 '&'는 변수의 시작 주소
	printf("\n변수 이름 앞에 '&'는 변수의 시작 주소\n");
	printf("c1 : %c, c2: %c\n", c1, c2);
	printf("&c1 : %x, &c2 : %x\n", &c1, &c2);		//	16진수 출력 %x
	printf("&c1 : %p, &c2 : %p\n", &c1, &c2);		//	주소 출력 %p

	// 주소에 정수 연산
	// &c1 + 1의 결과는 주소다
	// 형식은 data의 성질을 말하며, 어떤 연산이 가능한지, data의 크기가 얼마인지
	printf("\n주소에 정수 연산\n");
	printf("(char *)&c1 : %p\n", &c1);
	printf("&c1 + 1 : %p\n", &c1 + 1);
	printf("&c1 + 2 : %p\n\n", &c1 + 2);

	printf("(int *)&n1 : %p\n", &n1);
	printf("&n1 + 1 : %p\n", &n1 + 1);
	printf("&n1 + 2 : %p\n", &n1 + 2);

	// 주소의 형 변환
	// 암묵적 형 변환 : 그냥 n1 = c1하면 컴파일러가 알아서 형 변환을 한다
	// 명시적 형 변환 : n1 = (int*)c1, 형식변환 연산자 ()를 통해 명시함으로써 명확히한다.
	// 즉, 연산자는 항상 같은 자료형식에서 발생한다
	// 메모리 c에 &를 붙이면 변수 c의 시작주소가 되고
	// 이때 &c의 형식은 char * 형 이다
	// 따라서 &c + 1, (int *)&c + 1 은 서로 다르다 
	printf("\n주소의 형 변환\n");
	
	printf ("c = %d, n = %d\n", c1, n1);
	n1 = (int*)c1;
	printf ("int형 n에 char형 c 저장하기 \n결과\nn = %d\n", n1);
	printf ("따라서 &c + 1, (int *)&c + 1 은 각각 %x, %x로, 서로 다르다\n", &c1 + 1, (int *)&c1 + 1);
	n1 = 100;

	// 주소와 메모리 접근
	// 1. char 형 주소
	// 메모리 접근 연산자 '*'
	// 변수앞에 &가 붙으면 주소 
	// 주소앞에 *가 붙으면 변수
	// *&c 는 char 형
	printf("\n주소와 메모리 접근\n");
	printf("c = %c, *&c = %c\n", c1, *&c1);

	// 16진수 1자리는 정확히 4bit -> 2자리는 1byte
	// 즉 0x44434241 이라면 |44|43|42|41| 메모리 할당 (빅엔디안 경우)
	printf("주소 형 변환 후 메모리 접근\n");
	n2 = 0x44434241;
	printf("n의 16진수 저장 값     : %x\n", n2); // 41 42 43 44로 출력되므로 '리틀 엔디안'방식으로 저장되었음
	printf("n의 저장 한칸 값 c     : %c, d : %d, x : %x\n", *(char*)&n2, *(char*)&n2, *(char*)&n2);
	printf("n의 저장 한칸 값 c + 1 : %c, d : %d, x : %x\n", *((char*)&n2+1), *((char*)&n2+1), *((char*)&n2+1));
	printf("n의 저장 한칸 값 c + 2 : %c, d : %d, x : %x\n", *((char*)&n2+2), *((char*)&n2+2), *((char*)&n2+2));
	printf("n의 저장 한칸 값 c + 3 : %c, d : %d, x : %x\n", *((char*)&n2+3), *((char*)&n2+3), *((char*)&n2+3));

	printf("char형을 int로 접근한다면?\n");
	printf("c의 저장 값 : %d, memory size : %d\n", c1, sizeof(c1));
	printf("c의 저장값 한칸을 int형으로 변환 출력 : %d\n", *(int*)&c1); // 쓰레기값이 나온다


	// [] 는 *와 완벽히 일치한다
	// *는 주소 앞에 사용하고 []는 주소 뒤에 사용
	// *p == p[], *(p+0) == p[0], *(P+1) == p[1]
	// int*와 *p를 헷갈리지 말자
	// int* 는 형식표현기호, *p는 주소 p의 메모리를 접근해라는 연산자
	printf("[]를 이용한 메모리 접근");

	printf("n의 저장 한칸 값 c     : %c, d : %d, x : %x\n", ((char*)&n2)[0], ((char*)&n2)[0], ((char*)&n2)[0]);
	printf("n의 저장 한칸 값 c + 1 : %c, d : %d, x : %x\n", ((char*)&n2)[1], ((char*)&n2)[1], ((char*)&n2)[1]);
	printf("n의 저장 한칸 값 c + 2 : %c, d : %d, x : %x\n", ((char*)&n2)[2], ((char*)&n2)[2], ((char*)&n2)[2]);
	printf("n의 저장 한칸 값 c + 3 : %c, d : %d, x : %x\n", ((char*)&n2)[3], ((char*)&n2)[3], ((char*)&n2)[3]);
	
}
