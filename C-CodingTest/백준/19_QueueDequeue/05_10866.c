#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _node {
	int data;
	struct _node * next;
	struct _node * prev;
}Node;

typedef struct _deque {
	Node * head;
	Node * tail;
}Deque;

int cnt = 0;

void DequeInit(Deque* pdeq) {
	pdeq->head = NULL;
	pdeq->tail = NULL;
}
void pushF(Deque * pdeq, int data) {
	Node * newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = pdeq->head;

	if (pdeq->head == NULL) 
		pdeq->tail = newNode;
	
	else 
		pdeq->head->prev = newNode;
	
	pdeq->head = newNode;
	cnt++;
	newNode->prev = NULL;

}
void pushB(Deque * pdeq, int data) {
	Node * newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;

	newNode->prev = pdeq->tail;
	if(pdeq->head == NULL)
		pdeq->head = newNode;
	else 
		pdeq->tail->next = newNode;

	newNode->next = NULL;
	cnt++;
	pdeq->tail = newNode;
}
int popF(Deque * pdeq) {
	if (empty(pdeq))
		return -1;

	Node * rnode = pdeq->head;
	int rdata = rnode->data;

	pdeq->head = pdeq->head->next;
	if (pdeq->head == NULL) 
		pdeq->tail = NULL;
	
	else 
		pdeq->head->prev = NULL;
	
	cnt--;
	free(rnode);
	return rdata;
}
int popB(Deque *pdeq) {
	if (empty(pdeq))
		return -1;
	Node * rnode = pdeq->tail;
	int rdata = rnode->data;

	pdeq->tail = pdeq->tail->prev;
	if (pdeq->tail == NULL) 
		pdeq->head = NULL;
	
	else 
		pdeq->tail->next = NULL;
	
	cnt--;
	free(rnode);
	return rdata;

}
int size() {
	return cnt;
}
int empty(Deque * pdeq) {
	if (pdeq->head == NULL)
		return 1;
	else
		return 0;
}
int front(Deque * pdeq) {
	if (empty(pdeq))
		return -1;
	else
		return pdeq->head->data;
}
int back(Deque * pdeq) {
	if (empty(pdeq))
		return -1;
	else
		return pdeq->tail->data;
}

int main(void) {
	int N, num;
	Deque dq;
	DequeInit(&dq);
	scanf("%d", &N);
	char str[13];
	for (int i = 1; i <= N; i++) {
		scanf("%s", str);
		if (!strcmp(str, "push_back")) {
			scanf("%d", &num);
			pushB(&dq, num);
		}
		else if (!strcmp(str, "push_front")) {
			scanf("%d", &num);
			pushF(&dq, num);
		}
		else if (!strcmp(str, "pop_front"))
			printf("%d\n", popF(&dq));
		else if (!strcmp(str, "pop_back"))
			printf("%d\n", popB(&dq));
		else if (!strcmp(str, "size"))
			printf("%d\n", size(&dq));
		else if (!strcmp(str, "empty"))
			printf("%d\n", empty(&dq));
		else if (!strcmp(str, "front"))
			printf("%d\n", front(&dq));
		else if(!strcmp(str, "back"))
			printf("%d\n", back(&dq));
	}
	return 0;
}
