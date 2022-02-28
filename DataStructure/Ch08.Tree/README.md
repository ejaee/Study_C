# 트리(Tree)

## 트리의 접근

-  트리(Tree)는 계층적 관계를 표현하는 자료구조
>  데이터의 저장, 삭제를 용이하도록 만든 구조가 아닌, 무엇인가 표현 하기위한 구조

## 트리 관련 용어

노드 (node)
-  트리의 구성요소에 해당 A, B, C, D, E, F

간선 (edge)
-  노드와 노드를 연결하는 연결선

루트 노드 (root node)
-  트리 구조에서 최상위에 존재하는 A와 같은 노드

단말 노드 (terminal node)
-  아래로 또 다른 노드가 연결되어 있지 않은 노드 E, F, C, D

내부 노드 (internal node)
-  단말 노드를 제외한 모든 노드 A, B

노드간 부모, 자식, 형제의 관계가 성립
-  노드 A는 노드 B, C, D의 부모 노드

-  노드 B, C, D는 노드 A의 자식 노드

-  노드 B, C, D는 부모 노드가 같으므로, 서로가 서로에게 형제 노드

-  노드 A와 A는 노드 E의 조상 노드

-  노드 B, C, D, E, F는 모두 노드 A의 후손 노드

레벨 (level)
-  트리의 각 층별로 매긴 숫자, 루트 노드부터 0 레벨로 시작

높이 (height)
-  트리의 최고 레벨

서브 트리(Sub Tree)
-  큰 트리에 속하는 작은 트리

이진 트리(Binary Tree)

-  루트 노드를 중심으로 두 개의 서브 트리로 나누어진다

-  나뉘어진 두 서브 트리도 모두 이진 트리이어야 한다

-  그 서브트리의 모든 서브 트리도 이진 트리이어야 한다

-  노드가 존재하지 않더라도 그것을 공집합(empty set) 노드로 존재하는 것으로 간주한다

포화 이진 트리(Full Binary Tree)
-  모든 레벨이 꽉 찬 이진 트리

완전 이진 트리(Complete Binary Tree)
-  레벨이 꽉 찬 상태는 아니지만, 노드가 위에서 아래로, 왼쪽에서 오른쪽의 순서대로 채워진 상태

## 이진 트리의 구현 by 연결 리스트
>  이진 트리를 빈번하게 탐색하는 경우 배열 기반으로 구현한다

## 헤더파일에 정의된 구조체의 이해
[BinaryTree.h]()<br>
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
>  `sub`로 전달 된 트리 또는 노드를 `main`으로 전달된 노드의 서브 트리로 연결

## 이진 트리 구현
[BinaryTree.c]()<br>
[BinaryTreeMain.c]()<br>
MakeLeft(Right)SubTree 함수 특징
- 왼(오른)쪽 서브 트리가 존재한다면 `해당 트리 삭제`하고 `새로운 서브 트리를 연결`한다<br>
문제점 : 삭제할 서브 트리가 하나의 노드로 이루어져있지 않을 경우 메모리 누수 발생
- 모든 노드를 다 free 해주어야 하므로, 이때 `순회`의 방법을 사용한다



## 이진 트리의 순회(Traversal)

순회 방법 by 루트노드 방문 순서
-  전위 순회

-  중위 순회

-  후위 순회

중위 순회
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

전위 순회
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

후위 순회
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
> 순회 방법에 초점을 두기위해 노드에 저장된 데이터의 출력으로 노드 방문이 이루어진 것으로 가정

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