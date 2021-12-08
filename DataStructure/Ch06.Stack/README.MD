### [목차]
-  [06-1. 스택의 이해와 ADT 정의](#스택의-이해와-ADT-정의)
-  [06-2. 스택의 배열 기반 구현](#스택의-배열-기반-구현)
-  06-3.
-  06-4.

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
[ArrayBaseStack.h]()

## 배열 기반 스택의 구현
