#include <stdio.h>

int main() {
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);

    //일의자리부터 곱셈
    //나머지를 활용 123일 경우
    // 123%10 나머지 3
    // 12%10 나머지 2
    // 1%10 나머지 1

    printf("%d\n", a * (b % 10));
    printf("%d\n", a * ((b / 10) % 10));
    printf("%d\n", a * ((b / 100) % 10));
    printf("%d\n", a * b);
    return 0;
}