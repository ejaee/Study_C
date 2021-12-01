# :grey_exclamation: 추상 자료형: Abstract Data Type
### 자료구조에서의 추상 자료형(ADT)
-   정의

    구체적인 완성과정을 언급하지 않고, 순수하게 `기능이 무엇인지를 나열한 것`
    
-   자료형의 정의
    
    구조체를 정의하는 것 뿐만 아니라 해당 구조체를 기반으로 한 **연산**의 종류를 결정하는 것까지 포함
    (해당 구조체를 기반으로 제공할 수 있는 기능 관련 연산)

    다시말해  **자료형**의 정의에 **기능**(연산)과 관련된 내용을 명시할 수 있음

##### 예시
-   구조체 Wallet과 Wallet의 ADT
```.c
typedef struct_wallet   // 동전 및 지폐 일부만을 대상으로 표현한 지갑
{
    int coin100Num;     // 100원짜리 동전의 수
    int bill5000Num;    // 5,000원짜리 지폐의 수
} Wallet;
```
> 구조체를 기반으로 지갑을 의미하는 Wallet 이라는 자료형을 정의
```.c
int   TakeOutMoney(Wallet* pw, int coinNum, int billNum);   // 돈을 꺼내는 연산
void	PutMoney(Wallet* pw, int coinNum, int billNum);     // 돈을 넣는 연산
```
> Wallet을 기반으로 제공할 수 있는 기능 관련 연산을 명시

    자료형의 정의에 기능(연산) 관련된 내용을 명시할 수 있다
-  C언어에서는 구조체에서 필요로 하는 연산을 함수를 이용해 정의
-  위 연산이 자료형의 정의에 더해져 Wallet에 대한 자료형의 정의가 완성

-----
### ❔ Wallet의 ADT에 구조체 Wallet의 정의가 필요한가
-  main함수
```.c
int main(void){
    wallet myWallet;			// 지갑하나를 설정
    putMoney(&myWallet, 5, 10_;		// 돈을 넣는다
    ret = TakeOutMoney(&myWallet, 2, 5);// 돈을 꺼낸다
}
```
> Wallet을 기반으로 돈을 넣고 꺼내기 때문에 Wallet의 멤버의 구성을 굳이 알 필요 없다
> C언어의 파일 입출력을 공부하면서 FILE 구조체의 내부를 궁금해하지 않지않나

### ❕ 결론 필요없다

Wallet의 ADT
```.c
int   TakeOutMoney(Wallet* pw, int coinNum, int billNum)
```
-  첫 번째 인자로 전달된 주소의 지갑에서 돈을꺼낸다
-  두 번째 인자로 꺼낼 동전 수, 세 번째 인자로 꺼낼 지폐 수를 전달한다
-  꺼내고자 하는 돈의 총액이 반환되고 그만큼 돈은 차감된다

```.c
void	PutMoney(Wallet* pw, int coinNum, int billNum)
```
-  첫 번째 인자로 전달된 주소의 지갑에 돈을 넣는다
-  두 번째 인자로 넣을 동전의 수, 세 번째 인자로 넣을 지폐의 수를 전달한다
-  넣은 만큼 동전과 지폐의 수가 증가한다

-----

# :grey_exclamation: 배열을 이용한 리스트 구현
> 리스트 != 연결 리스트 by 구현방법

### 리스트의 이해
-   순차 리스트

    배열을 기반으로 구현된 리스트
-   연결 리스트

    메모리의 동적 할당을 기반으로 구현된 리스트
    
-   리스트 자료구조의 특성

    `데이터를 나란히 저장한다`<br>
    `중복된 데이터의 저장을 막지않는다`
    
### 리스트의 ADT
> 리스트 자료구조가 제공해야할 기능들

`void ListInit(List* plist);`

-   초기화할 리스트의 주소 값을 인자로 전달
-   리스트 생성 후 제일먼저 호출되어야 하는 함수

`void LInsert(List* plist, LData data);`

-   리스트에 데이터를 저장
-   매개변수 data에 전달된 값을 저장

`int LFirst(List* plist, LData* pdata);`

-   첫번째 데이터가 pdata가 가리키는 메모리에 저장
-   데이터 참조를 위한 초기화 진행
-   성공 시 TRUE(1), 실패 시 FALSE(0) 반환

`LData LRemove(List* plist);`

-   LFirst 또는 LNext 함수의 마지막 반환 데이터를 삭제
-   삭제된 데이터를 반환
-   마지막 반환 데이터를 삭제하므로 연이은 반복호출을 허용하지 않음

`int LCount(List\* plist);`

-   리스트에 저장되어 있는 데이터의 수를 반환


### 리스트의 ADT를 기반으로 정의된 main 함수
[ListMain.c](https://github.com/Ejaeda/42_study/blob/master/자료구조/Ch03_연결리스트/file/ListMain.c)
```.c
#include <stdio.h>
#include "ArrayList.h"

int main(void)
{
    // ArrayList의 생성 및 초기화
    List list;				// 리스트의 생성
    int data;
    Listinit(&list);			// 리스트 초기화

    // 5개의 데이터 저장
    LInsert(&list, 11);
    LInsert(&list, 11);
    LInsert(&list, 22);
    LInsert(&list, 22);
    LInsert(&list, 33);

    // 저장된 데이터의 전체 출력
    printf("현재 데이터의 수 : %d\n", LCount(&list));

    if(LFirst(&list, &data))    // 첫 번째 데이터를 변수 data에 저장
    {
        printf("%d", data);
        
        while(LNext(&list, &data))  // 두번째 이후의 데이터를 변수 data에 저장
        {
            printf("%d", data);
        }	
    }
    Printf("\n\n");
    
    /* 숫자 22를 탐색하여 모두 삭제 */
    if (LFirst(&list, &data))
    {
        if (data == 22)  
            LRemove(&list);			    // 앞서 LFirst함수가 참조한 데이터 삭제
	
        while(LNext(&list, &data))
        {
            if (data == 22)
                LRemove(&list); 		    // 앞서 LNext함수가 참조한 데이터 삭제
        }
     }
}
```

-   LFirst를 먼저 호출하고 LNext이 이어지는 이유

    이들은 리스트 내에서 데이터의 참조위치를 기록함
    
    참조를 새롭게 시작하기 위해서는 데이터 참조위치를 초기화 해야함
    
    이를 위해 `LFirst`를 먼저 호출 후 `LNext`호출하여 다음에 저장된 데이터를 이어서 획득

> 모든 데이터의 참조 : LFirst → LNext → LNext → LNext ...

### 배열 기반으로 리스트 구현하기: ArrayList.h

##### 구조체 [ArrayList.h](https://github.com/Ejaeda/42_study/blob/master/자료구조/Ch03_연결리스트/file/ArrayList.h)

```.c
#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#define TRUE	1
#define FALSE	0

#define LIST_LEN	100
typedef int LData;	 		    // 리스트에 int형 데이터의 저장을 위한 선언

typedef struct __ArrayList
{
	LData arr[LIST_LEN];                // 데이터의 저장공간이 배열로 선언
	int numOfData;                      // 저장된 데이터의 수 기록
	int curPosition;                    // 데이터 참조위치 기록
} ArrayList;

typedef ArrayList List;       	  	    // List는 배열 기반 리스트임을 선언
					    // LinkedList List로 변경하면 리스트 종류가 바

void ListInit(List * plist);           	    // 초기화
void LInsert(List * plist, LData data);     // 데이터를 저장

int LFirst(List * plist, LData * pdata);    // 첫 데이터 참조
int LNext(List * plist, LData * pdata);     // 두번째 이후 데이터 참조

LData LRemove(List * plist);                // 참조한 데이터 삭제
int LCount(List * plist);                   // 저장된 데이터 수 반환

#endif
```

### 삽입과 조회

-   `ListInit(List* Plist)` 초기화 작업 

```.c
void	ListInit(List* Plist){
	(plist -> numOfData) = 0;	    // 리스트에 저장된 데이터의 수는 0
	(plist -> curPosition) = -1; 	    // 현재 아무 위치도 가리키지 않는다는 뜻
}
```
> `curPosition`가 0 이면 배열의 첫번째를 뜻하므로 -1로 초기화

-   `void LInsert(List* plist, LData data)` 데이터의 수가 배열의 길이를 초과했는지 검사

```.c
void	LInsert(List * plist, LData data) {
    if	(plist->numOfData >= LIST_LEN) {    // 더 이상 저장할 공간이 없다면
        puts("저장이 불가능합니다.");
        return;
    }
 
    plist->arr[plist->numOfData] = data;    // 데이터 저장
    (plist->numOfData)++;		    // 저장된 데이터의 수 증가
}
```

-   `int LFirst(List * plist, LData * pdata)` `int LNext(List * plist, LData * pdata)` 조회

```.c
int LFirst(List * plist, LData * pdata) {   // 첫번째 조회
    if (plist->numOfData == 0)		    // 저장된 데이터가 하나도 없다면
        return FALSE;			    // FALSE
 
    (plist->curPosition) = 0;		    // 참조위치 초기화(첫 번째 데이터의 참조를 의미)
    *pdata = plist->arr[0];		    // pdate가 가리키는 공간에 데이터 저장
    return TRUE;			    // 저장 했음을 알리는 TRUE
}
 
int LNext(List * plist, LData * pdata) {
    if (plist->curPosition >= (plist->numOfData) - 1)
        return FALSE;			    // 더 이상 참조할 데이터가 없다면 FALSE
 
    (plist->curPosition)++;		    // 그 다음 장소에 저장해주기 위해 ++
    *pdata = plist->arr[plist->curPosition];
    return TRUE;
}
```
> ☑️ `LFirst : (plist -> curPosition)=0;`
> curPosition에 저장된 값을 0으로 재설정하여 데이터의 참조가 앞에서부터 다시 진행되게 한다
> ☑️ `LNext : (plist->curPosition)++;`
> curPosition 값을 증가시켜 순서대로 데이터를 참조할 수 있도록 한다

### 삭제

- ListMain.c에서 `LData LRemove`가 언급되었던 부분

```.c
if (LFirst(&list, &data))
{
    if (data == 22)  
        LRemove(&list);			    // 앞서 LFirst함수가 참조한 데이터 삭제
	
    while(LNext(&list, &data))
    {
        if (data == 22)
            LRemove(&list); 		    // 앞서 LNext함수가 참조한 데이터 삭제
    }
}
```
> `LRemove`함수는 `LFirst`함수나 `LNext`함수의 호출을 통해 바로 직전에 참조가 이뤄진 데이터를 삭제한다<br>
<img width="352" alt="스크린샷 2021-11-23 오후 8 39 38" src="https://user-images.githubusercontent.com/87407504/143017864-e4c4a4ed-b842-4a2f-9ed7-60bd40757856.png"><br>
> `LRemove`함수가 호출되면 리스트의 멤버 `curPosition`을 확인해서, 조회가 이뤄진 데이터의 위치를 확인한 후에, 그 데이터를 삭제한다
> 중간에 데이터가 삭제되면, 뒤에 저장된 데이터를 한 칸씩 앞으로 이동시켜 빈 공간을 메워야 한다

-  `LData LRemove(List* plist)` 최근 조회가 이루어진 데이터 삭제

```.c
LData	LRemove(List * Plist)
{
	int rpos = plist->curPosition;		// 삭제할 데이터 인덱스 값 참조
	int num = plist->numOfData;
	int i;
	LData rdata = plist->arr[rpos];		// 삭제할 데이터 임시저장
	
	/* 삭제를 위한 데이터의 이동을 진행하는 반복문 */
	for(i=rpos; i<num-1; i++)
	    plist->arr[i] = plist->arr[i+1];
	    
	(plist->numOfData)--;			// 삭제한 데이터만큼 데이터 수 감소
	(plist->curPosition)--;			// 참조위치를 하나 되돌림
	return rdata;				// 삭제된 데이터 반환
}
```
> 참조위치(curPosition)를 되돌리는 이유
> *	curPosition은 최근 참조가 이루어진 데이터의 인덱스 정보를 담는다
> *	삭제로 인해 데이터를 한 칸씩 앞으로 이동시키면 curPosition도 같이 앞으로 이동시켜줘야한다
> *	예로 arr[3]의 값을 지웠다면 arr[4]이후의 값은 [3]부터 저장될 것이다
> *	curPosition은 삭제가 되기 전[4]의 값을 인덱스 3을 가리킨 상황에서 가져오는데 [3]이 삭제되었으므로 2를 가리켜야한다 

### 배열 기반의 리스트 구현 하나로 묶기
[ArrayList.c](https://github.com/Ejaeda/42_study/blob/master/자료구조/Ch03_연결리스트/file/ListMain.c)
### 배열 리스트의 장단점

장점

-  데이터의 참조가 비교적 쉽다
- 인덱스 값을 기준으로 어디든 한 번에 참조가 가능하다

단점

-  배열의 길이가 초기에 결정된다 (변경 불가능)
-  삭제를 하면 데이터이동이 빈번하게 발생한다


-----
### 리스트에 구조체 변수 저장하기1 : 구조체 point와 관련 함수들의 정의

리스트에 정수가 아닌 다른 데이터를 저장하기 위해 정의한 리스트에 `구조체 변수의 주소값`을 저장하기
```.c
typedef struct_point
{
    int xpos;		// x좌표 정보
    int ypos;  		// y좌표 정보
} point;
```
학습 후 이어하기
