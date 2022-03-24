#include <stdio.h>
#include <string.h>
void reverse(char arr[])
{
	char	temp;
	int		len = strlen(arr);
	for(int idx = 0; idx < len/2; idx++)
	{
		temp = arr[idx];
		arr[idx] = arr[len - idx - 1];
		arr[len - idx - 1] = temp;
	}
}		

int main(){
	char A[10001] = {0, }, B[10001] = {0, }, res[10002] = {0, };
	int idx, carry = 0;
	scanf("%s %s", A, B);
	int len = strlen(A) > strlen(B) ? strlen(A) : strlen(B);
	reverse(A);
	reverse(B);

	for(idx = 0; idx < len; idx++){
		int sum = A[idx] - '0' + B[idx] - '0' + carry;
		if(sum < 0) sum += '0';
		if(sum > 9)
			carry = 1;
		else
			carry = 0;
		res[idx] = sum % 10 + '0';
	}
	if(carry == 1)
		res[len] = '1';
	reverse(res);
	printf("%s", res);
	return 0;
}
