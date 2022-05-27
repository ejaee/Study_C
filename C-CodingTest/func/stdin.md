## 표준입력(stdin)

scanf("%c", &c)

```c
char c1, c2, c3; 	

scanf("%c", &c1); 
scanf("%c", &c2); 
scanf("%c", &c3);	

printf("%c%c%c", c1, c2, c3);
```

- Input : abc -> output : a b c
  - 연속해서 입력해도 각각 들어가진다
- Input : a b c -> output : a b
  - b에 ' '가 들어간다
  - buf에 ' ''c''\n'가 남아있다



scanf("%s", arr)

	-	%s는 개행문자(\n), 공백문자, 탭 문자 직전까지 하나의 문자열로 인식한다
	-	"hello world"를 입력하면, 출력할 때 hello만 나온다
 -	개행문자 직전까지만 문자열로 입력을 받으므로, buffer에 개행문자(\n)가 남아있게 된다
 -	연속해서 scanf를 사용하게 되면 buf의 \n가 적용되어 그냥 넘어가버린다
 -	입력 전 buf를 비워줘야 한다

```c
scanf(" %s", arr); >> %s앞에 한칸 비운다면, \n를 white space 취급해 넘긴다
```



```c
%[*][폭(width)][한정자(modifiers)]타입(type)
```

[*]

 -	데이터를 stdin에서 받아들이지만 무시된다
   -	Ex) scanf("%*d%d", i,j) >> *d는 무시되고, 다음 %d이 i에 저장, j에는 아무것도 저장되지 않음
   -	정수 입력 1번을 무시

[폭]

- 읽어들일 최대 문자 수를 지정한다
  - Ex) scanf("%10s", str) >> 최대 10문자를 읽어와 str에 저장
  - 반드시 str에는 NULL 문자가 들어갈 수 있는 충분한 공간이 있어야 함
- [*] + [폭]
  - Ex) %10s%*s >> 문자를 10개 입력 받고 나머지 문자열은 버림

- ex

[한정자]

- 입력받는 데이터의 크기를 지정한다

----

gets(char *s)

- scanf에서 공백문자가 나오면 문자열 입력을 끊어버리는 문제를 해결하는 함수
- 개행문자('\n') 직전까지 입력된 모든 문자를 저장
- 개행문자를 떼고 '\0'을 붙여서 문장의 끝을 표시
- 보안상의 문제로 표준함수에서 제외 되었음

----

fgets(char *str, int num, FILE *stream)

- gets 함수의 보안성 문제를 해결해주는 함수
- FILE 구조체를 사용하여 파일 입출력 스트림에서 문자열을 가져오는 함수

```c
>> saved "123456789\nejaechoi\n" in tips.txt

#include <stdio.h>

int main(){
    FILE *p_file;
    char str[64];

    p_file = fopen("tips.txt", "rt");
    if (p_file != NULL){
        if (fgets(str, 64, p_file) != NULL)
            printf("%s", str);
        else
            printf("파일에서 문자열을 읽을 수 없습니다.\n");

    fclose(p_file);
    }
    return 0;
}

>> fgets() 함수는 한줄씩 읽는다
>> str에는 "123456789\n\0"이 저장된다
>> size를 64에서 6으로 바꾼다면, "12345\0"이 저장된다 ('\n' 없음)
```

매개변수

- str : 읽어들인 문자열을 저장할 배열
- num : 읽어들일 최대 문자 수 (개행문자 '\n', 마지막 '\0' 포함)
  - ex) ejae 입력 시 ejae + enter >> "ejae\n\0"로 저장되므로 4 + 2 필요
  - 개행이 나오지 않았지만 num을 초과하는 경우 다 읽지 않고 중단
- stream : 표준 입출력 받기 위해 stdin 사용



----

결론 : fgets 함수 연습하기