#include <stdio.h>
#define MAX 100
int size = -1;
char stack[MAX];

void push(char c){
	stack[++size] = c;
}

int	main(){
	int idx = 0;
	char str[100];
	while(scanf("%c", &str[idx-1]) != '.'){
		if(idx == 0)	continue;
		if(str[idx] == '(' || str[idx] == '[')
			push(str[idx]);
		else if(str[idx] == ')' || stack[size] == '(')
			size--;
		else if(str[idx] == ']' || stack[size] == ']')
			size--;
		else {
			printf("no\n");
			return 0;
		}
		idx++;
	}
	if(size  == -1)
		printf("yes\n");
	else
		printf("no\n");
	return 0;
}
