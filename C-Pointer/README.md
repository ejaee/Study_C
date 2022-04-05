
## 📌 Pointer
* 📖 교재 : [공동환의 열혈강의 C 포인터](https://freelec.co.kr/lecture/%EC%97%B4%ED%98%88%EA%B0%95%EC%9D%98-c-%ED%8F%AC%EC%9D%B8%ED%84%B0/)
    * 포인터 익숙해지기
    * 코드 따라하면서 내용 [정리하기](https://github.com/Ejaeda/C_lang/tree/master/Pointer)

-----

### 📌 자주 헷갈리는 개념 정리

-   문자열 상수와 배열의 차이점
    <details>
    <summary> 내용 확인 </summary>
    ```.c
    char *test = "abcdef";
    char test[] = "abcdef";
    ```

    "abcdef" 란?
    > 컴퓨터가 프로그램을 메모리에 로드할 때 읽기 전용 메모리에 로드되는 문자열 상수

    > abcdef 값을 저장하는 메모리의 주소 (문자열의 주소)

    문자열 상수 주소를 `포인터에 넣느냐` vs `배열에 넣느냐`
    
    - 포인터에 넣기
        ```.c
        char *test = "abcdef";
        ```

        문자열을 참조 할 수는 있지만 값을 바꾸지 못한다
        > 문자열이 저장된 메모리가 읽기 전용 메모리이기 때문

        > 원본을 그대로 가지온 격
        ```.c
        test[2] = 'x'; // error
        ```

    - 배열에 넣기
        ```.c
        char test[] = "abcdef";
        ```

        문자 배열을 문자열 상수 크기만큼 스택에 할당하고 내용을 동일하게 복사
        > 하나는 읽기 전용 메모리에, 하나는 스택에 각각 원본과 사본이 존재

        > 값을 변경할 수 있음
        ```.c
        test[2] = 'x';
        ```
    </details>

-----

-   문자열과 배열의 NULL
    <details>
    <summary> 내용 확인 </summary>

    ```.c
    char string[13] = "hello world!";
    
    |h|e|l|l|o| |w|o|r|l|d| ! |NULL|
     0 1 2 3 4 5 6 7 8 9 10 11  12
    ```
    
    문자열은 마지막에 반드시 NULL을 넣어야 한다
    > 메모리 크기에 NULL의 자리를 반드시 포함

    문자들을 하나씩 대입하는 경우, 마지막에 반드시 널 문자를 채워야 한다
    > 널문자가 없다면 쓰레기 값을 문자열로 출력한다

    > `string[100]` 라면 `99개`의 문자를 저장할 수 있다
    
    ```.c
    int arr[100] = {}
    ```
    
    배열은 같은 타입의 변수가 여러개 필요한 경우에 사용한다
    > `arr[100]` 라면 `100개`를 저장할 수 있다
    </details>
    
