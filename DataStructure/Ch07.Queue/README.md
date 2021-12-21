# 큐(Queue)

## 큐의 이해

-  큐(Queue)는 먼저 들어간 데이터가 먼저 나오는 자료구조

>  스택(Stack)은 먼저 들어간 데이터가 나중에 나오는 자료구조
    
## 큐의 ADT 정의

enqueue
-  큐에서 데이터를 넣는 연산

dequeue
-  큐에서 데이터를 꺼내는 연산

```.c
void QueueInit(Queue * pq);
int QIsEmpty(Queue * pq);
void Enqueue(Queue * pq, Data data);      // Stack's push
Data Dequeue(Queue * pq);                 // Stack's pop
Data QPeek(Queue * pq);
```

## 큐의 배열 기반 구현

배열 기반의 큐에서는 '원형 큐'형태로 큐를 구현

-  머리를 가리키는 F와 꼬리를 가리키는 R를 회전시켜 큐를 구성하는 배열을 효율적으로 사용

-  배열애서 앞에 저장공간이 비었을 시 F, R 모두 꼬리를 가리키고 있을 때 F를 맨 앞으로 이동

### 원형 큐(Circular Queue)

배열의 길이가 N이라면, 데이터의 수를 N-1개 까지만 저장하도록 한다
> 큐의 Empty와 Full 비교에 용이

-  큐가 비어있다면 F와 R이 가리키는 위치가 같다

-  enqueue 연산 시 R이 먼저 한칸 이동하고, 그 자리에 데이터 저장
<<<<<<< HEAD

-  dequeue 연산 시 F이 먼저 한칸 이동하고, F가 가리키는 위치의 저장 데이터를 반환 및 소멸

-  큐가 꽉 찼다면 R이 가리키는 위치의 앞을 F이 가리킨다
=======
<img width="450" alt="스크린샷 2021-12-20 오후 8 25 34" src="https://user-images.githubusercontent.com/87407504/146760172-5efb0966-225f-4f97-b0b2-ff363921b43b.png">

-  큐가 꽉 찼다면 R이 가리키는 위치의 앞을 F이 가리킨다
<img width="450" alt="스크린샷 2021-12-20 오후 8 25 56" src="https://user-images.githubusercontent.com/87407504/146760222-4f0f3dee-a6b0-420b-9f6c-71d7b2fef106.png">

-  dequeue 연산 시 F이 먼저 한칸 이동하고, F가 가리키는 위치의 저장 데이터를 반환 및 소멸

>>>>>>> 1c1dc180896a6f1728ff4d597a2dcf2e131a64ca

### 원형 큐 구현의 구현
[CircularQueue.h](https://github.com/Ejaeda/42_study/blob/master/DataStructure/Ch07.Queue/File/CircularQueue/CircularQueue.h)<br>
[CircularQueue.c](https://github.com/Ejaeda/42_study/blob/master/DataStructure/Ch07.Queue/File/CircularQueue/CircularQueue.c)<br>
[CircularQueueMain.c](https://github.com/Ejaeda/42_study/blob/master/DataStructure/Ch07.Queue/File/CircularQueue/CircularQueueMain.c)<br>

## 큐의 연결 리스트 기반 구현

스택은 push와 pop이 이루어지는 위치가 같은 반면, 큐는 en와 de가 이뤄지는 위치가 다르다

### 연결리스트 기반 큐의 헤더파일
[ListBaseQueue.h](https://github.com/Ejaeda/42_study/blob/master/DataStructure/Ch07.Queue/File/ListBaseQueue/ListBaseQueue.h)<br>
> Stack의 헤더파일에서 Queue의 특징인 F, R만 수정해주면 완성

### 연결 리스트 기반 큐의 구현

#### QueueInit
처음 큐를 생성하면 F(front)와 R(rear)이 모두 NULL을 가리키게 한다
```.c
void QueueInit(Queue * pq)
{
	pq->front = NULL;
	pq->rear = NULL;
}
```

#### QisEmpty
Empty 확인 유무는 F를 기반한 dequeue 연산에 필요하므로 F만 확인하면 된다 즉,

-  F에 NULL이 저장되어 있다면, 연결 리스트 기반의 큐는 비어있다
```.c
int QIsEmpty(Queue * pq)
{
	if(pq->front == NULL)
		return TRUE;
	else
		return FALSE;
}
```

#### Enqueue
F와 R 모두 기반되기 때문에 노드의 추가 과정이 둘로 나뉜다

-  첫번째 노드 추가 시 F, R 둘 다 새 노드를 가리키게 한다

-  두번째 이후 노드부터 R만 움직인다
> 비어있는지(QisEmpty) 확인하면 두 케이스를 식별할 수 있다
```.c
void Enqueue(Queue * pq, Data data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->data = data;

	if(QIsEmpty(pq))
	{
		pq->front = newNode;
		pq->rear = newNode;
	}
	else
	{
		pq->rear->next = newNode;
		pq->rear = newNode;
	}
}
```

#### Dequeue 
F에만 기반한다

-  F가 가리키는 노드의 값을 저장한다 

-  F는 다음 노드를 가리키고 저장 데이터 반환 후 노드 소멸
```.c
Data Dequeue(Queue * pq)
{
	Node * delNode;
	Data retData;

	if(QIsEmpty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	delNode = pq->front;
	retData = delNode->data;
	pq->front = pq->front->next;

	free(delNode);
	return retData;
}
```
> R은 꼬리를 가리키고 있는데 F이 노드를 모두 소멸 시킨 뒤 NULL을 가리키게 되었다면?<br>
> R은 쓰레기 값을 가리키고 있겠지만 문제가 안된다<br>

#### 파일정리
[ListBaseQueue.h](https://github.com/Ejaeda/42_study/blob/master/DataStructure/Ch07.Queue/File/ListBaseQueue/ListBaseQueue.h)<br>
[ListBaseQueue.c](https://github.com/Ejaeda/42_study/blob/master/DataStructure/Ch07.Queue/File/ListBaseQueue/ListBaseQueue.c)<br>
[ListBaseQueueMain.c](https://github.com/Ejaeda/42_study/blob/master/DataStructure/Ch07.Queue/File/ListBaseQueue/ListBaseQueueMain.c)<br>

## 큐의 활용

일상에서 큐 활용 예시 시뮬레이션 : 햄버거 가게 대기실 규모 정하기
> 실용적인 느낌을 알고가기

조건
```.c
1.  가장 손님이 많은 점심시간 1시간 기준 15초에 1명씩 주문
2.  한 명의 고객은 하나의 버거만 주문
3.  고객들은 무작위로 메뉴 선택
    -  치즈버거 12초        
    -  불고기버거 15초     
    -  더블버거 24초
4.  햄버거를 만드는 사람 수 1명
5.  주문한 메뉴를 받을 다음 고객은 대기실에서 나와 대기
```
정리
```.c
*
큐의 길이를 변경 == 대기실의 크기를 변경
       #define QUE_LEN 100
을 통해 설정

*
조건1   for(sec = 0; sec < 3600; sec++){
          if(sec % 15 == 0){
을 통해 해결

*
조건3   C언어의 srand 함수를 사용

*
실제 큐에 저장되는 것은 버거를 만드는데 소요되는 시간정보
버거의 종류에 맞는 상수가 En 매개 변수로 전달

이때 En이 발동되었을 때 대기실이 꽉찼다면 Error 출력

*
조건5   if(makeProc==0 && !QIsEmpty(&que))
	      makeProc = Dequeue(&que);
를 통해 설정 // 대기실에 나와 대기처리

       makeProc--;
을 통해 해당 값이 0이 되면 버거 완성을 의미, 그 다음 손님이 대기실에서 나와야 한다

*
무사히 for문을 빠져 나왔다면 대기실 자리 충분을 의미
시뮬레이션은 큐의 크기를 변경해가며 여러번 해야한다
```

구현<br>
[HamburgerSim](https://github.com/Ejaeda/42_study/tree/master/DataStructure/Ch07.Queue/File/HamburgerSim)<br>

## 덱(Deque)의 이해와 구현

### 덱의 이해와 ADT 정의
덱은 앞으로도 뒤로도 넣을 수 있고, 앞으로도 뒤로도 뺄 수 있는 자료구조
-  덱은 양방향으로 넣고 뺄 수 있다<br>
  (Stack과 Queue이 특성을 모두 갖는 자료구조)

-  핵심 함수 
    -  앞으로넣기 
    -  뒤로넣기 
    -  앞에서빼기 
    -  뒤에서빼기

```.c
void DequeInit(Deque * pdeq); 
void DQIsEmpty(Deque * pdeq); 
void DQAddFirst(Deque * pdeq, Data data); 
void DQAddLast(Deque * pdeq, Data data); 
Data DQRemoveFirst(Deque * pdeq); 
Data DQRemoveLast(Deque * pdeq); 
Data DQGetFirst(Deque * pdeq); 
Data DQGetLast(Deque * pdeq);
```

### 덱의 구현
양방향 연결 리스트를 기반으로 구현
> 꼬리에 위치한 노드를 삭제하는 함수 `DQRemoveLast`에서 꼬리 노드의 삭제를 위해

[Deque.c](https://github.com/Ejaeda/42_study/blob/master/DataStructure/Ch07.Queue/File/Deque/Deque.c)<br>
[Deque.h](https://github.com/Ejaeda/42_study/blob/master/DataStructure/Ch07.Queue/File/Deque/Deque.h)<br>
<<<<<<< HEAD
[DequeMain.c](https://github.com/Ejaeda/42_study/blob/master/DataStructure/Ch07.Queue/File/Deque/DequeMain.c)<br>
=======
[DequeMain.c](https://github.com/Ejaeda/42_study/blob/master/DataStructure/Ch07.Queue/File/Deque/DequeMain.c)<br>
>>>>>>> 1c1dc180896a6f1728ff4d597a2dcf2e131a64ca
