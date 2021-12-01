# :grey_exclamation: 연결 리스트의 개념적인 이해
### 연결 리스트(Linked List)

-  배열은 메모리의 특성이 정적이어서 메모리의 길이를 변경할 수 없다

-  이를 유연하게 대처하기 위한것이 연결 리스트

-  malloc과 free를 통한 동적 메모리 구성

[LinkedRead.c]()<br>

#### 구조체 정의
```.c
typedef struck _node
{
  int data;                              //  데이터를 담을 공간
  struct _node * next                    //  연결의 도구
} Node;
```
> 멤버 next : Node형 구조체 변수의 주소값을 저장할 수 있는 포인터 변수
> 구조체 Node 변수를 노드라고 하는데 연결이 가능한 개체라는 사실에 중점을 둔 작명

필요할 때마다 바구니를 하나씩 마련해서 그곳에 데이터를 저장하고 이들을 배열처럼 서로 연결하는 방식
> 필요할 때마다 바구니의 역할을 하는 구조체 변수를 하나씩 동적 할당(malloc, free) 해서 이들을 연결

-----
들어가기 전 내가 만든 핵심

-  head와 tail은 가리키기만 하는 것이지 data를 받는 변수가 아니다
-  이에 반해 newNode는 가리키기도 하고 data를 저장해야하기도 하므로 두가지 기능이 필요하다
>  `newNode -> data` 를 통해 데이터를 저장 `newNode -> next`를 통해 가리킴 
-  즉 head와 tail가 A를 가리키고 싶을때 `head = A` 를 통해서 바로 연결 지으면 되고
-  newNode 는 `newNode -> next = A` 를 통해 연결 지으면 된다

여기서의 문제점 : 새 노드 추가할 때 [`tail -> next = newNode`](#노드를-추가하는-과정) 이 나오는데 이건뭐냐?
-  `tail -> next = newNode`는 tail이 newNode를 가리키려고 하는 것이 아니다
-  newNode가 새로 만들어진 시점에서 이전의 newNode를 tail을 통해서 접근하기 위해 tail을 쓴 것이다
-  tail은 위의 논리대로 else문을 끝나고 만나는 tail = newNode를 통해 이어진다
-----

### 연결 리스트에서의 데이터 삽입
```.c
int main(void)
{
  Node * head = NULL;                    // 리스트의 머리를 가리키는 포인터 변수
  Node * tail = NULL;                    // 리스트의 꼬리를 가리키는 포인터 변수
  Node * cur = NULL;                     // 저장된 데이터의 조회에 사용되는 포인터 변수
```
> 해당 포인터들로 인해 연결이 이루어짐
#### 노드가 생성되고 초기화되는 과정(반복문이 처음 실행되는 상황)
```.c
newNode = (Node*)malloc(sizeof(Node));   // 노드의 생성
newNode -> data = readData;              // 노드에 데이터 저장
newNode -> next = Null;                  // 노드의 next를 Null로 초기화
```

#### head가 Null에서 첫번째 노드를 추가하고 가리키는 과정
```.c
if(head == Null)                         // 첫 번째 노드라면
    head = newNode;                      // 첫 번째 노드를 head가 가리키게 함
//else
//    tail -> next = newNode;
tail = newNode;                          // tail 새로 만들어진 노드를 가리키게 함
```
> head와 tail은 첫 번째 노드를 같이 가리키고 있는 상황

#### 노드를 추가하는 과정
```.c
//if(head == Null)
//    head = newNode;
else
    tail -> next = newNode;              // tail이 추가된 노드를 가리키게 한다
tail = newNode;
```
> 반복문이 끝나면 head는 첫 번째 노드를, tail은 마지막 노드를 가리킨다

### 연결 리스트에서의 데이터 조회
```.c
if(head == NULL)
   printf(" 저장된 자연수 없음 \n");

else{
   cur = head;                           // cur이 리스트의 첫 번째 노드를 가리킨다
   printf("%d ", cur -> data);           // 첫 번째 데이터 출력
   
   while(cur -> next != NULL)            // 연결된 노드가 존재한다면
   {
      cur = cur -> next;                 // cur이 다음 노드를 가리키게 한다
      printf("%d ", cur -> data);        // cur이 가리키는 노드를 출력한다
   }
}
```
> `cur = cur -> next;`를 통해 cur이 모든 노드를 가리키며 이동 가능
> `cur`은 리스트 안을 돌아다닐 때 사용

### 연결 리스트에서의 데이터 삭제
```.c
if(head == NULL)
    return 0;                            // 삭제할 노드가 존재하지 않음
else{
    node * delNode = head;
    node * delNextNode = head -> next;
```
> 바로 삭제를 하면 다음 노드를 가리키지 못하니까 delNextNode에 다음 연결지를 저장
```.c
    printf("%d을(를) 삭제\n", head -> data);
    free(delNode);                       // 첫 번째 노드 삭제
    
   while(delNextNode != Null)            // 두 번째 이후 노드 삭제
   {
      delNode = delNextNode;
      delNextNode = delNextNode -> Next;
```
> 한 칸씩 오른쪽으로 이동
```.c
      
      printf("%d을 삭제                    // delNode -> data);
      free(delNode);
    }
}
```

#### 여기까지 학습정리

-  연결 리스트의 ADT를 정의하지 않았다
-  필요할 때 가져다 쓸수 있도록 삽입, 삭제, 조회의 기능이 별도의 함수로 구분되어야 한다
-----
# :grey_exclamation: 단순 연결 리스트의 ADT와 구현

### 연결 리스트의 ADT

이전의 배열 리스트에서 정렬 기능이 추가
-  Void SetSortRule(List * Plist, int (* comp)(LData d1, LData d2));
> 리스트에 정렬릐 기준이 되는 함수를 등록

#### ❔새 노드를 추가할 때 리스트의 head와 tail 중 어디에 저장을 할까
head
-  장점 : 포인터 변수 tail이 불필요
-  단점 : 저장된 순서를 유지하지 않음

tail
-  장점 : 저장된 순서를 유지
-  단점 : 포인터 변수 tail이 필요

> 통상 head에 추가하는 방법을 선호
> 자료구조는 저장된 순서를 유지해야 하는 자료구조가 아니다

### 더미 노드(Dummy Node) 기반의 단순 연결 리스트

> 앞서 보인 LinkedRead.c의 head와 tail이 포인터 변수인 연결 리스트는 아래와 같은 단점이 있다
> 노드를 추가, 삭제, 조회하는 방법에 있어서 첫 번째 노드와 두 번째 이후의 노드에 차이가 있음

#### 더미 노드가 추가된 형태의 련결 리스트는 tail이 없다

### 정렬 기능이 추가된 연결 리스트의 구조체와 헤더파일의 정의
[DLinkedList.h]()
#### 구조체 정의
```.c
typedef struck _node                     // typedef int LData
{
  LData data;                            //  데이터를 담을 공간
  struct _node * next                    //  연결의 도구
} Node;
```

#### 연결 리스트를 의미하는 구조체 정의
```.c
typedef struck _node                     // typedef int LData
{
  Node * head;                           // 더미 노드를 가리키는 멤버
  Node * cur;                            // 참조 및 삭제를 돕는 멤버
  Node * before;                         // 삭제를 돕는 멤버
  int numOfData;                         // 저자된 데이터의 수를 기록하기 위한 멤버
  int (*comp)(LData d1, LData d2);       // 정렬의 기준을 등록하기 위한 멤버
} LinkedList;
```
> Ch03의 [typedef struck _ node ArrayList]() 와 성격이 동일
> 위 유형의 포인터 변수들은 main 함수 내에서도 전역변수로도 선언해서는 안된다
> 프로그램을 구현하는데 다수의 배열이 필요하듯 리스트 자료구조도 다수 사용될 수 있다
> 전역변수로 선언할 경우 필요 개수만큼 선언을 해주어야 한다

-  헤더파일은 Ch03의 배열 기반 리스트의 헤더파일에서 SetSortRule 함수의 선언이 추가된 것 뿐

### 더미 노드 기반의 단순연결 리스트에서의 데이터 삽입
```.c
typedef struck _node                     // typedef int LData
{
  Node * head;                           // 더미 노드를 가리키는 멤버
  Node * cur;                            // 참조 및 삭제를 돕는 멤버
  Node * before;                         // 삭제를 돕는 멤버
  int numOfData;                         // 저자된 데이터의 수를 기록하기 위한 멤버
  int (*comp)(LData d1, LData d2);       // 정렬의 기준을 등록하기 위한 멤버
} LinkedList;
```
> 위 구조체의 변수가 선언되면 이를 대상으로 초기화를 진행해야함 

#### 더미 노드가 생성되고 초기화되는 과정
```.c
void  ListInit(List * plist){
    plist -> head = (Node*)malloc(sizeof(Node));   // 더미 노드의 생성
    plist -> head -> next = NULL;
    plist -> comp = NULL;
    plist -> numOfData = 0;
```
> 초기화를 하면 head가 아무것도 들어있지 않은 더미노드를 가리키고 있다

#### 노드의 추가를 위해 호출되는 함수
```.c
void LInsert(List * plist, Ldata data){
    if(plist -> comp == NULL)                      // 정렬 기준이 마련되지 않았다면,
        FInsert(plist, data);                      // 머리에 노드를 추가!
    else                                           // 정렬기준이 마련되었다면
        SInsert(plist, data);                      // 정렬기준에 근거하여 노드를 추가!
}
```
> comp에 무엇이 저장되어 있느냐에 따라서 FInsert 또는 SInsert 함수를 통해서 진행
> FInsert와 SInsert는 헤더파일에 선언된 함수가 아니다

#### comp가 NULL일 때 호출되는 FInsert 함수
```.c
void  FInsert(List * plist, LData data){
    Node * newNode = (Node*)malloc(sizeof(Node));  // 새 노드 생성
    newNode -> data = data;                        // 새 노드에 데이터 저장
    
    newNode -> next = Plist -> head -> next        // 새 노드가 다른 노드를 가리키게 함
    plist -> head -> next = newNode;               // 더미 노드가 새 노드를 가리키게 함
    
    (plist -> numOfData)++;                        // 저장된 노드의 수를 하나 증가시킴
}
```
> 처음에 head는 NULL이 아닌 더미 노드를 가리키고 있다
> if else 구문이 필요없다
> 4와 6이 저장된 상태에서 FInsert(plist, 2);가 호출되었다고 가정하면
> head DMY 2 4 6 NULL 순으로 저장된다

SInsert 함수는 이후 다시 설명

### 더미 노드 기반의 단순연결 리스트에서의 데이터 조회
ADT 기준으로 `조회`하면 떠오르는 두 함수 LFirst와 LNext는 배열 리스트와 기능이 동일
> 더미 노드 기반의 단순 연결 리스트에서 첫번째 노드는 더미 노드 다음의 노드임을 재고
#### LFirst
```.c
int LFirst(List * plist, LData * pdata){
    if(plist -> head -> next == NULL)              // 더미 노드가 NULL을 가리킨다면,
        return FALSE;                              // 반환할 데이터 없음
    
    plist -> before = plist -> head;               // before은 더미 노드를 가리키게 함
    plist -> cur = plist -> head -> next;          // cur은 첫 번째 노드를 가리키게 함
    
    *pdata = plist -> cur -> data;                 // 첫 번째 노드의 데이터 전달
    return TRUE;                                   // 데이터 반환 성공
}
```
> before가 더미 노드를 가리키게 하는 이유는 삭제와 관련이 있음
> before은 cur보다 하나 앞선 노드를 가리킨 다는 사실을 기억하자
#### LNext
```.c
int LNext(List * plist, LData * pdata){
    if(plist -> head -> next == NULL)              // cur이 NULL을 가리킨다면,
        return FALSE;                              // 반환할 데이터 없음
    
    plist -> before = plist -> cur;                // cur이 가리키던 것을 before가 가리키게 함
    plist -> cur = plist -> cur -> next;           // cur은 그 다음 노드를 가리킴
    
    *pdata = plist -> cur -> data;                 // cur이 가리키는 노드의 데이터 전달
    return TRUE;                                   // 데이터 반환 성공
}
```
> cur이 가리키던 것을 before가 가리키게 하고 cur은 그 다음 노드를 가리키는 것이 핵심

### 더미 노드 기반의 단순연결 리스트에서의 데이터 삭제
> 바로 이전에 호출된 LFirst 혹은 LNext 함수가 반환한 데이터를 삭제한다
> cur이 가리키는 바구니의 데이터를 삭제하고 before의 도움을 받아 앞으로 한칸 이동한다
> LFirst 또는 LNext 함수에서 before는 cur바로 왼쪽의 노드를 가리키게 하므로 삭제 과정에서 둘이 가리키는게 같아져도 상관없다

```.c
LData LRemove(List * plist){
    Node * rpos = plist -> cur;                     // 소멸 대상의 주소 값을 rpos에 저장
    LData rdata = rpos -> data;                     // 소멸 대상의 데이터를 rdata에 저장
                                                    // cur와 rpos는 같은 곳을 가리키는 중    
    plist -> before -> next = plist -> cur -> next; // 소멸 대상을 리스트에서 제거
    plist -> cur = plist -> before;                 // cur이 가리키는 위치를 재조정
    
    free(rpos):                                     // 리스트에서 제거된 노드 소멸
    (plist -> numOfData)--;                         // 저장된 데이터의 수 하나 감소
    return rdata;                                   // 제거된 노드의 데이터 반환
}
```
 ### 하나로 묶기
[DLinkedList.h]()<br>
[DLinkedList.c]()<br>
[DLinkedListMain.c]()<br>
> 일반적으로main함수는 배열 기반 리스트와 동일하므로 소스코드 변경 없이 서로 대체가 가능

-----
# :grey_exclamation: 연결 리스트의 정렬 삽입의 구현
### 연결 리스트에서 정렬기준 설정
핵심

-  연결 리스트의 정렬기준이 되는 함수를 등록하는 SetSortRule 함수
-  SetSortRule 함수를 통해서 전달된 함수정보를 저장하기 위한 LinkedList의 멤버 comp
-  comp에 등록된 정렬기준을 근거로 데이터를 저장하는 SInsert 함수

> SetSortRule 함수가 호출되면서 정렬의 기준이 리스트의 멤버 comp에 등록되면, SInsert함수 내에서는 comp에 등록된 정렬의 기준을 근거로 데이터를 정렬하여 저장한다

#### SetSortRule Func
```.c
void  SetSortRule(List * plist, int (*comp)(LData d1, LData d2)){
    plist -> comp = comp;
}
```

#### SInsert
```.c
void  SInsert(List * plist, LData data){
    Node * newNode = (Node*)malloc(sizeof(Node));         // 새 노드 생성
    Node * pred = plist -> head;                          // pred는 더미 노드를 가리킴
    newNode -> data = data;                               // 새 노드에 데이터 저장
    
    /*새 노드가 들어갈 위치를 찾기 위한 반복문*/
    while(pred -> next != NULL && plist -> comp(data, pred -> next -> data) != 0){
        pred = pred -> next;                              // 다음 노드로 이동
    }
    
    newNode -> next = pred -> next;                       // 새 노드의 오른쪽을 연결
    pred -> next = newNode;                               // 새 노드의 왼쪽을 연결
    
    (plist -> numOfData)++;                               // 저장된 데이터의 수 하나 증가
}
```
