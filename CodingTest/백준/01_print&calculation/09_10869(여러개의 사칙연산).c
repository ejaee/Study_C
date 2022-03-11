#include <stdio.h>
int main() {
    int A, B; // 몫과 나머지를 출력하므로 정수형 가능
    scanf("%d %d", &A, &B);
    printf("%d\n", A + B);
    printf("%d\n", A - B);
    printf("%d\n", A * B);
    printf("%d\n", A / B);
    printf("%d\n", A % B);
    return 0;
}
