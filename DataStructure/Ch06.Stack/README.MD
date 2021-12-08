### [목차]
-  [06-1. 스택의 이해와 ADT 정의](#스택의-이해와-ADT-정의)
-  [06-2. 스택의 배열 기반 구현](#스택의-배열-기반-구현)
-  [06-3. 스택의 연결 리스트 기반 구현](#스택의-연결-리스트-기반-구현)
-  [06-4. 계산기 프로그램 구현](#계산기-프로그램-구현)

# 스택의 이해와 ADT 정의
> 스택의 개념을 확인하고<br>
> 스택의 ADT를 정의

## 스택(Stack)의 이해

후입선출 방식의 선형 자료구조
- 먼저 들어간 것이 나중에 나온다
- LIFO(Last In First Out) 구조의 자료구조
> top : stack의 가장 위를 가리키는 포인터 변수(가장 최근에 저장된 data를 가리킴)

## 스택 ADT
`void StackInit(Stack * pstack)`
-  스택의 초기화를 진행
-  스택 생성 후 제일먼저 호출되어야 하는 함수

`int IsEmpty(Stack * pstack)`
-  스택이 빈 경우 1 / 아니면 0을 반환

`void Push(stack * pstack, Data data)`
-  스택에 데이터를 저장
-  data로 전달된 값을 저장

`Data Pop(Stack * pstack)`
-  마지막에 저장된 data를 반환하고 삭제함
-  top이 가리키는 data를 반환하는 것
-  하나 이상 존재할 떄 호출 되어야 함

`Data Peek(Stack * pstack)`
-  마지막에 저장된 data를 반환하되 삭제하지 않음
-  top이 가리키는 data를 반환하는 것
-  하나 이상 존재할 때 호출 되어야 함

# 스택의 배열 기반 구현
배열의 0번 인덱스가 스택의 바닥

`Push`
-  top을 한칸 위로 올리고 top이 가리키는 위치에 data를 저장

`Pop`
-  top이 가리키는 data를 반환하고, top을 아래로 한칸 내림

## 배열 기반 스택의 헤더파일
[ArrayBaseStack.h](https://github.com/Ejaeda/42_study/blob/master/DataStructure/Ch06.Stack/File/ArrayBaseStack/ArrayBaseStack.h)<br>

## 배열 기반 스택의 구현
구조체 정의
```.c
typedef struct _arrayStack
{
	Data stackArr[STACK_LEN];
	int topIndex;
} ArrayStack;

typedef ArrayStack Stack;
```
> 구조체 정의에서 초기화할 멤버는 topIndex

초기화 함수
```.c
void StackInit(Stack * pstack)
{
	pstack->topIndex = -1;                  // 배열은 0부터 시작하니까
}
```

스택이 비었는지 확인하는 함수
```.c
int SIsEmpty(Stack * pstack)
{
	if(pstack->topIndex == -1)
		return TRUE;
	else
		return FALSE;
}
```
> 비어있다면 1 / 아니면 0을 반환

Push 함수
```.c
void SPush(Stack * pstack, Data data)
{
	pstack->topIndex += 1;
	pstack->stackArr[pstack->topIndex] = data;
}
```

Pop 함수
```.c
Data SPop(Stack * pstack)
{
	int rIdx;

	if(SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	rIdx = pstack->topIndex;                  // 삭제할 데이터가 저장된 인덱스 값 저장
	pstack->topIndex -= 1;                    // pop 연산의 결과로 topIndex 값 하나 감소

	return pstack->stackArr[rIdx];            // 삭제되는 데이터 반환
}
```
> Pop은 삭제와 반화의 의미를 함께 가진다<br>

Peek 함수
```.c
Data SPeek(Stack * pstack)
{
	if(SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	return pstack->stackArr[pstack->topIndex];
}
```
> 반환한 데이터를 소멸시키지 않는다
[ArrayBaseStack.c](https://github.com/Ejaeda/42_study/blob/master/DataStructure/Ch06.Stack/File/ArrayBaseStack/ArrayBaseStack.c)<br>
[ArrayBaseStackMain.c](https://github.com/Ejaeda/42_study/blob/master/DataStructure/Ch06.Stack/File/ArrayBaseStack/ArrayBaseStackMain.c)<br>

# 스택의 연결 리스트 기반 구현
> 배열과 연결 리스트는 모두 선형 자료구조 이므로 배열은 대부분 연결 리스트로 교체 가능

## 연결 리스트 기반 스택의 이해
> 스택도 저장된 순서의 역순으로 조회가 가능한 연결 리스트일 뿐이다

data의 추가와 삭제가 list의 head에서 이루어짐
<img width="450" alt="스크린샷 2021-12-08 오후 3 06 59" src="https://user-images.githubusercontent.com/87407504/145157090-b7a5303a-4e31-4c6f-beb1-478fdeff41e5.png"><br>

ADT에 추가되어야 하는 부분
-  push 연산 : list의 첫 부분에 newNode 추가(추가된 newNode를 head가 가리키게 함)
-  pop 연산 : head가 가리키는 노드를 반환하고 삭제

## 연결 리스트 기반 스택의 헤더파일
[ListBaseStack.h](https://github.com/Ejaeda/42_study/blob/master/DataStructure/Ch06.Stack/File/ListBaseStack/ListBaseStack.h)<br>
> 배열 기반 스택과 크게 다르지 않다

## 연결 리스트 기반 스택의 구현

구조체 정의
```.c
//typedef int Data;

//typedef struct _node
//{
//	Data data;
//	struct _node * next;
//} Node;

typedef struct _listStack
{
	Node * head;
} ListStack;

typedef ListStack Stack;
```

초기화 함수
```.c
void StackInit(Stack * pstack)
{
	pstack->head = NULL;              // 포인터 변수 head는 NULL로 초기화
}
```

비어있는지 확인하는 함수
```.c
int SIsEmpty(Stack * pstack)
{
	if(pstack->head == NULL)          // 스택이 비면 head에는 NULL이 저장
		return TRUE;
	else
		return FALSE;
}
```
> 포인터 번수 head는 새로 추가된 노드를 가리켜야 한다

Push 함수
```.c
void SPush(Stack * pstack, Data data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;
	newNode->next = pstack->head;

	pstack->head = newNode;
}
```

Pop 함수
```.c
Data SPop(Stack * pstack)
{
	Data rdata;
	Node * rnode;

	if(SIsEmpty(pstack)) {
		printf("Stack Memory Error!");
		exit(-1);
	}

	rdata = pstack->head->data;             // 삭제할 노드의 데이터를 임시로 저장
	rnode = pstack->head;                   // 삭제할 노드의 주소 값을 임시로 저장

	pstack->head = pstack->head->next;      // 삭제할 노드 다음 노드를 head가 가리킴
	free(rnode);                            // 노드 삭제

	return rdata;                           // 삭제된 노드의 데이터 반환
}
```

Peek 함수
```.c
Data SPeek(Stack * pstack)
{
	if(SIsEmpty(pstack)) {
		printf("Stack Memory Error!");
		exit(-1);
	}

	return pstack->head->data;              // head가 가리키는 노드에 저장된 데이터를 반환
}
```
> 스택에서는 삭제하지 않음 top이 가리키는 data를 반환할 뿐

[ListBaseStack.c](https://github.com/Ejaeda/42_study/blob/master/DataStructure/Ch06.Stack/File/ListBaseStack/ListBaseStack.c)<br>
[ListBaseStackMain.c](https://github.com/Ejaeda/42_study/blob/master/DataStructure/Ch06.Stack/File/ListBaseStack/ListBaseStackMain.c)<br>
> 배열 기반 스택의 main 함수와 동일

# 계산기 프로그램 구현
-  top이 가리키는 data를 반환하는 것
