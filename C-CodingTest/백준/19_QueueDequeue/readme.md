# [요세푸스 문제0](https://www.acmicpc.net/problem/11866) 

### :point_right: [11866](https://github.com/Ejaeda/Data_Structure/blob/master/CodingTest/%EB%B0%B1%EC%A4%80/19_QueueDequeue/03_11866.c)

- 핵심
```.c
1. 요세푸스 문제
> 요세푸스 순열
```

- 문제접근
```.c
양방향 연결리스트를 활용
```

- 코드 구현
```.c
#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    struct _node *next;
    struct _node *prev;
    int         num;
}               node;

// 연결리스트의 앞 뒤를 유지하므로 전역변수로 선언
node *head = 0;
node *tail = 0;

node    *create_node(int data)  // 노드를 생성하는 함수
{
    node *new;

    new = malloc(sizeof(node));
    new->next = 0;
    new->prev = 0;
    new->num = data;
    return (new);
}

void    cycle_node(int data)    // 노드를 생성과 동시에 연결하는 함수
{
    node *new = create_node(data);
    node *temp;

    if (head == NULL)
    {
        head = new;
        tail = head;
    }

    else
    {
        temp = tail;
        temp->next = new;
        new->prev =temp;
        tail = new;
    }
}


void    print_node(node *haed, int N, int K)    // 요세푸스 순열 출력
{
    node *temp = head->prev;
    int c = 0;
    int move = 0;

    printf ("<");
    while (c < N)
    {
        move = K;
        while (move--)
            temp = temp->next;
        printf(c++ ? ", %d" : "%d", temp->num);
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    printf (">");
}


int main()
{
    int idx;
    int N, K;

    scanf("%d %d", &N, &K);

    idx = 0;
    while (++idx <= N)
        cycle_node(idx);

    head->prev = tail;
    tail->next = head;
    print_node(head, N, K);

    return (0);
}
```

-  새로 안 사실

💡 노드를 생성하고 연결지으려면

    -   create_node 함수 생성
    -   cycle_node 함수 생성
    -   main에서 노드를 만들고 연결하는것이 아니라
    -   연결하는 함수 내에서 생성하면서 바로 연결
> 양방향일 경우 연결 모두 지어주고 아래와 같이 연결
```.c
    head->prev = tail;
    tail->next = head;
```

💡 원하는 만큼 노드를 움직이고 싶을 때

    -   시작점을 head->prev 부터 시작!
    -   node = node->next 를 활용

```.c
    list *node = head->prev;
    int move;
    int idx;

    idx = 0;
    while (idx < num의 갯수)
    {
        move = 움직일 거리;
        while (move--)          // node를 원하는만큼 움직이는 skill
            node = node->next;
```


💡 삼항 연자를 활용한 printf 스킬

    -   만약  1, 2, 3, 4, 5 를 출력해야할 경우
    -   끝에는 ',' 를 출력하지 않는다
    -   이때 사용하면 좋은 스킬

```.c
    while (idx < num의 갯수)
    {
        move = 움직일 거리;
        while (move--)
            node = node->next;
        printf(idx++ ? ", %d" : "%d", node->data);
    }
```
>   처음에는 idx == 0 이니까 FALSE 이므로 "%d" !!

💡 노드를 지우는 스킬

```.c
    
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;

```

-----