# [스택](https://www.acmicpc.net/problem/10828) 

### :point_right: [10828](https://github.com/Ejaeda/Coding_Test/blob/master/백준/18_stack/10828.c)

- 핵심
```.c
1. 직접 스택에서 쓰이는 함수들을 구현한다
2. 요구하는 함수는 push, pop, size, empty, top가 있다
3. 추가적으로 필요한 함수는 초기화 함수가 있다
```

- 문제접근
```.c
스택 구현하기 연습
```

- 코드 구현
```.c
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

int main(){
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
```

-  새로 안 사실
```.c
1.
입력을 push 1 이라고 받을 때
scanf("%d", char);
scanf("%d", int);
를 써주면 \t이 자연스럽게 첫번째 입력을 끝내고 두번째 정수를 int에 담을 수 있다

2.
strcmp 함수는 string.h 헤더파일에 있는 함수
strcmp(str1, str2) 두 문자열을 비교하는데 해당 문제에서는 문자열과 직접 쓴 문자열을 비교했다
정확하게 일치하면 0을 리턴
str1이 str2보다 크면 양수 작으면 음수값을 리턴

3.
if안에 0이면 안돌아가니까 if(!func)을 만들어주면 궅이 func == 0 할 필요 없다
```

### 개선

굳이 구조체를 사용하지 않아도 된다
```.c
#include <stdio.h>
#include <string.h>

int stack[10000];
int stack_size=0;

void push(int push_data){
    stack[stack_size] = push_data;
    stack_size += 1;
}

int empty(){
    if(stack_size == 0){
        return 1;
    }
    return 0;
}

int pop(){
    if(empty()){
        return -1;
    }
    stack_size -= 1;
    return stack[stack_size];
}

int top(){
    if(empty()){
        return -1;
    }
    return stack[stack_size-1];
}

int main(){

    int N = 0, push_data = 0;
    char command[5] = {0,};

    scanf("%d",&N);

    for(int i=0;i<N;i++){

        scanf("%s",command);

        if(!strcmp(command,"push")){
            scanf("%d",&push_data);
            push(push_data);
        }
        else if(!strcmp(command,"pop")){
            printf("%d\n",pop());
        }
        else if(!strcmp(command,"empty")){
            printf("%d\n",empty());
        }
        else if(!strcmp(command,"size")){
            printf("%d\n",stack_size);
        }
        else if(!strcmp(command,"top")){
            printf("%d\n",top());
        }

    }

    return 0;
}
```
> command라는 변수 이름이 맘에든다<br>
> 속도는 구조체를 명시하는 전자가 더 빠르다

-----

# [스택 수](https://www.acmicpc.net/problem/1874) 

### :point_right: [1874](https://github.com/Ejaeda/Coding_Test/blob/master/백준/18_stack/1874_2.c)
- 핵심
```.c
1. 입력받은 수열을 스택을 통해 구현할 수 있는지를 확인하다
2. 스택에 push를 할때는 반드시 오름차순으로 가능하다
```

- 문제접근
```.c
0. 필요한 변수는 입력값을 받을 arr배열, 스택을 담을 stack배열, 결과값을 받을 plma문자열
   배열과 문자열의 크기는 malloc을 통해 부여하는데 문자열은 배열의 크기 * 2가 된다
   숫자 하나당 push와 pop을 한번씩 하기 때문
1. push와 pop을 거치는 경우의 수
   arr[0]부터 숫자를 비교하고 stack에는 1부터 arr[0]까지 값을 저장
   저장 할때마다 plma에 '+'를 저장하기
2. stack에 저장하는 값이 arr[0]과 같아지면 pop을 해야함
   top-- 해주고 이와 동시에 plma에 '-'를 저장하기
   비교 arr의 인덱스를 하나 올려줘야한다
   stack에 저장의 용도로 사용하는 num은 절대 초기화 해서는 안됨
   초기화하면 다시 1부터 오름차순으로 저장을 하기 때문
3. impos
   stack의 값이 arr의 값보다 클 경우에는 pop해주고 그 아레 수를 pop 해준 후
   처음 pop해준 값을 다시 push해야하는데 이는 문제에 위배되므로
   불가능하므로 NO 출력
4. 반복문의 종료 조건 = plma 인덱스의 값이 2*N인 경우
```

- 코드 구현
```.c
#include <stdio.h>
#include <stdlib.h>
int main(){
    int N;
    scanf("%d", &N);
0.
    int *arr = malloc(sizeof(int*)*N);
    int *stack = malloc(sizeof(int*)*2*N);
    char *plma = malloc(sizeof(int*)*N);

    for(int idx = 0; idx < N; idx++)
        scanf("%d", &arr[idx]);

    int num = 1, top = -1, rst = 0, idx = 0;

    while(1){
1.      if(top == -1 || stack[top] < arr[idx]){
            stack[++top] = num++;
            plma[rst++] = '+';
        }
2.      else if(stack[top] == arr[idx]){
            stack[top--] = 0;
            plma[rst++] = '-';
            idx++;
        }
3.      else{
            printf("NO");
            return 0;
        }
4.      if(rst  == 2*N) break;
    }
    for(int idx = 0; idx < rst; idx++)
        printf("%c\n", plma[idx]);
    return 0;
}
```

-  새로 안 사실
```.c
1.
배열에 값을 추가하고 배열 인덱스를 올려줄때 따로따로 
arr[idx] = 1;
idx++;
하지말고
arr[idx++]

2.
배열을 시작하기에 앞서 꾸준히 인덱스를 올려야 하는 경우 즉 idx++를 하는 경우
초기 값을 idx = -1로 부여하면 시작과 동시에 0으로 시작할 수 있음
당연히 arr[++idx]로 줄일 수 있다

3.
malloc에 자유로워지자!
```


