# C01

### [ft_ft](#ex00)
### [ft_ultimate_ft](#ex01)
### [ft_swap](#ex02)
### [ft_div_mod](#ex03)
### [ft_ultimate_div_mod](#ex04)
### [ft_putstr](#ex05)
### [ft_strlen](#ex06)
### [ft_rev_int_tab](#ex07)
### [ft_sort_int_tab](#ex08)

## ex00 
### void    *ft_ft(int  *nbr);
`포인터에 값을 전달`
```.c
int*   nbr = &i;
```
-   nbr은 int*형으로, 변수 i의 주소를 저장하는 변수
-   nbr에 저장된 주소에 *를 통해 i에 저장된 값에 접근
>   *nbr = i;

## ex01 
### void	ft_ultimate_ft(int	*********nbr);
포인터의 흐름을 명확하게 이해하자
```.c
int nbr;

int* p1 = &nbr;          // 변수 nbr의 주소를 저장하는 int* 형 p1
int** p2 = p1;           // int*형 변수의 주소를 저장하기 위해서는 int**형
int******** p8 = p7      // int*x7형 변수의 주소를 저장하기 위해서는 int*x8형

//문제) 포인터의 포 포 포 포 포 포 포 포인터를 보내고 그 int에 값을 42로 주는 함수 
//     int*x9 형 9번을 보내고 그 int에 '42' 값을 주어라
//     9번 연달아 가리키는 포인터들의 행렬이 있고 
//     nbr은 최초 가리켜지는 변수를 a라 했을 때,
//     a를 바로 가리키는 포인터 p1가 있고
//     p1를 가리키는 p2 ... p8를 가리키는 nbr
//     nbr은 9번의 *를 통해 a의 값에 접근할 수 있음
//
//     따라서 (int *********nbr == a) = 42;
```

## ex02 
### void	ft_swap(int	*a, int	*b);
두개의 값을 서로 바꾸는 swap 함수<br>
임의의 변수 temp를 설정하고 이후에 전달해야할 값을 임의로 담아놓고 전달<br>
int* a는 a가 가리키는 메모리의 주소안에 저장된 `값`을 의미하므로 int형 변수에 저장 가능

## ex03 
### void	ft_div_mod(int a, int b, int *div, int *mod);
나누기 몫    -> `/`<br>
나누기 나머지 -> `%`<br>

## ex04 
### void	ft_ultimate_div_mod(int *a, int *b);
ex02와 ex03의 결합

## ex05 
### void	ft_putstr(char *str);
write 함수만을 이용하여 string을 출력<br>
-   ft_putchar를 연속으로 사용하기


## ex06 
### int	ft_strlen(char *str);
문자열 크기를 구하는 함수
> 문자열 마지막 NULL('\0')은 포함되지 않은 길이

ex05에서 ft_putchar 함수를 문자열이 끝날 때까지 while문을 돌린 것 처럼<br>
반복문을 진행하면서 카운트를 함께 해줌으로써 문자열의 길이를 측정할 수 있다


## ex07 
### void	ft_rev_int_tab(int *tab, int size);
문자열을 거꾸로 돌리기<br>
`ft_swap` 과 문자열의 특성을 이용해 while 반복문을 사용하기

## ex08 
### void	ft_sort_int_tab(int *tab, int size);
정수의 배열을 오름차순으로 정렬하기
[정렬 학습]();
