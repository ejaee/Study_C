#include <stdio.h>

struct _point
{
	int a;
	int b;
};

union _data
{
	int n1;
	int n2;
};

int	main()
{
	// 구조체는 사용자 정의 자료
	struct _point	p1 = {10, 20};

	printf("p1.a : %d\np1.b : %d\n\n", p1.a, p1.b);

	p1.a = 30;
	p1.b = 10;

	printf("p1.a : %d\np1.b : %d\n\n", p1.a, p1.b);

	// p1.a == (&p1)->a
	// 구조체에 주소로 접근하고자 할 때 ' -> '	
	printf("(&p1)->a : %d\n(&p1)->b : %d\n\n", (&p1)->a, (&p1)->b); // 연산자 우선순위 주의. () 필요
	printf("(*&p1).a : %d\n(*&p1).b : %d\n\n", (*&p1).a, (*&p1).b);

//	struct _point *n1;

//	n1->a = 20;
//	n1->b = 10;
//	printf("a : %d\nb : %d\n", n1->a, n1->b);

	// 구조체 주소의 연산

	printf("%x %x %x\n", &p1, &p1.a, &p1.b);
	printf("%x %x %x\n", &p1 + 1, &p1.a + 1, &p1.b + 1); // &p1 + 1은 'struct point *' 형만큼 ++하므로 +8

	/**********************************************************************/

	// 공용체
	// 모든 멤버들이 메모리를 공유

	union _data un = {10};

	printf("\nunion size  : %d\n", sizeof(un));	
	printf("union value : %d %d\n", un.n1, un.n2);	
	//	각각 다른 자료형을 한 메모리에 사용하고 싶을때 사용

	union _uni
	{
		int a;
		char carr[4];
	};		//	둘다 4byte
	
	union _uni un2;
	un2.a = 0x44434241;  //리틀엔디안 감안

	printf("\n16진수 : %x\n10진수 : %d\n", un2.a, un2.a);
	printf("%c %c %c %c\n", un2.carr[0], un2.carr[1], un2.carr[2], un2.carr[3]);

}
