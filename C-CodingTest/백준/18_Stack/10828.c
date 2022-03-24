#include <stdio.h>
#include <string.h>

typedef struct _stack{
	int arr[10000];
	int top;
} Stack;


void StackInit(Stack * pstack){
	pstack->top = -1;
}

int IsEmpty(Stack * pstack){
	if(pstack->top == -1)
		return 1;
	else
		return 0;
}

void Push(Stack * pstack, int x){
	pstack->top += 1;
	pstack->arr[pstack->top] = x;
}

int Pop(Stack * pstack){
	int rIdx;

	if(IsEmpty(pstack))
		return -1;

	rIdx = pstack->top;
	pstack->top -= 1;

	return pstack->arr[rIdx];
}

int size(Stack * pstack){
	if(pstack->top == -1)
		return -1;
	else
		return pstack->top;
}

int top(Stack * pstack){
    if(pstack->top == -1)
		return -1;
    else
		return pstack->arr[pstack->top];
}

int	main(){
	Stack stack;
	StackInit(&stack);

	int N, num, pnum;
	char str[6] = {0};
	scanf("%d", &N);

	while(N--){
		scanf("%s", str);

		if(!strcmp(str, "push")){	
			
			scanf("%d", &pnum); 
			Push(&stack, pnum);
		}
		else if(!strcmp(str, "pop")){
			printf("%d\n", Pop(&stack));
		}
		else if(!strcmp(str, "size")){
			printf("%d\n", size(&stack)+1);
		}
		else if(!strcmp(str, "empty")){
			printf("%d\n", IsEmpty(&stack));
		}
		else if(!strcmp(str, "top")){
			printf("%d\n", top(&stack));
		}
	}
	return 0;
}
