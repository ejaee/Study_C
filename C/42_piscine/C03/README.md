# C02

### [ft_strcmp](#ex00)
### [ft_strncmp](#ex01)
### [ft_strcat](#ex02)
### [ft_strncat](#ex03)
### [ft_strstr](#ex04)
### [ft_strlcat](#ex05)

## ex00 
### int     ft_strcmp(char *s1, char *s2);
두개의 문자열 s1와 s2를 `비교`
-   두개의 문자열 s1와 s2가 `모두 같을 경우`
>   `return (0)`; (s1 == s2)
-   두개의 문자열 s1와 s2를 `비교하다가 다른 문자가 나왔을 경우`
>   해당 문자들의 아스키 코드 값에 따라 return값이 달라짐<br>
>   -   `return (+)`; (s1 > s2)
>   -   `return (-)`; (s1 < s2)

## ex01 
### int     ft_strcmp(char *s1, char *s2, unsigned int n);
두개의 문자열 s1와 s2를 `n 크기 만큼 비교`<br>
-   매개변수 n은 unsigned int(size_t) 형 이므로 `0보다 큰 값이 와야함`<br>

n의 크기가 두 문자열의 길이 둘중 하나라도 `클 경우` 전체를 비교<br>
-   str1 : 5, str2 : 10, n = 100인 경우 `str1이 길이만큼 비교`<br>

`return` 은 strcmp와 동일 


## ex02 
### chat    *ft_strcat(char *dest, char *src);
문자열 dest 뒤에 문자열 src을 이어붙이는, `문자열 연결함수`
-   dest의 길이는 src와 합쳐져도 남을 정도로 충분히 길어야 한다
-   dest 의 문자열 끝에 있는 '\0'을 없애고 src를 붙여넣는다
-   마지막에 붙여 넣은 문자열 끝에만 '\0'를 붙인다


## ex03 
### chat    *ft_strncat(char *dest, char *src, unsigned int nb);
문자열 dest 뒤에 문자열 src 중 문자 n번째 까지 이어붙버이는 함수
-   n개의 문자만 잘라서 넣어도 합친 문자열 끝에는 '\0'를 붙인다
>   Q) while (src[idx_s] && idx_s < nb)로, src[idx_s]를 붙이는 이유 : 


## ex04   // 왜 KO일까
### char    *ft_strstr(char *str, char *to_find);
문자열 str 안에서 문자열 `to_find 를 찾는 함수`<br>
str에 to_find의 문자열과 일치하는 문자열이 있으면<br>
to_find가 시작되는 문자의 포인터(char* 타입)를 반환<br>
-   return (&str[length]);<br>
>   to_find가 시작하는 자리를 반환하는 이유 : <br>
>   -   문자열을 찾아서, 문자열을 바꾸는 경우 strstr 함수 이후에 strcpy 함수를 사용할 경우<br>
>   -   strcpy의 매개변수에 `str에서 바꿀 문자열의 위치를 전달`해야 하므로 to_find 시작 위치를 전달

일치하는 문자열을 찾지 못하면 null pointer를 반환
-   return (0);
>   찾지 못했으니까 맨 뒤에 이어 붙이니 0이라고 생각하기

>   예외처리<br>
>   to_find가 빈 문자열 ("")을 가리키고 있는 경우<br>
>   str이 가리키는 주소를 반환
>   -   `if (to_find[0] == '\0')     return (str);`

## ex05 
### unsigned int    ft_strlcat(char *dest, char *src, unsigned int size);
strlcpy와 마찬가지로 strlcat은 NULL 종료를 보장 하기위한 목적을 가진다<br>
```.c
chat    *ft_strcat(char *dest, char *src);
// 문자열 dest 뒤에 문자열 src을 이어붙이는, `문자열 연결함수`
```
size의 크기는 NULL 자리가 포함된 크기이다<br>
-   size = dest_len + src_len + 1(NULL);

dest 문자열의 길이가 size - 1이 되도록 src를 이어 붙인다<br>
-   size가 dest_len + NULL 길이보다 클 때부터 src 데이터가 들어간다.
>   때문에 size에 NULL을 위한 공간을 포함시켜야 한다 

strlcpy와 같이 strlcat는 `생성하려는 문자열의 전체 길이를 반환`(NULL 자리 미포함)  
-   size > dest_leng 경우 size - 1만큼 src를 붙이고 마지막에 NULL값을 넣어준다
>   return (src_leng + dest_leng);
-   size < dest_leng 경우 문자열을 붙이는 과정이 사라진다
>   return (src_leng + size);
```.c
*주의 사항*

while(*src && dest_len + cnt < size -1)
// 반드시 src의 값이 0인지 확인하기
```






