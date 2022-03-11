## :pencil: [4_11729.c]
### [하노이 탑 이동 순서](https://www.acmicpc.net/problem/11729)
<img width="991" alt="스크린샷 2021-11-20 오후 10 14 42" src="https://user-images.githubusercontent.com/87407504/142727692-f342849f-0516-4133-8c71-b9445b6e84d7.png"><br>
* 핵심
```
하노이타워
1단계 : 맨 아래를 제외한 원반 n-1개를 A에서 B로 이동
2단계 : 맨 아래 원반 1개를 A에서 C로 이동
3단계 : B에 있는 n-1개의 원반들을 B에서 C로 이동
```
> [자료구조 정리참조](https://github.com/Ejaeda/42_study/blob/master/자료구조/02_재귀.md)
* 문제접근
```
1. 하노이의 갯수를 출력한다
2. 원반의 이동 순서를 출력한다
3. 문제발생
재귀를 다 돌리고 몇번 돌렸는지 체크를 할랬는데 총 몇번 옮기는지 먼저 출력하고 이후 재귀를 돌려야한다
```
* 아이디어
```
3. math.h 헤드파일의 pow함수를 사용한다
pow(n, m) : n^m
하노이의 결과는 2^n -1 이므로 구현 가능
```
* 코드구현
```.c
1.
int   main(){
    int n, k;
    scanf("%d", &n);
	  k = pow(2,n) -1;
	  printf("%d\n", k);
2.
    hanoi(n, 1, 2, 3);
    return 0;
}
재귀함수 정의
void	hanoi(int n, int from, int by, int to){
	  int	idx, cnt = 0;
	  if(n == 1)
		    printf("%d %d\n", from, to);
	  else{
	      hanoi(n-1, from, to, by);
	      printf("%d %d\n", from, to);
	      hanoi(n-1, by, from, to);
    }
}

```
* 정리
```
하노이의 재귀 정도는 구현 흐름을 한번 정리할 것
```
