#include <stdio.h>

int func(int a, int b)
{
	return a + b;
}

void	main()
{
	// void형 포인터는 무엇인가
	// 자료형식은 그 메모리의 성질을 표현하는 것
	//			  어떤 연산이 가능한지를 나타내는 변수의 형태
	// int n -> 정수형 연산이 가능
	// double a -> 실수형 연산이 가능

	// void 형이라는 자료형식은 존재하지 않는다
	// void는 통상 함수의 return이 없다
	//			   매개변수를 받지 않는다로 쓰였다
	// void* 형은 존재한다
	// 어떤 자료형이든 무관하게 그 주소를 보관하고자 할 때 사용!

	// 자료에 관계없이 주소를 담는다
	// 객체지향 언어는 여러 자료 형식을 특정 형식 하나로 다룰 수 있지만
	// c 언어는 위와 같은 개념이 없다
	// 위 한계를 보안하기 위해 void* 를 쓴다

	char c = 'A';
	int n = 3;

	void *vp;
	vp = &c;
	printf("%x %x\n", &c, vp);

	vp = &n;
	printf("%x %x\n", &n, vp);

	//	void *vp는 앞에 *를 붙일 수 없다
	//  *vp는 void 형식이 된다는 말인데
	//	void 형식은 없다

	// 따라서 printf("%d", *vp) 는 안된다
	// 그러면 어떻게??  >> 형식변환

	// printf("%d\n", *vp); => error
	printf("%d\n", *(int*)vp);
	vp = &c;
	printf("%c\n", *(char*)vp);


	// void형 포인터의 메모리 접근[대입]
	vp = &n;
	int *npp;
	npp = (int*)vp;
	printf("%d %d %d\n", n, *(int*)vp, *npp);

/***************************************************/

	// 함수 포인터
	// 포인터에 함수의 주소를 저장하겠다
	printf("\nmain addr : %x\n", main); // 함수의 주소도 있다
	
	// 함수의 원형 : void main(void)
	void (*fp)();		// void (*fp)(void) 함수포인터 fp 선언
	fp = main;
	printf("main addr : %x\nfp addr : %x\n", main, fp);

	// int func(int n1, int n2) 함수
	// 함수의 원형 : int func(int, int);
	// 함수의 이름 func 를 (*fp) 로만 바꿔주면 된다
	// 함수의 이름은 주소... 그러므로 주소는 int *형
	// func를 fp에 저장하고 싶다
	// fp 는 주소를 저장하므로 int*형이 되어야 한다
	int (*ffp)(int, int); // 함수포인터 fp 선언
	ffp = func;
	printf("func addr : %x\nfp addr : %x\n", func, ffp);


/***************************************************/

	// 함수 호출 규약(함수 호출할 때 약속)  by 32bit O/S
	// __cdecl
	//			함수 인자를 오른쪽에서 왼쪽으로 전달
	//			함수 스택 프레임을 호출자에서 제거

	// __stdcall
	//			함수 인자를 오른쪽에서 왼쪽으로 전달
	//			함수 스택 프레임을 피호출자에서 제거

	/*
	int add(int a, int b)			//	피호출자(callee)
	{
		return (a + b);
	}

	int main()						//	 호출자(caller)
	{
		int result = add (2, 3);
	}
	*/
	// add 함수를 사용하고 스택에서 add 인자가 제거될 때 누가 하는가
	// 에 따라 __cdecl(main이) __stdcall(add가) 이 달라진다
	// 이걸 배우는 이유 : 함수 포인터의 사용이 달라진다

	// __cdecl 규약 : 기본 함수 호출 규약 (생략 가능)

	/*
	int __stdcall add(int n1, int n2) // __stdcall을 사용하는 함수라면
	{
		return (n1 + n2);
	}

	void main()
	{
		int (__stdcall*fp)(int, int) // 명시해주어야 한다
		fp = add;
		printf("%d", fp(10, 10));
	}
	*/

/***************************************************/

	// 여러가지 포인터의 비교

	int *np;			// int 형의 주소를 저장하는 포인터
	int **npp;			// int 형의 2차 포인터. int 형의 주소의 주소를 저장하는 포인터

	int arr[3];			// 1차원 배열
	int arr[2][3];		// 2차원 배열

	int *arr[3];		// (arr[3]) 배열은 배열인데 int *형식을 저장하는 즉, int 주소를 저장하는 배열
	
	int (*arr)[3];		// (*arr) 포인터다, int형 2차원 배열의 열의 갯수가 3개인 배열의 주소를 저장하는 포인터
						// 2차원 배열의 주소를 저장하는 배열 포인터
						// int arr2[2][3]; int (*arr)[3]; arr = arr2;

	int (*arr)[2][3];	// (*arr) 포인터다, 행과 열의 갯수를 2x3 씩 건너뛰는 포인터, 3차원 int형 배열의 주소 저장하는 포인터
						// int arr3[2][2][3]; int (*arr)[2][3]; arr = arr3;

	int (*arr[2])[3];	// (*arr[2]) 배열인데 포인터를 갖는 배열, 2개의  주소를 저장하는 포인터,
						// int (*arr)[3]와 흡사. 열이 3개인 int형 2차원 배열의 주소를 저장하는 포인터가 2개
						// iarr1[2][3]; iarr2[3][3]; arr[0] = iarr1; arr[1] = iarr2;

	int *(*arr)[3];		// (*arr) 포인터다, [3]는 열의 갯수가 3인 2차원 배열 주소를 저장하는데, 자료 형식이 int* 형
						// int * 를 T라고 했을 때 T (*arr)[3]은 2차원 배열에 열의 갯수가 3인 T형 타입의 주소를 저장하는 배열 포인터
						// int (*arr)[3]와 흡사. int형 주소를 저장하는 열이 3개인 2차원 배열에 저장하는 포인터

	int *func();		// 포인터가 아니다. 함수의 선언
	int (*func)();		// (*func) 포인터다. 함수 포인터. int형을 반환하고 매개변수를 가지지 않는 함수를 저장하는 포인터
	int (*func[2])();	// (*func[2])포인터를 가지는 배열. 함수포인터가 배열로 2개를 가진다






















}
