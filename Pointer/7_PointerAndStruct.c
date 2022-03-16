#include <stdio.h>

typedef struct _st
{
	int x;
	int y;
} st;


int	main()
{
	// 구조체 주소 저장하기	
	st s1 = {10, 10};
	st *sp = &s1;

	printf("s1.x : %d\ns1.y : %d\n", s1.x, s1.y);
	printf("(&s1)->x : %d\n(&s1)->y : %d\n", (&s1)->x, (&s1)->y);
	printf("sp->x : %d\nsp->y : %d\n", sp->x, sp->y);
	printf("(*sp).x : %d\n(*sp).y : %d\n", (*sp).x, (*sp).y);

	st arr[5] = {1,1,2,2,3,3,4,4,5,5};
	printf("\narr   : %d %d\n", arr->x, arr->y);
	printf("*arr  : %d %d\n", (*arr).x, (*arr).y);
	printf("arr+1 : %d %d\n\n", (arr+1)->x, (arr+1)->y);

	st *arrp = arr;
	printf("arrp     : %d %d\n", arrp->x, arrp->y);
	printf("arrp[0]  : %d %d\n", arrp[0].x, arrp[0].y);
	printf("arrp[1]  : %d %d\n", arrp[1].x, arrp[1].y);
	printf("arrp+1   : %d %d\n\n", (arrp+1)->x, (arrp+1)->y);
	// arr은 st* 형식
	// arrp는 st** 형식

	// 메모리 변수로 접근 ' . '
	// 메모리 주소로 접근 ' -> '
	
/****************************************************/

	// 다차원 포인터, 배열, 구조체
	// st *arrp;
	// arrp = arr // 배열의 주소 // st *arrp = arr

	st c = {1 ,1};
	st *cp = &c;
	st **cpp = &cp;

	printf("c. : %d %d\n", c.x, c.y);
	printf("(&c)-> : %d %d\n", (&c)->x, (&c)->y);
	printf("(cp)-> : %d %d\n", (cp)->x, (cp)->y);
	printf("(*cpp)-> : %d %d\n", (*cpp)->x, (*cpp)->y);
//	printf("(**cpp)-> : %d %d\n\n", (**cpp)->x, (**cpp)->y); //error
	printf("(**cpp). : %d %d\n\n", (**cpp).x, (**cpp).y);

	st **arrpp;
	arrpp = &arrp; // st **arrpp = &arrp
	printf("arr : %d %d\n", arr->x, arr->y);
	printf("arrp : %d %d\n", (arrp)->x, (arrp)->y);
	printf("arrpp : %d %d\n", (*arrpp)->x, (*arrpp)->y);

	// 2차 포인터 변수의 연산

	typedef struct _sst
	{
		char a;
		char b;
	} sst;

	sst ar = {20, 20};
	sst *arp = &ar;
	sst **arpp = &arp;

	printf("\nsizeof ar, *arp, **arpp\n");
	printf("&ar : %x\n&ar+1 : %x\n", &ar, (&ar)+1); //+2
	printf("arp : %x\narp+1 : %x\n", arp, (arp)+1); //+2
	printf("&arp : %x\n&arp+1 : %x\n", &arp, (&arp)+1); //+8
	printf("arpp : %x\narpp+1 : %x\n", arpp, (arpp)+1); //+8
	printf("&arpp : %x\n&arpp+1 : %x\n", &arpp, (&arpp)+1); //+8
	
/****************************************************/

	// 구조체 멤버로 주소 저장하기
	
	struct _string
	{
		char *str1;		// 포인터
		char str2[8];	// 배열
	};

	struct _string S1 = {"ABC", "ABC"};
	printf("\np : %s, arr : %s\n", S1.str1, S1.str2);
	printf("sizeof(S1) : %d\nsizeof(S1.str1) : %d\nsizeof(S1.str2) : %d\n", sizeof(S1), sizeof(S1.str1), sizeof(S1.str2));
	printf("p : %c\narr : %c\n", S1.str1[1], S1.str2[1]);

	struct _string * Sp = &S1;
	printf("\n%s %s\n", Sp->str1, Sp->str2);
	printf("%c %c\n", Sp->str1[1], Sp->str2[1]);
	printf("%c %c\n", *(Sp->str1+1), *(Sp->str2+1));
	printf("%x %x\n", &Sp->str1[1], &Sp->str2[1]);
	// &Sp->str1[1] = 1. Sp->str1 2. Sp->str1[1] 3. &Sp->str1[1]


/****************************************************/

	// 자신의 주소를 저장하는 구조체
	// 자기참조형 구조체

	typedef struct _node
	{
		int			data;
		struct _node *link;
	} node;

	struct _node n1, n2, n3;
	n1.data = 10;
	n1.link = &n2;
	n2.data = 20;
	n2.link = &n1;
	n3.data = 30;
	n3.link = &n3;

	// n1.link->link->data == 10;
	// n1.link = &n2
	// &n2->link = &n1
	// &n1 -> data = 10


/****************************************************/

	// 구조체의 크기를 예측하지마라

	// 구조체 안에 char , int n 이든,
	// short s, int n 이든,
	// int n1, int n2 모두 8 byte이다


	// 프로세스가 구조체를 읽고 메모리에 생성할 때
	// 고정 메모리 사이즈를 할당하고
	// cpu에 데이터를 읽어들이고 
	// cpu에서 데이터를 메모리공간에 쓴다
	struct _data1
	{
		char c;
		int n;
	};

	struct _data1 t;
	printf("%x %x\n", &t.c, &t.n);
	// &t.c가 char형 이지만 4byte 를 할당받았다
	// 비어있는 메모리를 패딩 바이트라고 한다
	// 메모리의 시작주소가 짝수에 위치하도록 결정한다
	// 컴파일러가 최적화 할때 결정한다
	// 컴파일러마다 방식이 다를 수 있다

	// 패딩 바이트를 통제하는방법
	// #pragma pack[]

	// #include <stdio.h>
	// #pragma pack(1) 하면
	// 1byte단위로 쌓을 수 있다

	// 되돌리는 방법
	// #pragma pack()
}
