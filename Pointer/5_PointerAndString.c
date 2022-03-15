#include <stdio.h>

void main()
{
	printf("포인터로 다루는 문자열과 배열로 다루는 문자열의 차이\n\n");
	// 문자열이란 '\0'를 포함한 연속한 문자들의 집합
	// " "를 사용 (문자는 ' ')
	char *cp = "ABCD";
	// ABCD를 cp에 저장한다는 것이 아니다
	// char형 포인터 변수 cp가 문자열 ABCD를 저장하는 메모리 시작 주소를 가리켜라

	// "ABCD"를  문자열로 보지말자
	// "ABCD"는 이 문자열이 시작하는 주소라고 생각하자
	// 그 시작 주소를 cp에 보관하는 것이다

	// 포인터는 문자열을 가리키는 것
	// 배열은 문자열을 보관하는 것
	char carr[10] = "ABCD";	//	== char carr[10] = {'A', 'B', 'C', 'D', '\n'}; 이후는 0으로 초기화
	// 배열과 문자열 모두 연속한 문자들의 집합이기 때문에 문자열을 배열로 표현 가능

	printf("*p : %c\narr[] : %c\n", cp[0], carr[0]);
	// cp[0] = 'Z' // 수정불가. char *cp = "ABCD" 에서 "ABCD"는 문자열 상수 리터럴이다
	// 문자열 상수는 변경할 수 없다
	carr[0] = 'Z'; // 수정가능.

	cp = carr;
	// carr = cp   // 수정불가
	printf("수정 후\n*p : %c\narr[] : %c\n", cp[0], carr[0]);

	/*************************************************************/

	// 포인터로 문자열 다루기
	char *str = "ABCD";		//	문자열 ABCD이 시작주소

	printf("str     : %s\n", str);
	printf("\"ABCD\"  : %s\n", "ABCD");
	printf("str + 1 : %s\n", str+1);
	printf("str + 2 : %s\n", str+2);
	printf("str + 3 : %s\n\n", str+3);

	char strr[] = "ABCD";
	puts(strr);	//puts 주소주면 문자열 출력
	puts(&strr[1]);
	puts(&strr[2]);
	puts(strr+3);

	/*************************************************************/

	// 문자 코드 : 각 문자에 대응하는 숫자 정의
	// ASCII코드 문자(1byte) ... 유니코드 문자(2byte)

	char c = 'A';		// ASCII
	wchar_t wc = L'A'; // UNICODE

	printf("\n\nASCII : %c\n", c);
	wprintf(L"UNICODE : %c\n", wc);

	printf("sizeof ASCII : %d\n", sizeof(c));		//1byte
	printf("sizeof UNICODE : %d\n", sizeof(wc));	//2byte

	// 문자열 함수 참고
	/*
	   printf == wprintf

	   strcpy(s, "String) == wcscpy(ws, L"String")

	   strcat(s, "+String") == wcscat(ws, L"+Sting")

	   strlen(s) == wcslen(ws)

	*/
}

