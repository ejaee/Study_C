# 트리(Tree)

## 트리의 접근

-  트리(Tree)는 계층적 관계를 `표현`하는 자료구조
>  데이터 저장, 삭제, 검색을 용이하도록 만든 구조가 아닌, 무엇인가 표현 하기위한 구조

## 트리 관련 용어

<img width="450" alt="스크린샷 2022-02-25 오후 6 59 42" src="https://user-images.githubusercontent.com/87407504/155695296-f63a07c4-bdae-4246-917b-e740d74de593.png"><br>

노드 (node)
-  트리의 구성요소에 해당 A, B, C, D, E, F ...

간선 (edge)
-  노드와 노드를 연결하는 연결선

루트 노드 (root node)
-  트리 구조에서 최상위에 존재하는 A와 같은 노드

단말 노드 (terminal node)
-  아래로 또 다른 노드가 연결되어 있지 않은 노드 C, E, H, I, J, K, L

내부 노드 (internal node)
-  단말 노드를 제외한 모든 노드 A, B, D, F, G

노드간 부모, 자식, 형제의 관계가 성립
>  노드 A는 노드 B, C, D의 부모 노드

>  노드 B, C, D는 노드 A의 자식 노드

>  노드 B, C, D는 부모 노드가 같으므로, 서로 형제 노드

>  노드 A와 B는 노드 E의 조상 노드

>  노드 B, C, D, E, F는 모두 노드 A의 후손 노드

레벨 (level)
-  트리의 각 층별로 매긴 숫자, 루트 노드부터 0 레벨로 시작

높이 (height)
-  트리의 최고 레벨

서브 트리(Sub Tree)
-  큰 트리에 속하는 작은 트리

<img width="450" alt="스크린샷 2022-02-25 오후 7 03 49" src="https://user-images.githubusercontent.com/87407504/155695845-2988ff75-e3a5-4350-9c4c-534766d9e1fd.png"><br>

이진 트리(Binary Tree)

<img width="450" alt="스크린샷 2022-02-25 오후 7 04 06" src="https://user-images.githubusercontent.com/87407504/155695883-5eb625f1-7562-48f3-b006-f2232e38c8d7.png"><br>

이진 트리의 특징
1.  루트 노드를 중심으로 두 개의 서브 트리로 나누어진다

2.  나뉘어진 두 서브 트리도 모두 이진 트리이어야 한다
  
3.  노드가 존재하지 않더라도 그것을 공집합(empty set) 노드로 존재하는 것으로 간주한다

포화 이진 트리(Full Binary Tree)

[포화 이진 트리(Full Binary Tree)]()<br>
<img width="450" alt="스크린샷 2022-02-25 오후 7 11 02" src="https://user-images.githubusercontent.com/87407504/155696937-61099dd3-dad4-45e7-beec-6deef298fb20.png"><br>

-  모든 레벨이 꽉 찬 이진 트리

[완전 이진 트리(Complete Binary Tree)]()<br>
<img width="450" alt="스크린샷 2022-02-25 오후 7 11 27" src="https://user-images.githubusercontent.com/87407504/155697001-d9bfe940-4565-4337-865a-3ae908f66961.png">
-  레벨이 꽉 찬 상태는 아니지만, 노드가 위에서 아래로, 왼쪽에서 오른쪽의 순서대로 채워진 상태


## 이진 트리의 구현 by 연결 리스트
>  이진 트리를 빈번하게 탐색하는 경우 배열 기반으로 구현한다

### 헤더파일에 정의된 구조체의 이해
[BinaryTree.h]()<br>
<img width="300" alt="스크린샷 2022-02-25 오후 7 24 30" src="https://user-images.githubusercontent.com/87407504/155698884-a44534b1-7816-4e72-83bf-3f12fbd4c558.png">()<br>
```.c
typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode * left;
	struct _bTreeNode * right;
} BTreeNode;
```
이진 트리를 표현한 구조체를 따로 정의하지 않는다

-  노드가 하나 있으면 공집합 노드 두개가 자식으로 딸려있다고 생각하면 된다
-  즉 노드 자체가 이진 트리이다
>  `BTreeNode * pnode` == `BTreeNode * ptree`

## 헤더파일 함수 기능(ADT)

1. 노드의 생성, 그 주소값 반환

```.c
BTreeNode * MakeBTreeNode(void)
```

2. 노드에 저장된 데이터를 반환

```.c
BTData GetData(BTreeNode * bt)
```

3. 노드에 데이터를 저장, data값 저장

```.c
void SetData(BTreeNode * bt, BTData data)
```

4. 서브 트리를 가리키기 기능
```.c
BTreeNode * GetLeftSubTree(BTreeNode * bt)
// 왼쪽 서브트리의 주소값을 반환

BTreeNode * GetRightSubTree(BTreeNode * bt)
// 오른쪽 서브트리의 주소값을 반환
```

5. 서브 트리의 연결 기능
```.c
void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub)
// 왼쪽 연결

void MakeRightSubTree(BTreeNode * main, BTreeNode * sub)
// 오른쪽 연결
```
>  `sub`로 전달 된 노드를 `main`으로 전달된 노드의 서브 트리로 연결

## 이진 트리 구현
[BinaryTree.c]()<br>

- MakeLeft(Right)SubTree 함수 특징
> 왼(오른)쪽 서브 트리가 존재한다면 `해당 트리 삭제`하고 `새로운 서브 트리를 연결`한다<br>

- 문제점 : 삭제할 서브 트리가 하나의 노드로 이루어져있지 않을 경우 메모리 누수 발생
> 이럴 경우 모든 노드를 다 free 해주어야 하는데, 이때 `순회`의 방법을 사용한다


[BinaryTreeMain.c]()<br>
MakeLeft(Right)SubTree 함수 특징
- 왼(오른)쪽 서브 트리가 존재한다면 `해당 트리 삭제`하고 `새로운 서브 트리를 연결`한다

문제점 : 삭제할 서브 트리가 하나의 노드로 이루어져있지 않을 경우 메모리 누수 발생

- 모든 노드를 다 free 해주어야 하므로, 이때 `순회`의 방법을 사용한다

## 이진 트리의 순회(Traversal)

세가지 방법 by 루트노드 방문 순서에 따라
1. 전위 순회

<img width="450" alt="스크린샷 2022-02-25 오후 7 56 08" src="https://user-images.githubusercontent.com/87407504/155703471-e8d1f883-dbe2-4c71-9546-d814849cc0be.png">

> 루트 -> 왼쪽 -> 오른쪽 순

```.c
void	PreorderTraverse(BTreeNode * bt)
{
	if(bt == NULL)			// bt가 NULL이면 재귀 탈출
		return;

	printf("%d \n", bt -> data);			// 1. 루트 노드의 방문
	InorderTraverse(bt -> left);			// 2. 왼쪽 서브 트리의 순회
	InorderTraverse(bt -> right);			// 3. 오른쪽 서브 트리의 순회
}
```

2. 중위 순회

<img width="450" alt="스크린샷 2022-02-25 오후 7 58 02" src="https://user-images.githubusercontent.com/87407504/155703757-ee741f80-597b-4868-b296-5e72cfc9ccfc.png">

> 왼쪽 -> 루트 -> 오른쪽 순

```.c
void	InorderTraverse(BTreeNode * bt)	// 중위 순회 함수
{
	if(bt == NULL)			// bt가 NULL이면 재귀 탈출
		return;

	InorderTraverse(bt -> left);			// 1. 왼쪽 서브 트리의 순회
	printf("%d \n", bt -> data);			// 2. 루트 노드의 방문
	InorderTraverse(bt -> right);			// 3. 오른쪽 서브 트리의 순회
}
```

3. 후위 순회

<img width="450" alt="스크린샷 2022-02-25 오후 7 58 59" src="https://user-images.githubusercontent.com/87407504/155703883-b9c22c12-2756-4976-b5c2-0aaff18ae48e.png">

> 왼쪽 -> 오른쪽 -> 루트 순

```.c
void	PostorderTraverse(BTreeNode * bt)
{
	if(bt == NULL)			// bt가 NULL이면 재귀 탈출
		return;

	InorderTraverse(bt -> left);			// 1. 왼쪽 서브 트리의 순회
	InorderTraverse(bt -> right);			// 2. 오른쪽 서브 트리의 순회
	printf("%d \n", bt -> data);			// 3. 루트 노드의 방문
}
```

> 순회 방법에 초점을 두기위해 노드에 저장된 데이터의 출력으로 노드 방문이 이루어진 것으로 가정하였음

재귀의 탈출조건이 없다?
- 공집합 노드를 만나게 되면 NULL로써 재귀함수 종료

노드의 방문 목적이 상황에 따라 달라진다
- 함수 포인터 사용하기

```.c
typedef	void VisitFuncPtr(BTData data);

void	InorderTraverse(BTreeNode *bt, VisitFuncPtr action)
{
	if (bt == NULL)
		return;

	InorderTraverse(bt->left, action);
	action(br->data);		//노드 방문
	InorderTraverse(bt->right, action);
}
> 함수의 주소 값을 매개변수 action을 통해서 전달받도록 변경<br>
> main 함수에서 노드 방문의 결과를 결정하는 함수를 정의하여 사용

헤더파일에 각각의 순회 함수들을 명시하고 사용할 수 있다
```.c
void	PreorderTraverse(BTreeNode * bt)
void	InorderTraverse(BTreeNode *bt, VisitFuncPtr action)
void	PostorderTraverse(BTreeNode * bt)
```
< 순회 + 함수포인터를 적용한 이진트리 ><br>
[BinaryTree.h]()<br>
[BinaryTree.c]()<br>
[BinaryTreeMain.c]()<br>

## 이진 트리 소멸

동적할당 이후에 소멸하는 함수가 필요하다

```.c
	void DeleteTree(BTreeNode * bt);
	...

int main()
{
	BTreeNode * bt1 = MakeBTreeNode();
	
	...

	DeleteTree(bt1);
}
```

함수 정의
```.c
void	DeleteTree(BTreeNode * bt)
{
	if (bt == NULL)
		return;

		DeleteTree(bt->left);
		DeleteTree(bt->right);

		free(bt);
}
```

## 수식 트리의 구현
수식트리
- 이진 트리를 이용하여 수식을 표현해 놓은 것

```.c
int	main()
{
	int result = 0;
	result = 7 + 4 * 2 - 1;
	
	...
	
```
컴파일러는 위와 같은 상황에서 어떻게 사칙연산에 의거하여 계산을 해내는가?
- 수식 트리를 활용

방식
- 루트 노드에 저장된 연산자의 연산을 하되, 두 개의 자식 노드에 저장된 두 피연산자를 대상으로 연산한다

수식트리 헤더파일<br>
[expression_tree.h]()
```c
#ifndef __EXPRESSION_TREE_H__
#define __EXPRESSION_TREE_H__

#include "BinaryTree2.h"

BTreeNode * MakeExpTree(char exp[]);	// 수식 트리 구성
int EvaluateExpTree(BTreeNode * bt);	// 수식 트리 계산

void ShowPrefixTypeExp(BTreeNode * bt); // 전위 표기법 기반 출력
void ShowInfixTypeExp(BTreeNode * bt);  // 중위 표기법 기반 출력
void ShowPostfixTypeExp(BTreeNode * bt);// 후위 표기법 기반 출력

#endif
```
BTreeNode * MakeExpTree(char exp[]);	// 수식 트리 구성
- 문자열 형태로 입력받음
- 이를 기반으로 수식 트리를 구성하고 루트 노드의 주소 값을 반환

## 후위 표기법의 수식을 기반으로 수식트리 구성하기

후위 표기법 특징
- 연산 순서대로 왼쪽에서 오른쪽으로 연산자가 나열
- 해당 연산자의 두 피연산자는 연산자 앞에 나열

수식 트리 구성
1. 후위 표기법의 수식에 앞쪽에 등장하는 피연산자와 연산자를 이용해서 트리의 하단을 만들기
2. 이를 바탕으로 점진적으로 수식 트리의 윗부분 구성해 나가기

세부 구성 과정
1. 피연산자라면 스택으로 옮긴다
문자열로 수식을 받으므로
```.c
 	SetData(pnode, exp[i] - '0');
```
2. 두번째 문자도 피연산자라면 스택으로 옮긴다
3. 연산자가 등장하면 스택에 쌓여있는 두개의 피연산자를 꺼내 자식노드로 연결한다
4. 이때 순서는 오른쪽 왼쪽 노드가 된다
5. 수식트리 전부를 스택으로 옮긴다(실제는 연산자 저장된 노드 주소 값을 보낸다)
6. 반복하면 이진트리 완성
