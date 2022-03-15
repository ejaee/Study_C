#include <stdio.h>

int	main()
{
	printf("\n포인터와 배열\n");
	char	c;
	char	*cp;

	c = 'A';
	cp = &c;
	printf("%c %c %c\n\n", c, *cp, cp[0]);


	char	carr[3] = {'A', 'B', 'C'};
	char	*ap;

	ap = carr;
	printf("carr[] : %c %c %c\n", carr[0], carr[1], carr[2]);
	printf("ap[] : %c %c %c\n", ap[0], ap[1], ap[2]);
	printf("*carr : %c %c %c\n", *carr, *(carr + 1), *(carr + 2));
	printf("*ap : %c %c %c\n\n", *ap, *(ap + 1), *(ap + 2));

	/**************************************************************************/

	printf("배열과 포인터의 차이점\n\n");
	char	carrr[3] = {'D', 'E', 'F'};
	char	*cpp = carr;
	printf("sizeof p : arr = %d : %d\n", sizeof(cpp), sizeof(carrr)); // 포인터의 크기와 배열의 크기
	// carr는 상수이므로 변경될 수 없다. (carr = parr);
	// cp는 cp = NULL 이 가능하다. 아무것도 가리키지 않는다는 뜻이 된다.

	printf("\n포인터를 이용한 배열 요소 접근\n");
	char	arr[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
	char	*p;

	p = arr;
	printf("p = arr     : %c, %c, %c\n", p[0], p[1], p[2]);
	p = arr + 2;  // == &arr[2];
	printf("p = arr + 2 : %c, %c, %c\n", p[-2], p[-1], p[0]);
	p = &arr[2];
	printf("p = &arr[2] : %c, %c, %c\n", p[-2], p[-1], p[0]);

	/**************************************************************************/

	printf("\n1차원 배열을 다차원 배열처럼 사용하기\n\n");
	char arrr[4] = {'a', 'b', 'c', 'd'};
	char (*ppp)[2] = (char(*)[2])arrr;	//	배열포인터. char형처럼 쓸거야, (*p) 포인터야, 열의 갯수 [2]개씩 건너뛸거야
										// arrr은 char*형 이므로 형변환이 필요함 -> char(*)[2]arrr
										// 형변환 팁 : ppp를 지우면 char(*)[2] 형식만 남으므로 형식을 알 수 있음
	printf("arr[] : %c, %c, %c\n", arrr[0], arrr[1], arrr[2], arrr[3]);
	printf("p[][] : %c, %c, %c\n", ppp[0][0], ppp[0][1], ppp[1][0], ppp[1][1]);
	
	char arrrr[2][2] = {'a', 'b', 'c', 'd'};
	char (*pppp)[2] = arrrr; // 형 변환 필요 없다

	char arrrrr[12];
	char (*ppppp)[2][3] = (char (*)[2][3])arrrrr; // 응용 가능

	/**************************************************************************/

	printf("\n다차원 배열을 1차원 배열처럼 사용하기\n\n"); // 1차원화 시키려면 해당 자료형을 바꾸면 된다
	char aarr[2][2] = {'a', 'b', 'c', 'd'};
	char *aap = (char *)aarr;

	printf("aarr[][] : %c, %c, %c, %c\n", aarr[0][0], aarr[0][1], aarr[1][0], aarr[1][1]);
	printf("aap[]	 : %c, %c, %c, %c\n", aap[0], aap[1], aap[2], aap[3]);
	// 형 변환은 반드시 괄호!
	printf("sizeof aarr[][] : aap = %d : %d\n", sizeof(aarr), sizeof(aap));

	// 배열포인터 + 포인터 변수 연산
	char cc = 'A';
	char (*apo1)[2] = (char(*)[2])&cc;
	char (*apo2)[4] = (char(*)[4])&cc;
	char (*apo3)[3][3] = (char(*)[3][3])&cc;

	printf("char (*)[2]    : %c %c %x %x\n", **apo1, apo1[0][0], apo1, apo1+1);
	printf("char (*)[4]    : %c %c %x %x\n", **apo2, apo2[0][0], apo2, apo2+1);
	printf("char (*)[3][3] : %c %c %x %x\n", ***apo3, apo3[0][0][0], apo3, apo3+1);
	printf("[0] : %x\n[0]+1 : %x\n[0][0] : %x\n[0][1] : %x\n\n", apo3[0], apo3[0]+1, apo3[0][0], apo3[0][1]);
	
	// 주소를 저장하는 배열도 가능
	// char* arr[5](char*형 배열) 와 char (*arr)[5](배열포인터)은 다르다
	char aa = 'a', bb = 'b', ccc = 'c', dd = 'd', ee = 'e';
	char* ad[5] = {&aa, &bb, &ccc, &dd, &ee};

	printf("주소를 저장하는 배열\n\n %x\n %x\n %x\n %x\n %x\n", ad[0], ad[1], ad[2], ad[3], ad[4]);

	// 다른 자료형의 포인터 사용하기
	printf("\nint형 메모리에 char*포인터로 접근하기\n\n");
	int x[4] = {0x1011, 0x2022, 0x3033, 0x4044}; // 리틀엔디안
	char* xp = (char *)x;
	printf("char* xp = (char *)x\n");
	printf ("xp[0] : %x\nxp[1] : %x\nxp[2] : %x\nxp[3] : %x\n", xp[0], xp[1], xp[2], xp[3]);
	printf ("xp[4] : %x\nxp[5] : %x\nxp[6] : %x\nxp[7] : %x\n", xp[4], xp[5], xp[6], xp[7]);
	// 메모리가 어떤 형식이든,  포인터에 따라 정해진다

	printf("\nchar형 메모리에 int*포인터로 접근하기\n\n");
	char xx[4] = {'A', 'B', 'C', 'D'}; // 리틀엔디안
	int* xxp = (int *)xx;
	printf("int* xp = (int *)x\n");
	printf("x[0] : %x\nx[1] : %x\nx[2] : %x\nx[3] : %x\n", xx[0], xx[1], xx[2], xx[3]);
	printf("xxp[0] : %x\n", xxp[0]);
	// 메모리가 어떤 형식이든,  포인터에 따라 정해진다

	/*정리(중요)
	  메모리 이름과 상관없이
	  어떤 주소를 T* p로 가리켰을 때
	  그 메모리의 이름은 *p
	  *p은 T*의 주소이므로
	  *p은 메모리의 이름인 T형 메모리가 된다

	  p[0] p[1] ... T형 자료형식으로 일반화 할 수 있다

















}
