#include <stdio.h>

struct Flags {
    unsigned int a : 1;     // a는 1비트 크기
    unsigned int b : 3;     // b는 3비트 크기
    unsigned int c : 7;     // c는 7비트 크기
};
// sizeof 연산자로 Flags 비트 필드 구조체의 크기를 구해보면 4가 나옴
// 필드의 멤버를 선언하는 자료형보다 큰 비트 수는 지정할 수 없음 a : 35;
int main()	
{
    struct Flags f1;    // 구조체 변수 선언

    f1.a = 1;      //   1: 0000 0001, 비트 1개
    f1.b = 15;     //  15: 0000 1111, 비트 4개
    f1.c = 255;    // 255: 1111 1111, 비트 8개

    printf("%u\n", f1.a);    //   1:        1, 비트 1개만 저장됨
    printf("%u\n", f1.b);    //   7:      111, 비트 3개만 저장됨
    printf("%u\n", f1.c);    // 127: 111 1111, 비트 7개만 저장됨

    return 0;
}
