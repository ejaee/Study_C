# C02

### [ft_strcpy](#ex00)
### [ft_strncpy](#ex01)
### [ft_str_is_alpha](#ex02)
### [ft_str_is_nummeric](#ex03)
### [ft_str_is_lowercase](#ex04)
### [ft_str_is_uppercase](#ex05)
### [ft_str_is_printable](#ex06)
### [ft_strupcase](#ex07)
### [ft_strlowcase](#ex08)
### [ft_strcapitalize](#ex09)
### [ft_strstrlcpy](#ex10)
### [ft_putstr_non_printable](#ex11)
### [ft_print_momory](#ex12)

## ex00 
### char    *ft_strcpy(char *dest, char *src);
`src의 배열`을 `dest에 복사`
-   while문을 벗어나면 NULL 추가 입력
-   return (dest);
>   리터값을 주소(배열의 이름)로 전달<br>
>   src가 dest 문자열 공간보다 많다면 overflow가 발생<br>
>   보완 : ft_strncpy

## ex01 
### ft_strncpy(char *dest, char *src, unsigned int n);
`src의 배열`을 `n`만큼 `dest에 복사`
-   `n이 src의 길이보다 작을` 경우, dest에 NULL 문자(\0)는 `추가되지 않음` 
-   `n이 src의 길이와 같거나 클` 경우, dest에는 n까지 남은 자리를 NULL 문자(\0)로 채워짐
-   return (dest);
>   자료형이 size_t인 n의 값이 음수가 되면 버퍼오버플로우(size_t는 unsigned형으로 선언) 발생<br><br>
>   `복사할 길이(n) < src의 길이` 경우, 문자열 끝에 ‘\0’문자를 붙여주지 않기 때문에 위험함<br>
>   보완 : ft_strlcpy<br>
>   <br>
>   <주의점><br>
>   `unsigned int형` n과 비교하는 idx의 자료형을 맞출 것


## ex02 
### int     ft_str_is_alpha(char *str);
`ASCII` 대문자 알파벳 = 65 ~ 90<br>
`ASCII` 소문자 알파벳 = 97 ~ 122<br>

## ex03 
### int     ft_str_is_nummeric(char *str);
`ASCII` 숫자 = 48 ~ 57<br>

## ex04 
### int     ft_str_is_lowercase(char *str);
`ASCII` 소문자 알파벳 = 97 ~ 122<br>

## ex05 
### int     ft_str_is_uppercase(char *str);
`ASCII` 대문자 알파벳 = 65 ~ 90<br>

## ex06 
### int     ft_str_is_printable(char *str);
`ASCII` 출력 가능한 문자 = 32 ~ 126<br>
-   공백 문자 1개 ( 32 )
-   숫자 10개 ( 48 ~ 57 )
-   영문 알파벳 대+소 문자 52개 ( 65 ~ 90, 97 ~ 122 )
-   특수 문자 32개 ( 33 ~ 47, 58 ~ 64, 91 ~ 96, 123 ~ 126 )

## ex07 
### char    *ft_strupcase(char  *str);
대문자 = 소문자 + 32

## ex08 
### char    *ft_strlowercase(char  *str);
소문자 = 대문자 - 32

## ex09 
### char    *ft_strcapitalize(char  *str);
문자열에서 단어를 식별하고 단어의 첫 알파벳을 대문자로, 이외 알파벳을 소문자로 변경<br>
단어 = (대, 소)문자, 숫자<br>
특수문자는 단어에 포함되지 않음<br>

```.c
while(str)                                // 문자열 전체 반복문
{
    if(문자가 대문자 or 소문자 or 숫자)         // 단어 첫 진입
    {
        if(소문자일 경우)                    // 첫 단어는 대문자
            대문자로 변경;
        str++;
        while(문자가 대문자 or 소문자 or 숫자)  // 단어 끝까지 확인 반복문
        {
            if(대문자일 경우)                // 두번째부터는 소문자
                소문자로 변경;
            str++;
        }                                // 단어 종료
    }
    str++;                               // 단어를 찾을때 까지 더하기
}
```

## ex10 
### unsigned int ft_strlcpy(char *dest, char *src, unsigned int  size);
`src의 배열`을 `size - 1`만큼 `dest에 복사` + `dest 배열 끝에 NULL('\0') 하나 입력`<br>
strncpy에서 src의 길이가 size보다 클 때 NULL(\0)이 빠질 수 있는 약점을 보완한 함수
-   `n이 src의 길이보다 작을` 경우, dest에 NULL 문자(\0)를 `무조건 하나 붙인다`
-   `n이 src의 길이와 같거나 클` 경우, dest의 끝에 NULL 문자(\0)를 `하나만 붙인다`
-   return (src의 길이);
>   unsigned int형인 size는 음수가 될 경우 버퍼오버플로우 발생<br>
>   이에따라 size가 0일 때 size - 1만큼 복사하는 과정에서 예외처리 필요
```.c
if(size == 0)  return (src_len); 으로 먼저 예외처리 후

while (idx < size - 1)
{
    dest[idx] = src[idx];
    idx++;
}
```
>   strncpy와 다르게 무조건 NULL은 '하나' 붙인다<br>
>   src의 길이가 size 보다 크면 while(idx < size - 1)는 src를 반복하던 도중 나온다<br><br>
>   src이 길이가 size 보다 작으면 src가 끝나도 복사를 더해야한다... 
>>  추가 조건 :  while ( src[idx] && idx < size - 1 )<br>
>
>   <주의점><br>
>   `unsigned int형` n과 비교하는 idx의 자료형을 맞출 것

## ex11
### ft_putstr_non_printable(char  *Str)
ex06에서 배운 출력 가능한 문자 범위 (32 ~ 126)를 활요하여 구별<br>
16진수로 출력하는 방법
-   16진수 (0123456789abcdef)를 담은 배열을 만든다
>   hexa = "0123456789abcdef";
-   출력 불가한 숫자를 매개변수로 받아 16으로 나눈 몫과 나머지를 활용하여 출력한다
>   putchar(hexa[c/16]);<br>
>   putchar(hexa[c%16]);
>>  ASCII 코드는 256개(0 ~ 256)이므로 c/16과 c%16 한번씩 만으로 16진수로 변환 가능
>>  <br>
>>  <br>
>>  <주의할 점>
>>  16진수로 변환하는 함수의 매개변수는 ASCII 코드의 숫자를 받으므로<br>
>>  char를 사용할 시 범위에 문제가 발생함<br>
>>  unsigned char 자료형을 사용할 것!
