#include <stdio.h>
extern char * arr;
void	printData(char *arr);
int	main(){
	arr = "Test file's glabal variable!!";
	printData(arr);
	return 0;
}
