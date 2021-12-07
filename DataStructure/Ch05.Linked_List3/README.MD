### [목차]
-  [05-1. 원형 연결 리스트](#05-1-원형-연결-리스트)<br>
-  [05-2. 양방향 연결 리스트](#05-2-양방향-연결-리스트)<br>

# 05-1. 원형 연결 리스트
> 05-1. 에서는 원형 연결 리스트에 대한 설명을 중점적으로 학습<br>
> 이후 문제 05-1에서 원형 연결 리스트의 활용 학습<br>
> 구현에 너무 목매이지 마라!<br>
### [학습흐름]
<리스트 설명>
-  [05-1-1. 원형 연결 리스트의 이해](원형-연결-리스트의-이해)<br>
-  [05-1-2. 변형된 원형 연결 리스트](변형된-원형-연결-리스트)<br>

<리스트 구현>
-  [05-1-3. 변형된 원형 연결 리스트의 헤더파일](변형된-원형-연결-리스트의-헤더파일)<br>
-  [05-1-4. 변형된 원형 연결 리스트의 삽입](변형된-원형-연결-리스트의-삽입)<br>
-  [05-1-5. 변형된 원형 연결 리스트의 조회](변형된-원형-연결-리스트의-조회)<br>
-  [05-1-6. 변형된 원형 연결 리스트의 조회](변형된-원형-연결-리스트의-삭제)<br>
-  [05-1-7. 변형된 원형 연결 리스트 하나로 묶기](변형된-원형-연결-리스트-하나로-묶기)<br>

<리스트 활용>
-  [문제 05-1. 원형 연결 리스트의 활용](문제 05-1-원형-연결-리스트의-활용)

> 자료구조를 학습하면서 모든 것들을 보지않고 구현하려는 능력을 최우선과제로 생각하지 말 것<br>
> 내가 코드의 전체적인 흐름을 이해했고<br>
> ADT의 변경 및 추가로 인해 함수를 일부 변경 및 추가할 수 있으면 된다<br>

## 원형 연결 리스트의 이해

-  단순 연결 리스트는 마지막 노드가 NULL을 가리킨다

-  마지막 노드가 NULL이 아닌 첫번째 노드를 가리키면 원형 연결 리스트가 된다

원형 연결 리스트에서 새로운 노드를 추가하는 방식에서

-  머리는 head가 가리키고 있으므로 바로 추가가 가능하다

-  꼬리에 추가하기 위해서는 head를 시작하여 처음 노드를 가리키는 마지막 노드에 도달해야한다
<img width="450" alt="스크린샷 2021-12-07 오후 3 43 05" src="https://user-images.githubusercontent.com/87407504/144979708-a631b143-086a-4a30-aca9-bd2d6a0bdcf8.png"><br>

그렇다면 head보다 tail이 있는 것이 더 유용하지 않겠는가?
> 이를 변형된 원형 연결 리스트로 언급

## 변형된 원형 연결 리스트

변형된 원형 연결 리스트의 장점

-  head와 tail 두개 다 있을 필요는 없다

-  head가 아닌 tail을 사용할 경우 새 노드를 추가할 때 더 유용하다
<img width="450" alt="스크린샷 2021-12-07 오후 3 46 26" src="https://user-images.githubusercontent.com/87407504/144980093-db420db5-0f30-4b73-85e6-041bf307f040.png"><br>
> 꼬리를 가리키는 포인터 변수 : tail<br>
> 머리를 가리키는 포인터 변수 : tail -> next

## 변형된 원형 연결 리스트의 헤더파일
[CLinkedList.h](https://github.com/Ejaeda/42_study/blob/master/DataStructure/Ch05.Linked_List3/File/CircularLinkedList/CLinkedList.h)<br>

연결 리스트의 활용가치를 높이는 대표적인 함수 다음이 있다
-  LFirst, LNext, LRemove

원형 연결 리스트의 구조적 특성상 LNext 함수의 기능을 변형한다
-  LNext는 무한 반복 호출이 가능

-  LNext는 리스트 끝에 도달할 경우 첫 번째 노드부터 다시 조회가 시작

이전의 헤더파일과 크게 다르지 않지만 변형된 원형 연결 리스트 특성상 두가지에 주목하자
```.c
-  void LInsert(List * plist, Data data);   // 꼬리에 노드를 추가

-  void LInsertFront(List * plist, Data data);   // 머리에 노드를 추가
```
## 변형된 원형 연결 리스트의 삽입

초기화 함수
```.c
void ListInit(List * plist)
{
	    plist->tail = NULL;
    	plist->cur = NULL;
	    plist->before = NULL;
	    plist->numOfData = 0;
}
```
리스트의 멤버들을 NULL 또는 0으로 초기화하면 끝<br>

삽입 함수
> 새 노드를 꼬리에 추가하는 LInsert 함수
> 새 노드를 머리에 추가하는 LInsertFront 함수
```.c
// 위 두가지 함수는 초기화 상태에서 같은 코드를 가진다
void LInsert(List * plist, Data data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if(plist->tail == NULL) 		// 초기화 상태라는 뜻
	{
		plist->tail = newNode;		// tail이 노드를 가리키게 하고
		newNode->next = newNode;	// 노드가 하나뿐이니 자기자신을 가리키게하여
						// 원형상태 만들기
	}
	else 
	{
		// 차이발생
	}

	(plist->numOfData)++;
}
```
두번째 노드 이후의 노드가 추가되는 상황
Case 1) 머리에 추가
> tail이 가리키는 노드는 꼬리 노드이므로 머리노드는 tail->Next
```.c
	else 
	{
		newNode->next = plist->tail->next;	// 새 노드가 가리키는 노드가
						        // tail->next 이다
						   //(tail이 가리키는 노드가 가리키는 노드
		plist->tail->next = newNode;		// tail이 가리키고 있는 노드가
							// 추가된 노드를 가리키도록 한다
	}
```
Case 2) 꼬리에 추가
> tail이 가리키는 노드가 꼬리 노드<br>
> 머리에 추가하는 것과 다른점은 tail이 가리키는 노드가 다르다는 것 뿐이다
```.c
	else 
	{
		newNode->next = plist->tail->next;	// 위와 같이 진행하고
		plist->tail->next = newNode;
		plist->tail = newNode;			// tail이 새 노드를 가리키도록 한다
	}
```
원형 연결 리스트는 머리와 꼬리의 구분이 의미가 없다

## 변형된 원형 연결 리스트의 조회
> 데이터의 조회를 담당하는 LFirst 함수와 LNext 함수

먼저 CLL구조체 정의를 보자
```.c
typedef struct _CLL
{
	Node * tail;
	Node * cur;
	Node * before;
	int numOfData;
} CList;
```
단순 연결 리스트와 동일<br>
-  before을 통해 다음 움직일 노드를 가리키게 하고<br>
-  bofore보다 하나 앞선 cur을 통해 데이터에 접근한다

int LFirst
> 해당 함수를 통해 cur(머리)과 before(꼬리)를 초기셋팅한다
```.c
int LFirst(List * plist, Data * pdata)
{
	if(plist->tail == NULL)    		// 저장된 노드가 없다면
		return FALSE;

	plist->before = plist->tail;		// before가 꼬리를 가리키게 한다
	plist->cur = plist->tail->next;		// cur이 머리를 가리키게 한다

	*pdata = plist->cur->data;		// cur이 가리키는 노드의 데이터를 반환
	return TRUE;
}
```
int Lnext
```.c
int LNext(List * plist, Data * pdata)
{
	if(plist->tail == NULL) 		// 저장된 노드가 없다면
		return FALSE;

	plist->before = plist->cur;		// cur위치로 before가 이동
	plist->cur = plist->cur->next;		// cur 앞의 위치로 한칸 이동

	*pdata = plist->cur->data;		// 다음 데이터를 반환
	return TRUE;
}
```
리스트의 끝을 검사하는 코드가 존재하지 않는다
-  무한반복 호출이 가능

## 변형된 원형 연결 리스트의 삭제
> 단순 연결 리스트의 삭제 구조와 유사<br>
단순 연결 리스트 삭제 구조
-  삭제할 노드의 이전 노드가, 삭제할 노드의 다음 노드를 가리키게 한다
```.c
   plist -> before -> next = plist -> cur -> next; // before가 가리키는 노드가 
   					           // cur이 가리키는 노드를 가리키도록
```

-  포인터 변수 cur을 한 칸 뒤로 이동시킨다
```.c
   plist -> cur = plist -> before;		   // cur이 before가 가리키는 노드를 가리키도록
```
> 삭제할 노드는 초기에 cur이 가리키고 있다

단순 연결 리스트와 원형 연결 리스트의 차이
-  더미 노드의 유무

이로인한 예외적 상황 두가지를 구분해야 한다
Case 1) 삭제할 노드를 tail이 가리키는 경우
   -  tail이 가리키는 노드가 삭제되므로 tail이 다른 노드를 가리키도록 해야한다
   -  tail은 before가 가리키는 노드인, 삭제될 노드 이전 노드를 가리켜야 한다

Case 2) 삭제할 노드가 리스트에 홀로 남은 경우
   -  삭제된 후에 포인터 변수 tail은 더이상 가리킬 노드가 없으므로 NULL을 가리키도록 해야한다

삭제 함수
```.c
Data LRemove(List * plist)
{
	Node * rpos = plist->cur;			// 삭제 대상을 cur이 가리킨다
	Data rdata = rpos->data;

	if(rpos == plist->tail)    			// Case 1) tail이 삭제 대상을 가리키고
	{						
		if(plist->tail == plist->tail->next)    // Case 2)그리고 마지막 남은 노드라면
			plist->tail = NULL;
		else
			plist->tail = plist->before;    // Case 1) 대로만 한다
	}

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(rpos);
	(plist->numOfData)--;
	return rdata;
}
```
> 원형 연결 리스트에 더미 노드를 만들어 준다면 위 함수가 예외없이 간단해 질 것 같다<br>
> 그렇지만 이로인해 LNext 함수 구현에 있어 더미노드를 처리해야하는 추가 소요가 발생한다

## 변형된 원형 연결 리스트 하나로 묶기
[CLinkedList.h](https://github.com/Ejaeda/42_study/blob/master/DataStructure/Ch05.Linked_List3/File/CircularLinkedList/CLinkedList.h)<br>
[CLinkedList.c](https://github.com/Ejaeda/42_study/blob/master/DataStructure/Ch05.Linked_List3/File/CircularLinkedList/CLinkedList.c)<br>
[CLinkedListMain.c](https://github.com/Ejaeda/42_study/blob/master/DataStructure/Ch05.Linked_List3/File/CircularLinkedList/CLinkedListMain.c)<br>
[문제 넘기기](05-2-양방향-연결-리스트)
## 문제 05-1. 원형 연결 리스트의 활용
직원정보 등록((int)사번, 이름)
-  직원 정보를 담을 구조체를 정의, 대략 네 명의 직원 정볼르 원형 연결 리스트에 저장하기
-  원형 연결 리스트에는 구조체 변수의 주소 값을 저장

직원들의 당직 순서는 프로그램 등록순
-  A, B, C 순이면 A - B - C - A...

직원의 이름과 하나의 숫자를 이용해 당직자를 확인
-  직원의 이름과 숫자를 인자로 받는 함수를 하나 정의
-  전달된 이름이 당직은 선 후로, 전달된 숫자에 해당하는 만큼의 날이 지나서 당직을 서게되는 직원의 정보를 반환
-  예를들어 A와 숫자 7이 전달되면 A이 당직선 후로 7일 뒤에 누가 당직을 서는지 반환되어야 함

### 문제풀이
1. 직원정보 등록을 위한 구조체 정의
Employee.h
```.c
#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

typedef struct _Employee
{
	int empNum;		// 사번
	char name[30];		// 이름
} Employee;

#endif
```
해당 헤더파일을 CLinkedList.h에 `#include "Employee.h"`로 선언한다

2. main파일 작성
[NightDutyMain.c](https://github.com/Ejaeda/42_study/blob/master/DataStructure/Ch05.Linked_List3/File/Q05-1/NightDutyMain.c)<br>

# 05-2. 양방향 연결 리스트
> 
> 
### [학습흐름]
<리스트 설명>
-  [05-2-1. 양방향 연결 리스트의 이해](양방향-연결-리스트의-이해)<br>
-  [05-2-2. 변형된 원형 연결 리스트](변형된-원형-연결-리스트)<br>

<리스트 구현>
-  [05-2-3. 변형된 원형 연결 리스트의 헤더파일](변형된-원형-연결-리스트의-헤더파일)<br>
-  [05-2-4. 변형된 원형 연결 리스트의 삽입](변형된-원형-연결-리스트의-삽입)<br>
-  [05-2-5. 변형된 원형 연결 리스트의 조회](변형된-원형-연결-리스트의-조회)<br>
-  [05-2-6. 변형된 원형 연결 리스트의 조회](변형된-원형-연결-리스트의-삭제)<br>
-  [05-2-7. 변형된 원형 연결 리스트 하나로 묶기](변형된-원형-연결-리스트-하나로-묶기)<br>

## 양방향 연결 리스트의 이해
> doubly linked list<br>
> 이중 연결 리스트

노드가 양쪽 방향으로 연결된 구조의 리스트
<img width="450" alt="스크린샷 2021-12-07 오후 6 53 00" src="https://user-images.githubusercontent.com/87407504/145006857-cc70b6a0-eaec-4d9d-a22e-a4f2ba2d7f37.png"><br>

양방향 연결 리스트의 노드를 표현하는 구조체
```.c
typedef struct _node
{
	Data data;			// typedef int Data
	struct _node * next;		// 오른쪽 노드를 가리키는 포인터 변수
	struct _node * prev;		// 왼쪽 노드를 가리키는 포인터 변수
}Node;
```

