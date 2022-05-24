# 📖 Linked_list by Array

### [목차]
-  [03-1. 추상 자료형](#03-1-추상-자료형)<br>
-  [03-2. Array List](#03-2-배열을-이용한-리스트-구현)<br>

----

# 03-1. 추상 자료형
> Abstract Data Type
### [학습 흐름]
-  [03-1-1. 자료구조 공부 이전에 추성 자료형에 대해 이해하자](#자료구조에서의-추상-자료형)<br>
-  [03-1-2. 자료구조의 학습 순서를 알아보자](#리스트-자료구조의-학습순서)


## 자료구조에서의 추상 자료형
> 자료구조 공부 이전에 추상 자료형에 대해 이해하자
#### 추상 자료형(ADT) 정의

-  구체적인 완성과정을 언급하지 않고, 순수하게 `기능이 무엇인지를 나열한 것`
    
#### cf) 자료형의 정의
    
-  구조체를 정의하는 것 뿐만 아니라 해당 구조체를 기반으로 한 **연산**의 종류를 결정하는 것까지 포함<br>
    (해당 구조체를 기반으로 제공할 수 있는 기능 관련 연산)

-  다시말해  **자료형**의 정의에 **기능**(연산)과 관련된 내용을 명시할 수 있음

#### 예시(구조체 Wallet과 Wallet의 ADT의 비교)
-  구조체 Wallet
```.c
typedef struct_wallet  			  // 동전 및 지폐 일부만을 대상으로 표현한 지갑
{
    int coin100Num;     		  // 100원짜리 동전의 수
    int bill5000Num;  			  // 5,000원짜리 지폐의 수
} Wallet;
```
> 구조체를 기반으로 지갑을 의미하는 Wallet 이라는 자료형을 정의<br>
> 이것은 지갑이라는 건데 100원짜리 동전과 5000원짜리 지폐를 넣을 수 있어

-  Wallet의 ADT
```.c
Operations:

int   TakeOutMoney(Wallet* pw, int coinNum, int billNum);   // 돈을 꺼내는 연산
-  첫번째 인자로 전달된 주소의 지갑에서 돈을 꺼냄
-  두번째 인자로 꺼낼 동전의 수, 세 번쩨 인자로 꺼낼 지폐의 수를 전달
-  꺼내고자 하는 돈의 총액이 반환 + 그만큼 돈이 차감

void	PutMoney(Wallet* pw, int coinNum, int billNum);     // 돈을 넣는 연산
-  첫번째 인자로 전달된 주소의 지갑에 돈을 넣음
-  두번째 인자로 넣을 동전의 수, 세 번쩨 인자로 넣을 지폐의 수를 전달
-  넣은만큼 돈전과 지폐수가 증가
```
> Wallet을 기반으로 제공할 수 있는 기능 관련 연산을 명시<br>
> 이것은 돈을 꺼내고 넣을 수 있어

-  지갑을 설명하기위해 정의를 설명할 수도 있지만 기능만으로 설명할 수 있다
-  C언어에서는 이에 해당하는 기능, 즉 연산을 함수를 이용해 정의한다
#### 즉, Wallet이라는 자료형의 정의는 `Wallet 정의`와 `Wallet 기능`이 더해져 완성된다

----

## :book: Wallet의 ADT에 구조체 Wallet의 정의를 포함시켜야 하는가

#### 예시
```.c
int main(void){
    wallet myWallet;				// 지갑하나를 설정

    putMoney(&myWallet, 5, 10);			// 돈을 넣는다
 
    ret = TakeOutMoney(&myWallet, 2, 5);	// 돈을 꺼낸다
}
```
> Wallet을 기반으로 돈을 넣고 꺼내기 때문에 Wallet의 멤버의 구성을 굳이 알 필요 없다
> C언어의 파일 입출력을 공부하면서 FILE 구조체의 내부를 궁금해하지 않지않나

```.vim
결론 : 필요없다
```

----

## 리스트 자료구조의 학습순서

리스트 자료구조를 공부할때 다음과 같은 순서로 접근한다

1.  리스트 자료구조의 ADT 정의
2.  ADT를 근거로 리스트 자료구조를 활용하는 main 함수 정의
3.  ADT를 근거로 리스트 구현

> ADT에 정의된 함수들이 어떻게 구성되어있는지도 모르고 ADT만보고 main함수를 정의하는데 왜?
> 리스트 사용자는 사용 방법만 알면되지 어떻게 구성되어있는지까지 알 필요없다
> ADT를 보고 main함수를 사용할 수 있도록 감을 기르자
> 예를들어 LInsert로 입력을 받는데 왜 첫번째 인자로 &list가 똑같이 들어가는지 그냥 쓰기만 할줄 알면 된다
```.c
모든걸 만들어서 하려고 하지말자
```
----

# 📖 03-2. 배열을 이용한 리스트 구현
> Array List(순차 리스트)

### [학습 흐름]

<1. 리스트 자료구조의 ADT 정의>

-  [03-2-0. 리스트의 이해](#리스트의-이해)
-  [03-2-1. 리스트 ADT를 정의](#리스트의-adt-정의)

<2. ADT를 근거로 리스트 자료구조를 활용하는 main 함수 정의>

-  [03-2-2. ADT를 근거로 리스트 자료구조를 활용하는 main 함수 정의](#adt를-근거로-리스트-자료구조를-활용하는-main-함수-정의)
 
<3. ADT를 근거로 리스트 구현>

-  [03-2-3. 배열 리스트의 헤더파일 정의](#배열-리스트의-헤더파일-정의)
-  [03-2-3. 배열 리스트의 삽입과 조회](#배열-리스트의-삽입과-조회)
-  [03-2-3. 배열 리스트의 삭제](#배열-리스트의-삭제)
-  [03-2-3. 배열 리스트 하나로 묶기](#배열-리스트-하나로-묶기)
-  [03-2-4. 배열 리스트의 장단점](#배열-리스트의-장단점)
-  [03-2-5. 리스트에 구조체 변수 저장하기](#리스트에-구조체-변수-저장하기)

리스트 자료구조 공부 순서대로
     
-    ADT정의(03-2-1) -> main함수 정의(03-2-2) -> 배열 리스트 구현(03-2-3)순으로 학습
-    최종적인 목표는 리스트를 사용하기 위해 ArrayList.h를 포함시키고 이 헤더파일에 선언된 함수의 기능을 숙지
-    실제 리스트가 어떻게 구현되어 있는지 확인할 필요 없음

> 나아가 위에서는 리스트에 정수만 저장해 보았다면 5를 통해 리스트에 정수만 저장하지 않고 구조체 변수의 주소 값을 저장해보자

----

## 리스트의 이해
> 리스트는 연결리스트가 아니다

리스트 특성

-  데이터를 나란히 저장
-  중복된 데이터의 저장을 막지 않음

리스트 종류 (by 구현방법)
-   순차 리스트

    배열을 기반으로 구현된 리스트

-   연결 리스트

    메모리의 동적 할당을 기반으로 구현된 리스트
    
----
    
## 리스트의 ADT 정의
> 리스트 자료구조가 제공해야할 기능들

`void ListInit(List* plist);`

-   리스트 초기화하는 기능(출발지점을 처음으로 설정)
-   초기화할 리스트의 주소 값을 인자로 전달
-   리스트 생성 후 제일먼저 호출되어야 하는 함수

`void LInsert(List* plist, LData data);`

-   리스트에 데이터를 저장하는 기능
-   두번째 매개변수 data에 전달된 값을 저장

`int LFirst(List* plist, LData* pdata);`

-   맨처음 들어오는 데이터를 pdata가 가리키는 메모리에 저장하는 기능
-   데이터 참조를 위한 초기화 진행
-   참조 성공 시 TRUE(1), 실패 시 FALSE(0) 반환

`int LNext(List* plist, LData* pdata);`
-   참조된 데이터의 다음 데이터를 pdata가 가리키는 메모리에 저장하는 기능
-   순차적인 참조를 위해 반복 호출이 가능
-   참조를 새로 시작하려면 LFirst함수를 호출해야함
-   참조 성공 시 TRUE(1), 실패 시 FALSE(0) 반환

`LData LRemove(List* plist);`

-   가장 최근에 저장한 데이터를 삭제하는 기능
-   LFirst 또는 LNext 함수의 마지막 반환 데이터를 삭제
-   삭제된 데이터는 반환됨
-   마지막 반환 데이터를 삭제하므로 연이은 반복호출을 허용하지 않음

`int LCount(List\* plist);`

-   리스트에 저장되어 있는 데이터의 수를 반환하는 기능
> 위 정보만 가지고도 리스트 자료구조가 제공하는 기능을 어느정도 예측할 수 있어야 한다

----

## ADT를 근거로 리스트 자료구조를 활용하는 main 함수 정의
> 위에서 언급된 리스트의 ADT를 활용하여 main함수가 어떻게 구성되는지 보자
[ListMain.c](https://github.com/Ejaeda/42_study/blob/master/DataStructure/Ch03.Linked_List/file/ListMain.c)

#### main 함수 분석
> 자세한 세부 설명은 [헤더파일 정의](#배열-리스트의-헤더파일-정의)에서 진행

`List list;`

-    list는 이동역할

`ListInit(&list);`
-    이동역할을 하는 list가 처음부터 움직이기 위해 위치를 초기화

`LInsert(&list, number);`
-    첫번째 인자 &list가 똑같이 들어가는 것을 볼 수 있다

     [이유보기](#설명)

`LFirst를 먼저 호출하고 LNext이 이어지는 이유`

-    LFirst와 LNext은 리스트 내에서 데이터의 참조위치를 기록함
    
-    참조를 새롭게 시작하기 위해서는 데이터 참조위치를 초기화 해야함
    
-    이를 위해 `LFirst`를 먼저 호출 후 `LNext`호출하여 다음에 저장된 데이터를 이어서 획득

> 모든 데이터의 참조 : LFirst → LNext → LNext → LNext ...

----

## 문제 03-1[리스트 라이브러리의 활용]

-    1~9를 저장하고 그 합을 계산하여 출력
-    저장된 값들 중 2, 3의 배수를 모두 삭제
-    리스트에 저장된 데이터를 순서대로 출력
답 : [Q1_Listmain.c](https://github.com/Ejaeda/42_study/blob/master/DataStructure/Ch03.Linked_List/file/Q1_ListMain.c)

## 배열 리스트의 헤더파일 정의
[ArrayList.h](https://github.com/Ejaeda/42_study/blob/master/DataStructure/Ch03.Linked_List/file/ArrayList.h)

## 배열 리스트의 삽입과 조회
> 좀더 구체적으로 살펴보자

void ListInit(List* Plist)
```.c
void	ListInit(List* Plist){
	(plist -> numOfData) = 0;	    // 리스트에 저장된 데이터의 수는 0
	(plist -> curPosition) = -1; 	    // 현재 아무 위치도 가리키지 않는다는 뜻
}
```
-    초기화하는 함수
>    `curPosition`가 0 이면 배열의 첫번째를 뜻하므로 -1로 초기화

void LInsert(List* plist, LData data)
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
-    데이터의 수가 배열의 길이를 초과하기 전까지 저장한다

##### 설명
-    왜 같은 list가 게속 들어가는가

     -    void LInsert는 ArratList.c에 정의

     -    LInsert의 &list는 List * plist에게 전달

     -    첫번째 인자 `List * plist`는 
          plist -> arr[plist -> numOfData] = 두번째 인자 `data` 방식으로 데이터를 저장

     -    데이터 저장 이후 (plist -> numOfData)++; 해주므로 같은 list처럼 보이지만 변하고 았음

int LFirst(List * plist, LData * pdata), int LNext(List * plist, LData * pdata)
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
-    LFirst에서 (plist -> curPosition) = 0;

     ☑️  curPosition에 저장된 값을 0으로 재설정하여 데이터의 참조가 앞에서부터 다시 진행되게 한다

-    LNext에서 (plist->curPosition)++;

     ☑️  urPosition 값을 증가시켜 순서대로 데이터를 참조할 수 있도록 한다

## 배열 리스트의 삭제

main함수에서의 LData LRemove
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
-    `LRemove`함수는 `LFirst`함수나 `LNext`함수의 호출을 통해 바로 직전에 참조가 이뤄진 데이터를 삭제한다<br>
<img width="352" alt="스크린샷 2021-11-23 오후 8 39 38" src="https://user-images.githubusercontent.com/87407504/143017864-e4c4a4ed-b842-4a2f-9ed7-60bd40757856.png"><br>

-    `LRemove`함수가 호출되면 리스트의 멤버 `curPosition`을 확인해서, 조회가 이뤄진 데이터의 위치를 확인한 후에, 그 데이터를 삭제한다

-    중간에 데이터가 삭제되면, 뒤에 저장된 데이터를 한 칸씩 앞으로 이동시켜 빈 공간을 메워야 한다

LData LRemove(List* plist)
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
-	참조위치(curPosition)를 되돌리는 이유

	-	curPosition은 최근 참조가 이루어진 데이터의 인덱스 정보를 담는다

	-	삭제로 인해 데이터를 한 칸씩 앞으로 이동시키면 curPosition도 같이 앞으로 이동시켜줘야한다

	-	예로 arr[3]의 값을 지웠다면 arr[4]이후의 값은 [3]부터 저장될 것이다
	-	curPosition은 삭제가 되기 전[4]의 값을 인덱스 3을 가리킨 상황에서 가져오는데 [3]이 삭제되었으므로 2를 가리켜야한다 

## 배열 리스트 하나로 묶기
[ArrayList.c](https://github.com/Ejaeda/42_study/blob/master/DataStructure/Ch03.Linked_List/file/ArrayList.c)
### 배열 리스트의 장단점


단점

-  배열의 길이가 초기에 결정이 되어야한다<br>

   [ArrayList.h](https://github.com/Ejaeda/42_study/blob/master/DataStructure/Ch03.Linked_List/file/ArrayList.h)의 8번째줄에서 배열의 길이를 100으로 고정

-  삭제 과정에서 데이터 이동이 빈번하게 발생한다

장점

-  인덱스 값을 기준으로 어디든 한 번에 참조가 가능해 데이터의 참조가 쉽다


## 리스트에 구조체 변수 저장하기 
> 앞의 설명에서는 리스트에 단순히 정수가 저장되었다
> 실제로는 다양한 데이터들이 저장되므로 구조체 변수의 주소값을 저장해보자
> 기존에 만들었던 배열 리스트의 헤더파일과 소스파일을 활용한다

1. 구조체 point와 관련 함수들 정의하기

-    구조체 변수의 주소값을 저장하기 위한 새 구조체 정의
```.c
typedef struct_point
{
    int xpos;		// x좌표 정보
    int ypos;  		// y좌표 정보
} point;
```
-    구조체 관련 함수 정의
```.c
void SetPointPos(Point * ppos, int xpos, int ypos);	// 구조체 변수에 값을 저장

void ShowPointPos(Point * ppos);			// 저장된 정보 출력

int PointComp(Point * pos1, Point * pos2);		// 두 구조체 변수에 저장된 값 비교
    * xpos만 같으면 1 반환
    * ypos만 같으면 2 반환
    * 둘다 같으면 0 반환
    * 모두 다르면 -1 반환
```
-    [point.h](https://github.com/Ejaeda/42_study/blob/master/DataStructure/Ch03.Linked_List/file/5.file/Point.h)	// 위 구조체 정의와 구조체 관련 함수들을 모은 헤더파일

-    [point.c](https://github.com/Ejaeda/42_study/blob/master/DataStructure/Ch03.Linked_List/file/5.file/Point.c)	// 헤더파일에 선언된 함수들의 정의

2. 1.에 맞게 앞의 ArrayList 코드 변경 [ArrayList.h](https://github.com/Ejaeda/42_study/blob/master/DataStructure/Ch03.Linked_List/file/5.file/ArrayList.h)

Point 구조체 변수의 주소값을 저장하기 위해 변경하기
> 소스파일 .c은 변경하지 않아도 된다
> 헤더파일 .h만 바꾸자

Typedef 선언변경

-  기존의 ArrayList.h에서 Typedef int LData; -> Point * LData;로 변경
> 구조체 정의에서 Point라는 구조체 이름을 썻으니 이에 맞게 변경하는 것

헤더파일 추가

-  #include "Point.h"

#### 정리
-  구조체 변수의 주소 값을 저장하기 위해 새로운 구조체를 정의한다

-  이로인해 ArrayList.h에서의 Typedef 선언이 변경되어야한다

-  새로 정의된 구조체에 맞게 구조체 관련 함수들을 정의한다

-  point 헤더파일에 구조체 정의와 함수들을 선언하고

-  point 소스파일에 헤더파일을 명시하고 함수들을 정의한다

-  위를 바탕으로 새로운 main함수를 만든다 [PointListMain.c](https://github.com/Ejaeda/42_study/blob/master/DataStructure/Ch03.Linked_List/file/5.file/PointListMain.c)

-  소스파일 3개를 컴파일하면 성공

## 문제 03-2[리스트의 활용]
2회독에 완료하기
