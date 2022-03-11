#include <stdio.h>
#include <string.h>

int stack[10000];
int stack_size = -1;

void	push(int nb){
	stack[++stack_size] = nb;
}

int		pop(){
	int idx = stack_size;
	if(stack_size == -1)
		return -1;
	stack_size--;
	return stack[idx];
}

int		size(){
	return stack_size+1;
}

int		empty(){
	if(stack_size == -1)
		return 1;
	return 0;
}

int		top(){
	if(stack_size == -1)
		return -1;
	return stack[stack_size];
}
	

int	main(){
	int	N, nb;
	char command[5] = {0};

	scanf("%d", &N);

	for(int idx = 0; idx < N; idx++){
		scanf("%s", command);

		if(!strcmp(command, "push")){
			scanf("%d", &nb);
			push(nb);
		}
		else if(!strcmp(command, "pop"))
			printf("%d\n", pop());
		else if(!strcmp(command, "size"))
			printf("%d\n", stack_size+1);
		else if(!strcmp(command, "empty"))
			printf("%d\n", empty());
		else if(!strcmp(command, "top"))
			printf("%d\n", top());
	}
	return 0;
}
