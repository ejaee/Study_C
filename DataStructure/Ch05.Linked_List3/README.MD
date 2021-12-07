### [목차]
-  [05-1. 원형 연결 리스트](#05-1-원형-연결-리스트)<br>
-  [05-2. 양방향 연결 리스트](#05-2-양방향-연결-리스트)<br>

# 05-1. 원형 연결 리스트

### [학습흐름]
-  [05-1-1. 원형 연결 리스트의 이해](원형-연결-리스트의-이해)<br>
-  [05-1-2. 변형된 원형 연결 리스트](변형된-원형-연결-리스트)<br>
-  [05-1-3. 변형된 원형 연결 리스트의 헤더파일](변형된-원형-연결-리스트의-헤더파일)<br>
-  [05-1-4. 변형된 원형 연결 리스트 초기화와 삽입](변형된-원형-연결-리스트-초기화와-삽입)<br>
-  [05-1-4. 변형된 원형 연결 리스트의 삽입](변형된-원형-연결-리스트의-삽입)<br>

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
